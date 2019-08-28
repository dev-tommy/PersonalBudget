#include "BudgetManager.h"

BudgetManager::BudgetManager(string fileNameWithIncomes,string fileNameWithExpenses,int idOfLoggedInUser):
    fileWithIncomes(fileNameWithIncomes),
    fileWithExpenses(fileNameWithExpenses),
    ID_OF_LOGGED_IN_USER(idOfLoggedInUser) {

    incomes = fileWithIncomes.loadFinancialOperationsFromFile(ID_OF_LOGGED_IN_USER);
    expenses = fileWithExpenses.loadFinancialOperationsFromFile(ID_OF_LOGGED_IN_USER);

}

void BudgetManager::addIncome() {
    system("cls");
    cout << ">>> DODAJ PRZYCHOD <<<" << endl << endl;
    FinancialOperation income = enterNewFinancialOperationData();

    income.setOperationId(fileWithIncomes.getLastIdOfOperation()+1);
    income.setUserId(ID_OF_LOGGED_IN_USER);

    incomes.push_back(income);

    fileWithIncomes.addOperationToFile(income);

    cout << endl << "Przychod dodany pomyslnie." << endl << endl;

    system("pause");

}

void BudgetManager::addExpense() {
    system("cls");
    cout << ">>> DODAJ WYDATEK <<<" << endl << endl;
    FinancialOperation expense = enterNewFinancialOperationData();

    expense.setOperationId(fileWithExpenses.getLastIdOfOperation()+1);
    expense.setUserId(ID_OF_LOGGED_IN_USER);

    expenses.push_back(expense);

    fileWithExpenses.addOperationToFile(expense);

    cout << endl << "Wydatek dodany pomyslnie." << endl << endl;

    system("pause");

}

int BudgetManager::giveTheDate() {
    int date;
    char choice;
    bool correctDate = false;
    string dateForCheck;
    do {
        cout << "Czy operacja dotyczy dzisiejszej daty (t/n) ? ";
        choice = AuxiliaryMethods::getSign();

        if (choice == 't') {
            Date todayDate;
            date = todayDate.getDate();
            cout << "Wczytana data: " << AuxiliaryMethods::getDateAsString(date) << endl;
            correctDate = true;

        } else if (choice == 'n') {
            cout << endl << "Podaj date w formacie [rrrr-mm-dd] : ";
            dateForCheck = AuxiliaryMethods::getLineOfText();
            Date checkedDate(dateForCheck);
            date = checkedDate.getDate();
            cout << "Wczytana data: " << AuxiliaryMethods::getDateAsString(date) << endl;
            correctDate = true;
        }
    } while (!correctDate);

    return date;
}

string BudgetManager::giveTheItem() {
    cout << "Czego dotyczy operacja: ";
    return AuxiliaryMethods::getLineOfText();
}

double BudgetManager::giveTheAmount() {
    string amount;
    double convertedAmountToDouble;
    string convertedAmountToString;
    int decimalPointPosition = 0;
    bool correctAmount = false;
    do {
        cout << "Podaj kwote (do dwoch miejsc po przecinku): ";
        amount  = AuxiliaryMethods::getLineOfText();
        amount = AuxiliaryMethods::findAndReplace(amount, "," , ".");
        decimalPointPosition = amount.length() - amount.find(".");

        if (decimalPointPosition == 1) {
            amount += "00";
        } else if (decimalPointPosition == 2) {
            amount += "0";
        } else if (amount.find(".") == -1) {
            amount += ".00";
        }

        convertedAmountToDouble = AuxiliaryMethods::convertStringToDouble(amount);
        convertedAmountToDouble = (convertedAmountToDouble * 100) / 100;
        convertedAmountToString = AuxiliaryMethods::convertDoubleToString(convertedAmountToDouble);

        if (!(amount == convertedAmountToString)) {
            cout << "Kwota nieporawnie odczytana: " << convertedAmountToString << endl;
            continue;
        }

        correctAmount = true;
    } while (!correctAmount);


    return AuxiliaryMethods::convertStringToDouble(amount);
}

FinancialOperation BudgetManager::enterNewFinancialOperationData() {

    FinancialOperation operation;
    string item, amount;

    operation.setDate(giveTheDate());
    operation.setItem(giveTheItem());
    operation.setAmount(giveTheAmount());

    return operation;
}
