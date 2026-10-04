#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define NAME_LEN 100
#define DEPT_LEN 60

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
    double totalSalary;
} Employee;

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculateSalary(const Employee *employee);

int getEmployeeCount(void);
int getEmployeeId(int index);
const char *getEmployeeName(int index);
const char *getEmployeeDepartment(int index);
double getEmployeeTotalSalary(int index);

#endif
