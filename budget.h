#ifndef BUDGET_H
#define BUDGET_H

int getBudgetCount(void);
char* getBudgetName(int index);
double getBudgetRevenue(int index);
double getBudgetExpenditure(int index);

void display_report(void);
void display_exceeded_summary(void);

#endif