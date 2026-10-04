/*
 * suppliers.c - Supplier Management module (MFMS, Project A)
 *
 * Stores suppliers in a fixed-size array of structs. The array is private
 * to this file; other modules use getSupplierCount() and getSupplier().
 * All input is read with fgets() and validated before it is stored.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

typedef int (*Validator)(const char *);

/* ---------- small string helpers ---------- */

static void trim(char *s)
{
    size_t start = 0;
    size_t len;

    while (s[start] != '\0' && isspace((unsigned char)s[start])) {
        start++;
    }
    if (start > 0) {
        memmove(s, s + start, strlen(s + start) + 1);
    }
    len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[--len] = '\0';
    }
}

static void toUpperStr(char *s)
{
    for (; *s != '\0'; s++) {
        *s = (char)toupper((unsigned char)*s);
    }
}

static void toLowerStr(char *s)
{
    for (; *s != '\0'; s++) {
        *s = (char)tolower((unsigned char)*s);
    }
}

/* ---------- input ---------- */

/* Reads one line. Returns 1 = ok, 0 = line too long (discarded), -1 = end of input. */
static int readLine(const char *prompt, char *buf, size_t size)
{
    size_t len;

    printf("%s", prompt);
    if (fgets(buf, (int)size, stdin) == NULL) {
        buf[0] = '\0';
        return -1;
    }
    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
        return 1;
    }
    if (feof(stdin)) {
        return 1;
    }
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            /* discard the rest of the long line */
        }
    }
    return 0;
}

/* ---------- validators ---------- */

static int validId(const char *s)
{
    for (; *s != '\0'; s++) {
        if (!isalnum((unsigned char)*s) && *s != '-' && *s != '_') {
            return 0;
        }
    }
    return 1;
}

static int validEmail(const char *s)
{
    const char *at = strchr(s, '@');
    const char *lastDot;
    const char *p;

    for (p = s; *p != '\0'; p++) {
        if (isspace((unsigned char)*p)) {
            return 0;
        }
    }
    if (at == NULL || at == s || strchr(at + 1, '@') != NULL) {
        return 0;
    }
    lastDot = strrchr(at + 1, '.');
    if (lastDot == NULL || lastDot == at + 1 || lastDot[1] == '\0') {
        return 0;
    }
    return 1;
}

static int validPhone(const char *s)
{
    int digits = 0;
    size_t i;

    for (i = 0; s[i] != '\0'; i++) {
        if (isdigit((unsigned char)s[i])) {
            digits++;
        } else if (s[i] == '+' && i == 0) {
            /* a leading + is allowed */
        } else if (s[i] != ' ' && s[i] != '-') {
            return 0;
        }
    }
    return digits >= 7 && digits <= 15;
}

/*
 * Asks until a non-empty, valid value fits in 'out'.
 * Returns 1 on success, 0 if the input ended.
 */
static int promptField(const char *prompt, char *out, size_t size,
                       Validator ok, const char *errmsg)
{
    char line[256];

    for (;;) {
        int r = readLine(prompt, line, sizeof line);

        if (r < 0) {
            return 0;
        }
        if (r == 0) {
            printf("  Input too long. Please try again.\n");
            continue;
        }
        trim(line);
        if (strlen(line) == 0) {
            printf("  This field cannot be empty.\n");
            continue;
        }
        if (ok != NULL && !ok(line)) {
            printf("  %s\n", errmsg);
            continue;
        }
        if (strlen(line) >= size) {
            printf("  Too long (maximum %d characters).\n", (int)size - 1);
            continue;
        }
        strcpy(out, line);
        return 1;
    }
}

/* ---------- lookup and printing ---------- */

static int findIndexById(const char *id)
{
    int i;

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

static void printHeader(void)
{
    printf("%-11s %-46s %-30s %-18s %-s\n",
           "Supplier ID", "Supplier Name", "Email", "Phone", "Town/Location");
}

static void printRow(const Supplier *s)
{
    printf("%-11s %-46s %-30s %-18s %-s\n",
           s->id, s->name, s->email, s->phone, s->town);
}

/* ---------- operations ---------- */

void addSupplier(void)
{
    Supplier s;

    memset(&s, 0, sizeof s);
    printf("\n--- Add Supplier ---\n");

    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list full (maximum %d suppliers).\n", MAX_SUPPLIERS);
        return;
    }

    if (!promptField("Supplier ID (e.g. SUP001): ", s.id, sizeof s.id, validId,
                     "ID may contain only letters, digits, '-' and '_' (no spaces).")) {
        return;
    }
    toUpperStr(s.id);
    if (findIndexById(s.id) >= 0) {
        printf("Supplier ID %s already exists. Supplier not added.\n", s.id);
        return;
    }
    if (!promptField("Supplier name: ", s.name, sizeof s.name, NULL, "")) {
        return;
    }
    if (!promptField("Email: ", s.email, sizeof s.email, validEmail,
                     "Invalid email. Example: name@company.com.na")) {
        return;
    }
    if (!promptField("Telephone (e.g. +264 61 200 1111): ", s.phone, sizeof s.phone, validPhone,
                     "Invalid phone. Use 7-15 digits; spaces, '-' and a leading '+' are allowed.")) {
        return;
    }
    if (!promptField("Town/Location: ", s.town, sizeof s.town, NULL, "")) {
        return;
    }

    suppliers[supplierCount] = s;
    supplierCount++;
    printf("Supplier %s added successfully.\n", s.id);
}

