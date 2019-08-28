#include "BudgetManager.h"

BudgetManager::BudgetManager(string fileNameWithIncomes,string fileNameWithExpenses,int idOfLoggedInUser):
    fileWithIncomes(fileNameWithIncomes),
    //fileWithExpenses(fileNameWithExpenses),
    ID_OF_LOGGED_IN_USER(idOfLoggedInUser) {


}

void BudgetManager::addIncome() {
    system("cls");
    cout << ">>> DODAJ PRZYCHOD <<<" << endl << endl;
    FinancialOperation income = enterNewIncomeData();

    incomes.push_back(income);
    fileWithIncomes.addOperationToFile(income);

    cout << endl << "Przychod dodany pomyslnie." << endl << endl;

    system("pause");

}

int BudgetManager::giveTheDate() {
    int date;
    char choice;
    bool correctDate = false;
    string dateForCheck;
    do {
        cout << "Czy przychod dotyczy dzisiejszej daty (t/n) ? ";
        choice = AuxiliaryMethods::getSign();

        if (choice == 't') {
            Date todayDate;
            date = todayDate.getDate();
            cout << "Wczytana data: " << date << endl;
            correctDate = true;

        } else if (choice == 'n') {
            cout << endl << "Podaj date w formacie [rrrr-mm-dd] : ";
            dateForCheck = AuxiliaryMethods::getLineOfText();
            Date checkedDate(dateForCheck);
            date = checkedDate.getDate();
            cout << "Wczytana data: " << date << endl;
            correctDate = true;
        }
    } while (!correctDate);

    return date;
}

string BudgetManager::giveTheItem() {
    cout << "Czego dotyczy przychod: ";
    return AuxiliaryMethods::getLineOfText();
}

float BudgetManager::giveTheAmount() {
    string amount;
    cout << "Podaj kwote przychodu: ";
    amount  = AuxiliaryMethods::getLineOfText();
    return AuxiliaryMethods::convertStringToFloat(amount);
}

FinancialOperation BudgetManager::enterNewIncomeData() {

    FinancialOperation income;
    string item, amount;

    income.setOperationId(getIdOfNewOperation());
    income.setUserId(ID_OF_LOGGED_IN_USER);
    income.setDate(giveTheDate());
    income.setItem(giveTheItem());
    income.setAmount(giveTheAmount());

    return income;
}

int BudgetManager::getIdOfNewOperation() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getOperationId() + 1;
}
