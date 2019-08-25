#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "FinancialOperation.h"
#include "FileWithFinancialOperations.h"
#include "Date.h"

using namespace std;

class BudgetManager {
    const int ID_OF_LOGGED_IN_USER;
    vector<FinancialOperation> incomes;
    //vector<FinancialOperation> expenses;
    FileWithFinancialOperations fileWithIncomes;
    //FileWithFinancialOperations fileWithExpenses;
    FinancialOperation enterNewIncomeData();
    int getIdOfNewOperation();

public:
    BudgetManager(string fileNameWithIncomes,string fileNameWithExpenses,int idOfLoggedInUser);
    void addIncome();
    //void addExpense();
    //void showBudgetFromSelectedPeriod();
    //void setIdOfLoggedInUser();

};

#endif // BUDGETMANAGER_H
