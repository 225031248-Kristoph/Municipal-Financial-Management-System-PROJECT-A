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
    printf("\n======================================================\n");
    printf("            EMPLOYEE SALARY SUMMARY REPORT            \n");
    printf("======================================================\n");

    int count = getEmployeeCount();
    if (count == 0) {
        printf("No employee records found in system.\n");
    } else {
        double total = 0;
        double highest = -1;
        double lowest = -1;

        for (int i = 0; i < count; i++) {
            double sal = getEmployeeTotalSalary(i);
            total += sal;
            if (i == 0 || sal > highest) highest = sal;
            if (i == 0 || sal < lowest) lowest = sal;

            printf("ID: %-4d | Name: %-15s | Dept: %-12s | Total Salary: N$%.2f\n",
                   getEmployeeId(i),
                   getEmployeeName(i),
                   getEmployeeDepartment(i),
                   sal);
        }

        printf("------------------------------------------------------\n");
        printf("Total Employees : %d\n", count);
        printf("Total Payroll   : N$%.2f\n", total);
        printf("Average Salary  : N$%.2f\n", total / count);
        printf("Highest Salary  : N$%.2f\n", highest);
        printf("Lowest Salary   : N$%.2f\n", lowest);
    }

    printf("======================================================\n");
    printf("\nPress Enter to go back...");
    while (getchar() != '\n');
    getchar();
}

void generateBudgetReport(void) {
    printf("\n======================================================\n");
    printf("          BUDGET EXPENDITURE & OVERRUNS REPORT        \n");
    printf("======================================================\n");
    printf("Note: Budget data is managed within the Budget Management menu.\n");
    printf("Please check option 2 under Budget Management for full itemized reports.\n");
    printf("======================================================\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n');
    getchar();
}

void generateSupplierReport(void) {
    printf("\n======================================================\n");
    printf("                SUPPLIER REGISTER REPORT              \n");
    printf("======================================================\n");
    printf("Supplier register data is coordinated via the Supplier module.\n");
    printf("======================================================\n");

    printf("\nPress Enter to go back...");
    while (getchar() != '\n');
    getchar();
}

void generateAssetReport(void) {
    printf("\n======================================================\n");
    printf("                ASSET REGISTER REPORT                 \n");
    printf("======================================================\n");
    
    // Calls the display function directly from assets.h
    displayAssets();

    printf("======================================================\n");
    printf("\nPress Enter to go back...");
    while (getchar() != '\n');
    getchar();
}