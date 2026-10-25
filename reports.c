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
    
    int count = getEmployeeCount();
    if (count == 0) {
        printf("No employee records found in memory.\n");
        return;
    }

    double totalSalary = 0.0;
    double minSalary = 999999.0;
    double maxSalary = 0.0;

    printf("%-6s %-20s %-15s\n", "ID", "Name", "Total Salary (NAD)");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int id = getEmployeeId(i);
        const char *name = getEmployeeName(i);
        double salary = getEmployeeTotalSalary(i);

        printf("%-6d %-20s NAD %-12.2f\n", id, name, salary);
        
        totalSalary += salary;
        if (salary < minSalary) minSalary = salary;
        if (salary > maxSalary) maxSalary = salary;
    }

    printf("--------------------------------------------------\n");
    printf("Total Employees: %d\n", count);
    printf("Average Salary:  NAD %.2f\n", totalSalary / count);
    printf("Minimum Salary:  NAD %.2f\n", minSalary);
    printf("Maximum Salary:  NAD %.2f\n", maxSalary);
}

void generateBudgetReport(void) {
    printf("\n--- BUDGET EXPENDITURE & OVERRUNS REPORT ---\n");
    printf("Budget reporting relies on active departmental data entered in Budget Management.\n");
}

void generateSupplierReport(void) {
    printf("\n--- SUPPLIER REGISTER REPORT ---\n");
    printf("Supplier register data is managed via the Supplier module.\n");
}

void generateAssetReport(void) {
    printf("\n--- ASSET REGISTER REPORT ---\n");
    printf("Asset register data is managed via the Asset module.\n");
}