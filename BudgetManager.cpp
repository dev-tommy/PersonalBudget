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
        amount = AuxiliaryMethods::findAndReplace(amount, ",", ".");
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

void BudgetManager::showBudgetForCurrentMonth() {
    Date todayDate;
    int startDate, endDate;

    endDate = todayDate.getEndDate(todayDate.getDate());
    startDate = todayDate.getStartDate(todayDate.getDate());

    system("cls");
    cout << ">>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    cout << "Od " << AuxiliaryMethods::getDateAsString(startDate) << " do " << AuxiliaryMethods::getDateAsString(endDate) << ":" << endl << endl;

    showBudgetFromSelectedPeriod(startDate, endDate);
    system("pause");
}

void BudgetManager::showBudgetFromPreviousMonth() {
    Date todayDate;
    int startDate, endDate;
    int today, month, year, previusMonthDate;

    today = todayDate.getDate();
    month = (today / 100) % 100 - 1;
    year = today / 10000;
    if (month < 1) {
        month += 12;
        year--;
    }

    previusMonthDate = year * 10000 + month  * 100 + 1;

    endDate = todayDate.getEndDate(previusMonthDate);
    startDate = todayDate.getStartDate(previusMonthDate);

    system("cls");
    cout << ">>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
    cout << "Od " << AuxiliaryMethods::getDateAsString(startDate) << " do " << AuxiliaryMethods::getDateAsString(endDate) << ":" << endl << endl;

    showBudgetFromSelectedPeriod(startDate, endDate);
    system("pause");
}

void BudgetManager::showBudgetFromSelectedPeriod() {
    bool correctDate = false;
    string dateForCheck;
    int startDate;
    int endDate;

    system("cls");
    cout << ">>> BILANS Z WYBRANEGO OKRESU <<<" << endl;

    do {
        cout << endl << "Podaj date poczatkowa w formacie [rrrr-mm-dd] : ";
        dateForCheck = AuxiliaryMethods::getLineOfText();
        Date checkedStartDate(dateForCheck);
        startDate = checkedStartDate.getDate();
        cout << "Wczytana data: " << AuxiliaryMethods::getDateAsString(startDate) << endl;
        correctDate = true;

    } while (!correctDate);

    correctDate = false;
    do {
        cout << endl << "Podaj date koncowa w formacie [rrrr-mm-dd] : ";
        dateForCheck = AuxiliaryMethods::getLineOfText();
        Date checkedEndDate(dateForCheck);
        endDate = checkedEndDate.getDate();

        if ( endDate >= startDate ) {
            cout << "Wczytana data: " << AuxiliaryMethods::getDateAsString(endDate) << endl;
            correctDate = true;
            system("pause");
        } else {
            cout << "Data jest wczesniejsza niz poczatkowa" << endl;
        }

    } while (!correctDate);

    system("cls");
    cout << ">>> BILANS Z WYBRANEGO OKRESU <<<" << endl;
    cout << "Od " << AuxiliaryMethods::getDateAsString(startDate) << " do " << AuxiliaryMethods::getDateAsString(endDate) << ":" << endl << endl;
    showBudgetFromSelectedPeriod(startDate, endDate);
}

void BudgetManager::showBudgetFromSelectedPeriod(int startDate, int endDate) {
    const int COLUMN_DATE_SIZE = 12;
    const int COLUMN_ITEM_SIZE = 40;
    const int COLUMN_AMOUNT_SIZE = 20;

    vector<FinancialOperation> incomesToShow;
    vector<FinancialOperation> expensesToShow;

    string columnDate, columnItem, columnAmount;
    string lineOfText;

    double sumOfIncomes = 0;
    double sumOfExpenses = 0;

    for (int i = 0; i< incomes.size() ; i++) {
        if ((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate)) {
            incomesToShow.push_back(incomes[i]);
        }
    }


    cout << "PRZYCHODY:" << endl;

    lineOfText = "";
    lineOfText.resize(1 + COLUMN_DATE_SIZE + 1 + COLUMN_ITEM_SIZE + 1 + COLUMN_AMOUNT_SIZE + 1, '-');
    cout << lineOfText << endl;

    for (int i=0; i<incomesToShow.size() ; i++) {
        columnDate = AuxiliaryMethods::getDateAsString(incomesToShow[i].getDate());
        columnDate = " " + columnDate;
        columnDate.resize(COLUMN_DATE_SIZE, ' ');

        columnItem = " " + incomesToShow[i].getItem();
        columnItem.resize(COLUMN_ITEM_SIZE, ' ');

        sumOfIncomes += incomesToShow[i].getAmount();

        columnAmount = AuxiliaryMethods::convertDoubleToString(incomesToShow[i].getAmount()) + " ";
        columnAmount.insert(0 , COLUMN_AMOUNT_SIZE - columnAmount.length(), ' ');
        columnAmount.resize(COLUMN_AMOUNT_SIZE, ' ');

        cout << "|" << columnDate << "|" << columnItem << "|" << columnAmount << "|" << endl;
    }

    lineOfText = "";
    lineOfText.resize(1 + COLUMN_DATE_SIZE + 1 + COLUMN_ITEM_SIZE + 1 + COLUMN_AMOUNT_SIZE + 1, '-');
    cout << lineOfText << endl;


    for (int i = 0; i< expenses.size() ; i++) {
        if ((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <= endDate)) {
            expensesToShow.push_back(expenses[i]);
        }
    }

    cout << "WYDATKI:" << endl;

    lineOfText = "";
    lineOfText.resize(1 + COLUMN_DATE_SIZE + 1 + COLUMN_ITEM_SIZE + 1 + COLUMN_AMOUNT_SIZE + 1, '-');
    cout << lineOfText << endl;

    for (int i=0; i<expensesToShow.size() ; i++) {
        columnDate = AuxiliaryMethods::getDateAsString(expensesToShow[i].getDate());
        columnDate = " " + columnDate;
        columnDate.resize(COLUMN_DATE_SIZE, ' ');

        columnItem = " " + expensesToShow[i].getItem();
        columnItem.resize(COLUMN_ITEM_SIZE, ' ');

        sumOfExpenses = expensesToShow[i].getAmount();

        columnAmount = AuxiliaryMethods::convertDoubleToString(expensesToShow[i].getAmount()) + " ";
        columnAmount.insert(0 , COLUMN_AMOUNT_SIZE - columnAmount.length(), ' ');
        columnAmount.resize(COLUMN_AMOUNT_SIZE, ' ');

        cout << "|" << columnDate << "|" << columnItem << "|" << columnAmount << "|" << endl;
    }


    lineOfText = "";
    lineOfText.resize(1 + COLUMN_DATE_SIZE + 1 + COLUMN_ITEM_SIZE + 1 + COLUMN_AMOUNT_SIZE + 1, '-');
    cout << lineOfText << endl;

    cout << "                                       " << "Suma przychodow:           " << sumOfIncomes << endl;
    cout << "                                         " << "Suma wydatkow:           " << sumOfExpenses << endl;

    cout << endl << "                                               " << "Bilans:           " << (sumOfIncomes - sumOfExpenses) << endl;

    system("pause");
}


