# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Project:** Project A
**Language:** C
**Tools:** Visual Studio Code, GCC, Git & GitHub

| # | Name | Student number | Responsibility |
|---|------|----------------|----------------|
| 1 | Hans Amakali JP | 225025426 | Employee Management |
| 2 | Amani Enkara | 224072536 | Budget Management |
| 3 | Rebazar Allembe | 223122386 | Supplier Management |
| 4 | Roberth Mupiri | 226066096 | Asset Management |
| 5 | Michael Muyoba | 225083981 | Reports |
| 6 | Veranus Ashivudhi | 225001195 | Functions, integration and validation |
| 7 | Kristoph Ndilinawa | 225031248 | Testing, documentation and Git coordination |

## Project Description

The MFMS is a menu-driven console application written in C for a municipality. It stores and processes employee, budget, supplier and asset information in memory using arrays of structures, and produces summary reports.

## System Features

- Main menu with clear navigation and handling of invalid choices.
- **Employee Management:** add, display and search employees; calculate salary (basic + housing + transport allowance).
- **Budget Management:** enter departmental budgets and expenditure, calculate the remaining budget, show WITHIN BUDGET / EXCEEDED status, and list departments over budget.
- **Supplier Management:** add, display and search suppliers; compare two suppliers.
- **Asset Management:** add, display and search the municipal asset register.
- **Reports:** employee statistics (total, average, highest, lowest salary), budget summary, supplier list and asset list.
- **Input validation:** rejects negative values, empty names and non-numeric input.
- **Modular design:** one source/header pair per module, no single large `main()`.

## Project Structure

```
MFMS/
|-- main.c
|-- employees.c / employees.h
|-- budget.c / budget.h
|-- suppliers.c / suppliers.h
|-- assets.c / assets.h
|-- reports.c / reports.h
|-- validation.c / validation.h
|-- common.h
|-- docs/   (technical report, contribution records)
|-- tests/  (test plan)
|-- README.md
```

## Compilation Instructions

Requires GCC.

```
gcc -std=c99 -Wall -Wextra -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c validation.c
```

## How to Run

```
mfms.exe        # Windows
```

## Individual Responsibilities

| Member | Modules / files | Main functions |
|--------|-----------------|----------------|
| 1 | employees.c/.h | |
| 2 | budget.c/.h | |
| 3 | suppliers.c/.h | |
| 4 | assets.c/.h | |
| 5 | reports.c/.h | |
| 6 | main.c, validation.c/.h, common.h | |
| 7 | README.md, docs/, tests/ | Repo setup, PR reviews, test plan, report assembly |

## Testing

The full test plan is in `tests/test_plan.md`.

## Repository

https://github.com/225031248-Kristoph/Municipal-Financial-Management-System-PROJECT-A
