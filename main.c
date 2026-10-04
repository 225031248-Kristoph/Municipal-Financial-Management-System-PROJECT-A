#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "assets.h"
#include "reports.h"

#define MAX_BUDGET_DEPTS 10

static void budgetMenu(void)
{
    Department departments[MAX_BUDGET_DEPTS];
    int count = 0;
    int choice;

    do {
        printf("\n========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budget Reports\n");
        printf("3. Display Exceeded Budgets\n");
        printf("4. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice.\n");
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (count >= MAX_BUDGET_DEPTS) {
                    printf("Maximum number of departments reached.\n");
                } else {
                    input_department(&departments[count]);
                    calculate_budget(&departments[count]);
                    count++;

                    printf("Department budget added successfully.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No budget records available.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        display_report(&departments[i]);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No budget records available.\n");
                } else {
                    display_exceeded_summary(departments, count);
                }
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 4);
}

static void assetMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("           ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice.\n");
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 4);
}

static void reportsMenu(void)
{
    int choice;

    do {
        displayReportsMenu();
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice.\n");
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                generateEmployeeReport();
                break;

            case 2:
                generateBudgetReport();
                break;

            case 3:
                generateSupplierReport();
                break;

            case 4:
                generateAssetReport();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 5);
}

int main(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                printf("\nSupplier Management is waiting for the Supplier module.\n");
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                reportsMenu();
                break;

            case 6:
                printf("\nExiting Municipal Financial Management System...\n");
                break;

            default:
                printf("Invalid menu choice. Please choose 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}