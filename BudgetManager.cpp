#include "BudgetManager.h"

BudgetManager::BudgetManager(string fileNameWithIncomes,string fileNameWithExpenses,int idOfLoggedInUser):
    fileWithIncomes(fileNameWithIncomes),
    //fileWithExpenses(fileNameWithExpenses),
    ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
{


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

FinancialOperation BudgetManager::enterNewIncomeData() {

    FinancialOperation income;
    string dateForCheck, item, amount;
    int  date;
    char choice;
    bool correctDate = false;

    income.setOperationId(getIdOfNewOperation());
    income.setUserId(ID_OF_LOGGED_IN_USER);
    //user.setUserId(getIdOfNewUser());
    do {
        cout << "Czy przychod dotyczy dzisiejszej daty (t/n) ? ";
        choice = AuxiliaryMethods::getSign();

        if (choice == 't') {
            Date todayDate;
            date = todayDate.getIntegerDate();
            correctDate = true;

        } else if (choice == 'n') {
            cout << endl << "Podaj date w formacie [rrrr-mm-dd] : ";
            dateForCheck = AuxiliaryMethods::getLineOfText();
            Date checkedDate(dateForCheck,false);
            date = checkedDate.getIntegerDate();
            correctDate = true;
        }
    } while (!correctDate);

    income.setDate(date); // na int

    cout << "Czego dotyczy przychod: ";
    item  = AuxiliaryMethods::getLineOfText();
    income.setItem(item);

    cout << "Podaj kwote przychodu: ";
    amount  = AuxiliaryMethods::getLineOfText();
    income.setAmount(AuxiliaryMethods::convertStringToFloat(amount)); // na float


    return income;
}

int BudgetManager::getIdOfNewOperation() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getOperationId() + 1;
}
