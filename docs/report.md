# PAP521S Project A: Technical Report

**Municipal Financial Management System (MFMS)**
 | **Repository:** https://github.com/225031248-Kristoph/Municipal-Financial-Management-System-PROJECT-A

**Members:** Hans Amakali JP (225025426), Amani Enkara (224072536), Rebazar Allembe (223122386), Roberth Mupiri (226066096), Michael Muyoba (225083981), Veranus Ashivudhi (225001195), Kristoph Ndilinawa (225031248)

## 1. Introduction

This report describes the foundation version of the Municipal Financial Management System (MFMS), developed in ANSI C (C99) for Project A of PAP521S Programming in Practice. The MFMS is a menu-driven console application that helps a municipality record employees, departmental budgets, suppliers and assets, and produce summary reports. It was built by a team of seven students using Visual Studio Code, GCC, and Git/GitHub, and is the first working version of a system that will be extended and refactored in Project B.

## 2. Problem Description

Municipalities manage large amounts of financial and administrative information: staff salaries, departmental spending against budget, the suppliers they buy from, and the assets they own. When this information is kept on paper or in disconnected lists, it is hard to search, easy to enter incorrectly, and slow to summarise. A manager who needs to know which departments have overspent, or the average salary of staff, must calculate it by hand.

The MFMS addresses this by keeping the information in one program, checking it when it is entered, allowing it to be searched, and calculating totals and statistics automatically. The system is limited to the concepts taught in Weeks 1 to 8 of the course, so data is held in arrays of structures in memory and is not saved between runs.

## 3. System Objectives

1. Provide a clear menu-driven interface with a main menu and sub-menus.
2. Use suitable variables and data types for each kind of information.
3. Accept input and reject invalid values (negative amounts, empty names, non-numeric input, invalid menu choices).
4. Use arithmetic, relational and logical operators for salary and budget calculations.
5. Use decision-making (`if`, `if-else`, `switch`) and loops for menus, searching and display.
6. Store records in arrays and process text with standard C string functions.
7. Organise the program into functions and separate modules rather than one large `main()`.
8. Work as a team, with every member contributing through GitHub.

## 4. System Features

**Main menu.** The user chooses Employee, Budget, Supplier or Asset Management, Reports, or Exit. Invalid choices display an error and the menu is shown again.

**Employee Management.** The user can add an employee, display all employees and search for an employee. Salary is calculated from the basic salary plus the housing and transport allowances.

**Budget Management.** The user enters a department's allocated budget and expenditure. The system calculates the remaining budget, shows whether the department is within budget or has exceeded it, and summarises the departments that exceeded their allocation.

**Supplier Management.** The user can add suppliers (ID, name, email, telephone, town), display them, search by ID, name or town, and compare two suppliers side by side. Email addresses and telephone numbers are checked before they are stored.

**Asset Management.** The user can add assets to the register, display them and search for an asset.

**Reports.** The Reports menu produces an Employee Report, a Budget Report, a Supplier Report and an Asset Report.

**Data validation.** Input functions reject negative values, empty text, non-numeric input and invalid menu options, and ask the user to try again.

## 5. Program Design

The program is divided into modules, each with a source file (`.c`) and a header file (`.h`), plus `main.c`, which starts the program and connects the menus.

| Module | Files | Key functions |
|--------|-------|---------------|
| Main | `main.c` | `main()`, `budgetMenu()`, `assetMenu()`, `reportsMenu()` |
| Employees | `employees.c/.h` | `addEmployee()`, `displayEmployees()`, `searchEmployee()`, `calculateSalary()`, `employeeMenu()` |
| Budget | `budget.c/.h` | `input_department()`, `calculate_budget()`, `display_report()`, `display_exceeded_summary()` |
| Suppliers | `suppliers.c/.h` | `addSupplier()`, `displaySuppliers()`, `searchSupplier()`, `compareSuppliers()`, `supplierMenu()` |
| Assets | `assets.c/.h` | `addAsset()`, `displayAssets()`, `searchAsset()` |
| Reports | `reports.c/.h` | `displayReportsMenu()`, `generateEmployeeReport()`, `generateBudgetReport()`, `generateSupplierReport()`, `generateAssetReport()` |

**Data structures.** Each module defines a `struct` for its records (for example `Employee`, `Department`, `Asset` and `Supplier`) and stores them in a fixed-size array with a counter for the number of records in use.

**Module communication.** The employee and supplier arrays are private to their files. The Reports module reads them through getter functions such as `getEmployeeCount()`, `getEmployeeTotalSalary()`, `getSupplierCount()` and `getSupplier()`, so it never changes another module's data directly.

**Program flow.** `main()` shows the main menu in a loop and uses a `switch` statement to call the menu function for the chosen module. Each module menu repeats until the user chooses to go back. Values that are only read are passed by value or as `const` pointers, and results are returned from functions such as `calculateSalary()`.

**String processing.** `strcmp()` is used to compare supplier IDs and the budget status text (for example "EXCEEDED"). `strlen()` and `strcpy()` are used when checking and storing supplier text, and `strstr()` is used for name and town searches.

## 6. Challenges Encountered

- **Integrating modules written separately.** When the files were first compiled together, `budget.c` failed because the `Department` type was not defined in `budget.h` and the function prototypes did not match their definitions.
- **Renamed header files.** Renaming `asset.h` to `assets.h` fixed one error but broke `reports.c`, which still included the old name.
- **A module not available at the first integration test.** The supplier module was missing, so `reports.c` could not compile against `suppliers.h`.
- **Stray files in the repository.** An empty file named `gcc` and object files were created by mistake during early commits.
- **Safe input.** Mixing number input and text input can leave characters in the input buffer, so each module needed its own care when reading values.
- `<Add one or two specific challenges from each member.>`

## 7. Solutions Implemented

- **Compile tests and GitHub Issues.** The test lead compiled every module, recorded each error with its owner in a GitHub Issue, and re-tested after fixes were pushed.
- **Corrected headers.** The `Asset` structure was moved into `assets.h`, `budget.h` was updated, and the include in `reports.c` was changed to `assets.h`.
- **Late supplier module.** The supplier module was provided as a stand-in so that the Reports module and the full build could be completed. It exposes `getSupplierCount()` and `getSupplier()` for Reports.
- **Input helper functions.** Modules use helpers such as `clearInputBuffer()`, `readLine()`, `readPositiveInt()` and `readMenuChoice()` to read and check input, with a message and a repeated prompt for invalid values.
- **Repository clean-up.** The stray file was removed and `.gitignore` excludes build output.
- `<Match each member's challenge above with its solution.>`

## 8. Conclusion

The MFMS meets the requirements of Project A: it provides a menu-driven system for employees, budgets, suppliers and assets, validates input, supports searching, performs calculations and produces reports, using arrays, strings, functions and control structures from Weeks 1 to 8. The team worked in modules and used GitHub to share the code and track problems.

The main limitation of this version is that data exists only while the program runs, and each module checks its own input rather than sharing one validation module. Project B will extend this foundation with features such as saving records to files, more advanced searching and sorting, shared validation functions, and a clean-up of the code, building on the existing module structure.
