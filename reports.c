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
    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("No employee records found (employees.txt missing).\n");
        return;
    }

    int id, count = 0;
    char name[50];
    double gross, tax, net;
    double totalGross = 0.0, minSalary = 999999.0, maxSalary = 0.0;

    printf("%-6s %-20s %-12s %-12s\n", "ID", "Name", "Gross (NAD)", "Net (NAD)");
    printf("----------------------------------------------------\n");

    while (fscanf(file, "%d;%49[^;];%lf;%lf;%lf\n", &id, name, &gross, &tax, &net) == 5) {
        printf("%-6d %-20s %-12.2f %-12.2f\n", id, name, gross, net);
        totalGross += gross;
        if (gross < minSalary) minSalary = gross;
        if (gross > maxSalary) maxSalary = gross;
        count++;
    }
    fclose(file);

    if (count > 0) {
        printf("----------------------------------------------------\n");
        printf("Total Employees: %d\n", count);
        printf("Average Gross Salary: NAD %.2f\n", totalGross / count);
        printf("Minimum Gross Salary: NAD %.2f\n", minSalary);
        printf("Maximum Gross Salary: NAD %.2f\n", maxSalary);
    } else {
        printf("No valid employee records read.\n");
    }
}

void generateBudgetReport(void) {
    printf("\n--- BUDGET EXPENDITURE & OVERRUNS REPORT ---\n");
    FILE *file = fopen("budget.txt", "r");
    if (file == NULL) {
        printf("No budget records found (budget.txt missing).\n");
        return;
    }

    char dept[50];
    double allocated, spent;
    printf("%-20s %-15s %-15s %-15s\n", "Department", "Allocated (NAD)", "Spent (NAD)", "Status");
    printf("-------------------------------------------------------------------\n");

    while (fscanf(file, "%49[^;];%lf;%lf\n", dept, &allocated, &spent) == 3) {
        double diff = spent - allocated;
        if (diff > 0) {
            printf("%-20s %-15.2f %-15.2f OVERRUN (+%.2f)\n", dept, allocated, spent, diff);
        } else {
            printf("%-20s %-15.2f %-15.2f WITHIN BUDGET\n", dept, allocated, spent);
        }
    }
    fclose(file);
}

void generateSupplierReport(void) {
    printf("\n--- SUPPLIER REGISTER REPORT ---\n");
    FILE *file = fopen("suppliers.txt", "r");
    if (file == NULL) {
        printf("No supplier records found (suppliers.txt missing).\n");
        return;
    }

    int id;
    char name[50], contact[50];
    printf("%-6s %-20s %-20s\n", "ID", "Supplier Name", "Contact");
    printf("----------------------------------------------------\n");

    while (fscanf(file, "%d;%49[^;];%49[^\n]\n", &id, name, contact) == 3) {
        printf("%-6d %-20s %-20s\n", id, name, contact);
    }
    fclose(file);
}

void generateAssetReport(void) {
    printf("\n--- ASSET REGISTER REPORT ---\n");
    FILE *file = fopen("assets.txt", "r");
    if (file == NULL) {
        printf("No asset records found (assets.txt missing).\n");
        return;
    }

    int id;
    char assetName[50];
    double value;
    printf("%-6s %-25s %-15s\n", "ID", "Asset Name", "Value (NAD)");
    printf("----------------------------------------------------\n");

    while (fscanf(file, "%d;%49[^;];%lf\n", &id, assetName, &value) == 3) {
        printf("%-6d %-25s %-15.2f\n", id, assetName, value);
    }
    fclose(file);
}