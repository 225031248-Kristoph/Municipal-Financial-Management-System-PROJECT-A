#ifndef BUDGET_H
#define BUDGET_H

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_STATUS_LEN 20
#define MAX_DEPTS 10

typedef struct {
    char name[MAX_NAME_LEN];
    double allocated_budget;
    double expenditure;
    double remaining_budget;
    char status[MAX_STATUS_LEN];
} Department;

void input_department(Department *dept);
void calculate_budget(Department *dept);
void display_report(const Department *dept);
void display_exceeded_summary(const Department depts[], int count);

#endif