void displaySuppliers(void)
{
    int i;

    printf("\n--- Registered Suppliers ---\n");
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printHeader();
    for (i = 0; i < supplierCount; i++) {
        printRow(&suppliers[i]);
    }
    printf("Total suppliers: %d\n", supplierCount);
}

void searchSupplier(void)
{
    char choiceLine[32];
    char key[SUP_NAME_LEN];
    char keyLower[SUP_NAME_LEN];
    char fieldLower[SUP_NAME_LEN];
    char *end;
    long choice;
    int i;
    int found = 0;

    printf("\n--- Search Suppliers ---\n");
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("1. Search by Supplier ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Town/Location\n");
    if (readLine("Enter your choice: ", choiceLine, sizeof choiceLine) <= 0) {
        printf("Invalid choice.\n");
        return;
    }
    trim(choiceLine);
    choice = strtol(choiceLine, &end, 10);
    if (choiceLine[0] == '\0' || *end != '\0' || choice < 1 || choice > 3) {
        printf("Invalid choice. Enter 1, 2 or 3.\n");
        return;
    }

    if (!promptField("Search for: ", key, sizeof key, NULL, "")) {
        return;
    }
    strcpy(keyLower, key);
    toLowerStr(keyLower);
    toUpperStr(key);

    printf("\nSearch results:\n");
    for (i = 0; i < supplierCount; i++) {
        int match = 0;

        if (choice == 1) {
            match = (strcmp(suppliers[i].id, key) == 0);
        } else {
            strcpy(fieldLower, choice == 2 ? suppliers[i].name : suppliers[i].town);
            toLowerStr(fieldLower);
            match = (strstr(fieldLower, keyLower) != NULL);
        }
        if (match) {
            if (!found) {
                printHeader();
            }
            printRow(&suppliers[i]);
            found++;
        }
    }
    if (!found) {
        printf("No supplier found.\n");
    } else {
        printf("%d supplier(s) found.\n", found);
    }
}

void compareSuppliers(void)
{
    char idA[SUP_ID_LEN];
    char idB[SUP_ID_LEN];
    int a;
    int b;

    printf("\n--- Compare Suppliers ---\n");
    if (supplierCount < 2) {
        printf("At least two suppliers must be registered to compare.\n");
        return;
    }
    if (!promptField("First supplier ID: ", idA, sizeof idA, validId,
                     "ID may contain only letters, digits, '-' and '_'.")) {
        return;
    }
    if (!promptField("Second supplier ID: ", idB, sizeof idB, validId,
                     "ID may contain only letters, digits, '-' and '_'.")) {
        return;
    }
    toUpperStr(idA);
    toUpperStr(idB);

    a = findIndexById(idA);
    b = findIndexById(idB);
    if (a < 0) {
        printf("Supplier %s not found.\n", idA);
        return;
    }
    if (b < 0) {
        printf("Supplier %s not found.\n", idB);
        return;
    }
    if (a == b) {
        printf("Please choose two different suppliers.\n");
        return;
    }

    printf("\n%-14s %-48s %-48s\n", "Field", "Supplier A", "Supplier B");
    printf("%-14s %-48s %-48s\n", "Supplier ID", suppliers[a].id,    suppliers[b].id);
    printf("%-14s %-48s %-48s\n", "Supplier Name", suppliers[a].name, suppliers[b].name);
    printf("%-14s %-48s %-48s\n", "Email",       suppliers[a].email,  suppliers[b].email);
    printf("%-14s %-48s %-48s\n", "Phone",       suppliers[a].phone,  suppliers[b].phone);
    printf("%-14s %-48s %-48s\n", "Town/Location", suppliers[a].town, suppliers[b].town);
}

void supplierMenu(void)
{
    char line[32];
    char *end;
    long choice;

    for (;;) {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Back to Main Menu\n");

        if (readLine("Enter your choice: ", line, sizeof line) < 0) {
            return;   /* input ended */
        }
        trim(line);
        choice = strtol(line, &end, 10);
        if (line[0] == '\0' || *end != '\0') {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            continue;
        }

        switch (choice) {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: compareSuppliers(); break;
            case 5: return;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    }
}

/* ---------- access for other modules ---------- */

int getSupplierCount(void)
{
    return supplierCount;
}

Supplier getSupplier(int index)
{
    Supplier empty;

    if (index >= 0 && index < supplierCount) {
        return suppliers[index];
    }
    memset(&empty, 0, sizeof empty);
    return empty;
}
