#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses):
    userManager(fileNameWithUsers),
    FILE_NAME_WITH_INCOMES(fileNameWithIncomes),
    FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
    budgetManager = NULL;
}
PersonalBudget::~PersonalBudget() {
    delete budgetManager;
    budgetManager = NULL;
}

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogin() {
    userManager.userLogin();
    budgetManager = new BudgetManager(FILE_NAME_WITH_INCOMES,FILE_NAME_WITH_EXPENSES,userManager.getIdOfLoggedInUser());
}

void PersonalBudget::changePasswordOfLoggedInUser() {
    if (userManager.isLoggedIn) {
        userManager.changePasswordOfLoggedInUser();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void PersonalBudget::logoutOfUser() {
    userManager.logoutOfUser();
    delete budgetManager;
    budgetManager = NULL;
}


void PersonalBudget::addIncome() {
    if (userManager.isLoggedIn) {
        budgetManager->addIncome();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void PersonalBudget::addExpense() {
    if (userManager.isLoggedIn) {
        budgetManager->addExpense();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}


bool PersonalBudget::isUserLoggedIn() {
    return userManager.isLoggedIn;
}

void PersonalBudget::showBudgetForCurrentMonth() {
    if (userManager.isLoggedIn) {
        budgetManager->showBudgetForCurrentMonth();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void PersonalBudget::showBudgetFromSelectedPeriod() {
    if (userManager.isLoggedIn) {
        budgetManager->showBudgetFromSelectedPeriod();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void PersonalBudget::showBudgetFromPreviousMonth() {
    if (userManager.isLoggedIn) {
        budgetManager->showBudgetFromPreviousMonth();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}
