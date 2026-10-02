/*
 * budget.c
 *
 * Municipal Financial Management System – Budget Management Module
 * Phase 2: Implementation (ANSI C99, GCC compatible)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "budget.h"

/* ── Helper: read a non-negative number with strict validation ────── */

/*
 * read_positive_double
 *
 * Reads a line from stdin and attempts to parse it as a number.
 * Rejects input that contains non-numeric characters (e.g. words),
 * negative values, or empty lines.  Re-prompts until valid.
 *
 * Returns the parsed non-negative double value.
 */
static double read_positive_double(const char *prompt)
{
    char   buffer[64];
    char  *endptr;
    double value;

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        /* Remove trailing newline */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* Reject empty input */
        if (buffer[0] == '\0') {
            printf("Error: Input cannot be empty. Please enter a valid number.\n");
            continue;
        }

        /* Attempt to convert to a number */
        value = strtod(buffer, &endptr);

        /* Check that the entire string was consumed (no trailing letters) */
        if (*endptr != '\0') {
            printf("Error: Invalid input. Please enter a valid number (no letters).\n");
            continue;
        }

        /* Check for negative values */
        if (value < 0) {
            printf("Error: Value cannot be negative. Please try again.\n");
            continue;
        }

        return value;
    }
}

/* ── Input Function ─────────────────────────────────────────────────── */

/*
 * input_department
 *
 * Prompts the user for:
 *   1. Department name
 *   2. Allocated budget  (must be >= 0, strictly numeric)
 *   3. Expenditure       (must be >= 0, strictly numeric)
 *
 * Non-numeric input and negative values are rejected with an error
 * message and the user is re-prompted until valid input is entered.
 */
void input_department(Department *dept)
{
    /* ── Department name ─────────────────────────────────────────── */
    printf("Enter Department Name: ");
    fgets(dept->name, MAX_NAME_LEN, stdin);

    /* Strip the trailing newline character left by fgets, if present */
    dept->name[strcspn(dept->name, "\n")] = '\0';

    /* ── Allocated budget with strict numeric validation ─────────── */
    dept->allocated_budget = read_positive_double("Enter Allocated Budget: ");

    /* ── Expenditure with strict numeric validation ──────────────── */
    dept->expenditure = read_positive_double("Enter Expenditure: ");
}

/* ── Calculation Function ───────────────────────────────────────────── */

/*
 * calculate_budget
 *
 * Computes:  remaining_budget = allocated_budget − expenditure
 *
 * Status assignment (via strcpy):
 *   remaining_budget >= 0  →  "WITHIN BUDGET"
 *   remaining_budget <  0  →  "EXCEEDED"
 */
void calculate_budget(Department *dept)
{
    dept->remaining_budget = dept->allocated_budget - dept->expenditure;

    if (dept->remaining_budget >= 0) {
        strcpy(dept->status, "WITHIN BUDGET");
    } else {
        strcpy(dept->status, "EXCEEDED");
    }
}

/* ── Display / Reporting Function ───────────────────────────────────── */

/*
 * display_report
 *
 * Outputs a formatted budget report for a single department.
 * Departments that have exceeded their budget are explicitly flagged.
 */
void display_report(const Department *dept)
{
    printf("\n");
    printf("====================================\n");
    printf("    DEPARTMENT BUDGET REPORT\n");
    printf("====================================\n");
    printf("Department      : %s\n",       dept->name);
    printf("Allocated Budget: N$%.2f\n",   dept->allocated_budget);
    printf("Expenditure     : N$%.2f\n",   dept->expenditure);
    printf("Remaining Budget: N$%.2f\n",   dept->remaining_budget);
    printf("Status          : %s\n",       dept->status);

    if (strcmp(dept->status, "EXCEEDED") == 0) {
        printf("*** WARNING: This department has EXCEEDED its budget! ***\n");
    }

    printf("====================================\n\n");
}

/* ── Summary of Exceeded Budgets ───────────────────────────────────── */

/*
 * display_exceeded_summary
 *
 * Iterates over all departments and prints a consolidated listing
 * of those whose expenditure has exceeded their allocated budget.
 */
void display_exceeded_summary(const Department depts[], int count)
{
    int i;
    int found = 0;

    printf("\n");
    printf("====================================\n");
    printf("  DEPARTMENTS EXCEEDING BUDGET\n");
    printf("====================================\n");

    for (i = 0; i < count; i++) {
        if (strcmp(depts[i].status, "EXCEEDED") == 0) {
            printf("- %s  (Over by N$%.2f)\n",
                   depts[i].name,
                   -(depts[i].remaining_budget));
            found = 1;
        }
    }

    if (!found) {
        printf("All departments are within budget.\n");
    }

    printf("====================================\n\n");
}
