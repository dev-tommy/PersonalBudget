#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
//#include "BudgetManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
//    BudgetManager *budgetManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses);
    ~PersonalBudget();
    void userRegistration();
    void userLogin();
    void changePasswordOfLoggedInUser();
    void logoutOfUser();
    void addIncome();
    void addExpense();
    void showBudgetForCurrentMonth();
    void showBudgetFromPreviousMonth();
    void showBudgetFromSelectedPeriod();
    bool isUserLoggedIn();
};

#endif // PERSONALBUDGET_H
