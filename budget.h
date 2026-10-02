/*
 * budget.h
 *
 * Municipal Financial Management System – Budget Management Module
 * Phase 1: Header / Interface Definition (ANSI C99)
 */

#ifndef BUDGET_H
#define BUDGET_H

/* ── Standard library includes ──────────────────────────────────────── */
#include <stdio.h>
#include <string.h>

/* ── Constants ──────────────────────────────────────────────────────── */
#define MAX_NAME_LEN   50   /* Maximum length for department name   */
#define MAX_STATUS_LEN 20   /* Maximum length for status string     */
#define MAX_DEPTS      10   /* Maximum number of departments        */

/* ── Data structures ────────────────────────────────────────────────── */

/*
 * Department
 *
 * Represents a single municipal department's budget record.
 *
 *   name            – Department name (e.g. "Public Works")
 *   allocated_budget – Total budget allocated to the department
 *   expenditure      – Amount spent so far
 *   remaining_budget – allocated_budget − expenditure
 *   status           – Textual label derived from spending ratio
 *                      (e.g. "Within Budget", "Over Budget")
 */
typedef struct {
    char   name[MAX_NAME_LEN];
    double allocated_budget;
    double expenditure;
    double remaining_budget;
    char   status[MAX_STATUS_LEN];
} Department;

/* ── Function prototypes ────────────────────────────────────────────── */

/*
 * input_department
 *
 * Prompts the user to enter the department name, allocated budget,
 * and expenditure, then stores the values in the supplied struct.
 */
void input_department(Department *dept);

/*
 * calculate_budget
 *
 * Computes remaining_budget (allocated − expenditure) and assigns
 * a human-readable status string based on the result.
 */
void calculate_budget(Department *dept);

/*
 * display_report
 *
 * Prints a formatted budget report for the given department,
 * showing all fields including the computed status.
 */
void display_report(const Department *dept);

/*
 * display_exceeded_summary
 *
 * Scans an array of departments and prints a summary listing
 * only those that have exceeded their allocated budget.
 */
void display_exceeded_summary(const Department depts[], int count);

#endif /* BUDGET_H */
