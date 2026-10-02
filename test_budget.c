/*
 * test_budget.c
 *
 * Temporary test driver for the Budget Management module.
 * Simulates how the main menu will eventually call the module's functions.
 *
 * Compile & run:
 *   gcc -std=c99 -Wall -o test_budget budget.c test_budget.c
 *   ./test_budget
 */

#include <stdio.h>
#include "budget.h"

#define NUM_DEPARTMENTS 3  /* Number of departments to test with */

int main(void)
{
    Department departments[NUM_DEPARTMENTS];
    int i;

    printf("============================================\n");
    printf("  MUNICIPAL BUDGET MANAGEMENT SYSTEM TEST\n");
    printf("============================================\n\n");

    /* ── Step 1: Collect input for each department ───────────────── */
    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        printf("--- Department %d of %d ---\n", i + 1, NUM_DEPARTMENTS);
        input_department(&departments[i]);
        printf("\n");
    }

    /* ── Step 2: Calculate budget and assign status ──────────────── */
    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        calculate_budget(&departments[i]);
    }

    /* ── Step 3: Display the budget report for every department ──── */
    printf("\n********** FULL BUDGET REPORT **********\n");
    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        display_report(&departments[i]);
    }

    /* ── Step 4: Summary of departments exceeding their budget ──── */
    display_exceeded_summary(departments, NUM_DEPARTMENTS);

    return 0;
}
