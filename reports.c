#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "reports.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void displayReportsMenu(void) {
    printf("\n=== MUNICIPAL REPORTS MODULE ===\n");
    printf("1. Employee Salary Summary Report\n");
    printf("2. Budget Expenditure & Overruns Report\n");
    printf("3. Supplier Register Report\n");
    printf("4. Asset Register Report\n");
    printf("=================================\n");
}

void generateEmployeeReport(void) {
    printf("\n--- EMPLOYEE SALARY REPORT ---\n");
    printf("Employee salary data is managed via the Employee module.\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n'); // clear input buffer
    getchar();
}
void generateBudgetReport(void) {
    printf("\n--- BUDGET EXPENDITURE & OVERRUNS REPORT ---\n");
    printf("Budget reporting relies on active departmental data entered in Budget Management.\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n'); // clear input buffer
    getchar();
}

void generateSupplierReport(void) {
    printf("\n--- SUPPLIER REGISTER REPORT ---\n");
    printf("Supplier register data is managed via the Supplier module.\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n'); // clear input buffer
    getchar();
}

void generateAssetReport(void) {
    printf("\n--- ASSET REGISTER REPORT ---\n");
    printf("Asset register data is managed via the Asset module.\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n'); // clear input buffer
    getchar();
}