# MFMS Test Plan

**Course:** PAP521S – Project A
**Test lead:** Student 7

## 1. Main Menu

| ID | Input | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| MN-01 | 1 | Employee menu opens | | | |
| MN-02 | 2 | Budget menu opens | | | |
| MN-03 | 3 | Supplier menu opens | | | |
| MN-04 | 4 | Asset menu opens | | | |
| MN-05 | 5 | Reports menu opens | | | |
| MN-06 | 6 | Program exits cleanly | | | |
| MN-07 | 0 | "Invalid choice", menu shown again | | | |
| MN-08 | 7 | "Invalid choice", menu shown again | | | |
| MN-09 | -1 | "Invalid choice", menu shown again | | | |
| MN-10 | abc | Rejected, no infinite loop or crash | | | |
| MN-11 | Empty input (Enter only) | Rejected, menu shown again | | | |
| MN-12 | 1.5 | Rejected or handled safely | | | |
| MN-13 | Return from each sub-menu | Returns to main menu | | | |

## 2. Employee Management

| ID | Input | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| EMP-01 | Valid employee (ID, name, dept, basic 10000, housing 2000, transport 500) | Added successfully | | | |
| EMP-02 | Duplicate employee ID | Rejected | | | |
| EMP-03 | Empty name | Rejected, re-prompt | | | |
| EMP-04 | Negative basic salary | Rejected, re-prompt | | | |
| EMP-05 | Negative housing or transport allowance | Rejected | | | |
| EMP-06 | Salary entered as text (abc) | Rejected, no crash | | | |
| EMP-07 | Basic salary 0 | Handled as per group decision (accept or reject) | | | |
| EMP-08 | Display with 0 employees | "No employees" message | | | |
| EMP-09 | Display with 3 employees | All 3 listed, aligned | | | |
| EMP-10 | Search by ID that exists | Correct employee shown | | | |
| EMP-11 | Search by ID that does not exist | "Not found" | | | |
| EMP-12 | Search by name (exact) | Correct employee shown | | | |
| EMP-13 | Search by name with different letter case | Behaviour matches group decision | | | |
| EMP-14 | Salary calculation for basic 10000 + 2000 + 500 | Gross = 12500.00 | | | |
| EMP-15 | Name at maximum length | Stored and shown fully, no overflow | | | |
| EMP-16 | Name longer than maximum | Truncated or rejected, no crash | | | |
| EMP-17 | Add past the array limit | "Employee list full" | | | |

## 3. Budget Management

| ID | Input | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| BUD-01 | Finance, budget 500000, expenditure 420000 | Remaining 80000.00, WITHIN BUDGET | | | |
| BUD-02 | Budget 100000, expenditure 100000 | Remaining 0.00, WITHIN BUDGET | | | |
| BUD-03 | Budget 100000, expenditure 120000 | Remaining -20000.00, EXCEEDED | | | |
| BUD-04 | Negative budget | Rejected | | | |
| BUD-05 | Negative expenditure | Rejected | | | |
| BUD-06 | Empty department name | Rejected | | | |
| BUD-07 | Budget as text | Rejected, no crash | | | |
| BUD-08 | Duplicate department name | Handled per group decision | | | |
| BUD-09 | Display with no departments | "No budgets" message | | | |
| BUD-10 | Display with several departments | All shown with status | | | |
| BUD-11 | Over-budget list with 2 of 4 departments over | Only those 2 listed | | | |
| BUD-12 | Over-budget list with none over | "No departments exceeded budget" | | | |
| BUD-13 | Add past the array limit | "Budget list full" | | | |

## 4. Supplier Management

| ID | Input | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| SUP-01 | SUP001, Namib Water Corp, contact@namibwater.na, +264 61 200 1111, Windhoek | "Supplier SUP001 added successfully" | | | |
| SUP-02 | Duplicate ID SUP001 | Rejected | | | |
| SUP-03 | Empty supplier name | Rejected | | | |
| SUP-04 | Email without @ | Rejected | | | |
| SUP-05 | Phone abc123 | Rejected | | | |
| SUP-06 | Empty town | Rejected | | | |
| SUP-07 | Display with 0 suppliers | "No suppliers registered" | | | |
| SUP-08 | Display with 3 suppliers | 3 rows, columns aligned | | | |
| SUP-09 | Search by ID that exists | Correct supplier shown | | | |
| SUP-10 | Search town = Swakopmund | Matching supplier(s) shown | | | |
| SUP-11 | Search town with several matches | All matches shown | | | |
| SUP-12 | Search town that does not exist | "No supplier found" | | | |
| SUP-13 | Compare two valid IDs | Side-by-side table shown | | | |
| SUP-14 | Compare with unknown ID | Error message | | | |
| SUP-15 | Compare a supplier with itself | Handled sensibly | | | |
| SUP-16 | Name of 46 characters (Namib Electrical and Hardware Supplies Pty Ltd) | Stored and shown in full | | | |
| SUP-17 | Add past the array limit | "Supplier list full" | | | |

## 5. Asset Management

| ID | Input | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| AST-01 | Valid asset (ID, name, type, value 250000, dept, condition) | Added successfully | | | |
| AST-02 | Duplicate asset ID | Rejected | | | |
| AST-03 | Empty asset name | Rejected | | | |
| AST-04 | Negative purchase value | Rejected | | | |
| AST-05 | Purchase value as text | Rejected, no crash | | | |
| AST-06 | Display with 0 assets | "No assets" message | | | |
| AST-07 | Display with several assets | All listed, aligned | | | |
| AST-08 | Search by ID (exists) | Correct asset shown | | | |
| AST-09 | Search by name (exists) | Correct asset shown | | | |
| AST-10 | Search by type (several matches) | All matches shown | | | |
| AST-11 | Search with no match | "Not found" | | | |
| AST-12 | Add past the array limit | "Asset list full" | | | |

## 6. Reports

| ID | Input / Data state | Expected | Actual | Result | Tester |
|----|--------------------|----------|--------|--------|--------|
| REP-01 | Employee report, 0 employees | No crash, no divide by zero, clear message | | | |
| REP-02 | Employee report, 1 employee | Average = highest = lowest | | | |
| REP-03 | Employee report, salaries 8500, 18500, 42000 | Total 3, average 23000.00, highest 42000, lowest 8500 | | | |
| REP-04 | Budget report, no data | Clear message, totals 0.00 | | | |
| REP-05 | Budget report, several departments | Total allocated, total spent and remaining all correct | | | |
| REP-06 | Budget report with over-budget departments | They are listed | | | |
| REP-07 | Supplier report, 0 suppliers | "No suppliers registered" | | | |
| REP-08 | Supplier report, several suppliers | All listed with real data (not stub output) | | | |
| REP-09 | Asset report, 0 assets | "No assets" message | | | |
| REP-10 | Asset report, several assets | All listed | | | |
| REP-11 | Add data, then run report | Report reflects the newly added data | | | |

## 7. Integration and Build

| ID | Check | Expected | Actual | Result | Tester |
|----|-------|----------|--------|--------|--------|
| INT-01 | The gcc command from the README on a clean clone | Builds with no errors | | | |
| INT-02 | Compile with -Wall -Wextra | No serious warnings | | | |
| INT-03 | stubs.c removed from repo and build | No duplicate definitions | | | |
| INT-04 | Run every menu option in one session | No crash | | | |
| INT-05 | Add data in each module, then view all reports | Consistent results | | | |
| INT-06 | strcmp() / strlen() used in search and validation | Present in source | | | |
| INT-07 | No single large main() | main() only calls menu functions | | | |
