#include "Table.h"

Table::Table(int columnDateSize, int columnItemSize, int columnAmountSize, vector<FinancialOperation> operationsToShow) :
    COLUMN_DATE_SIZE(columnDateSize),
    COLUMN_ITEM_SIZE(columnItemSize),
    COLUMN_AMOUNT_SIZE(columnAmountSize) {

    operations = operationsToShow;
    sumOfAmounts = 0;
}

void Table::showTable() {
    showFullLine();
    showTableOneRow("Data", "Tytul", "Kwota");
    showFullLine();
    showTableRows();
    showFullLine();
}

void Table::showFullLine() {
    string lineOfText = "";
    lineOfText.resize(1 + COLUMN_DATE_SIZE + 1 + COLUMN_ITEM_SIZE + 1 + COLUMN_AMOUNT_SIZE + 1, '-');
    cout << lineOfText << endl;
}

string Table::alignText(string toAlignText, string alignType, int spaceSize) {
    string alignedText = toAlignText;
    if (alignType == "Center") {
        alignedText.insert(0, (spaceSize - alignedText.length()) / 2, ' ');
        alignedText.resize(spaceSize, ' ');

    } else if (alignType == "Left") {
        alignedText = " " + alignedText;
        alignedText.resize(spaceSize, ' ');

    } else if (alignType == "Right") {
        alignedText.insert(0, spaceSize - alignedText.length() - 1, ' ');
        alignedText.resize(spaceSize, ' ');
    }
    return alignedText;
}

void Table::showTableOneRow(string columnDateName, string columnDateAlign, string columnItemName, string columnItemAlign,string columnAmountName, string columnAmountAlign) {
    string columnDate, columnItem, columnAmount;
    string lineOfText = "";

    columnDate = alignText(columnDateName, columnDateAlign, COLUMN_DATE_SIZE);
    columnAmount = alignText(columnAmountName, columnAmountAlign, COLUMN_AMOUNT_SIZE);
    columnItem = alignText(columnItemName, columnItemAlign, COLUMN_ITEM_SIZE);

    lineOfText = "|" + columnDate + "|" + columnItem + "|" + columnAmount + "|";
    cout << lineOfText << endl;
}

void Table::showTableRows(string columnDateAlign, string columnItemAlign, string columnAmountAlign) {
    string columnDate, columnItem, columnAmount;
    sumOfAmounts = 0;
    for (int i = 0; i < operations.size() ; i++) {
        sumOfAmounts += operations[i].getAmount();

        columnDate = AuxiliaryMethods::getDateAsString(operations[i].getDate());
        columnItem = operations[i].getItem();
        columnAmount = AuxiliaryMethods::convertDoubleToString(operations[i].getAmount());

        showTableOneRow(columnDate, columnDateAlign, columnItem, columnItemAlign, columnAmount, columnAmountAlign);
    }
}

void Table::showSumOfAmounts(string titleOfOperationsSum) {
    string lineOfText = "";
    string title, sum;

    title = alignText(titleOfOperationsSum, "Right", COLUMN_ITEM_SIZE);
    sum = alignText(AuxiliaryMethods::convertDoubleToString(sumOfAmounts), "Right", COLUMN_AMOUNT_SIZE);

    lineOfText.insert(0, (1 + COLUMN_DATE_SIZE + 1), ' ');
    lineOfText += title + " " + sum;
    cout << lineOfText << endl;
}


void Table::showBalance(double balanceValue) {
    string lineOfText = "";
    string title, balance;

    title = alignText("Saldo:", "Right", COLUMN_ITEM_SIZE);
    balance = alignText(AuxiliaryMethods::convertDoubleToString(balanceValue), "Right", COLUMN_AMOUNT_SIZE);

    showFullLine();

    lineOfText.insert(0, (1 + COLUMN_DATE_SIZE + 1), ' ');
    lineOfText += title + " " + balance;
    cout << lineOfText << endl;

}
void Table::showTableOneRow(string columnDateName, string columnItemName, string columnAmountName) {
    showTableOneRow(columnDateName, "Center", columnItemName, "Center", columnAmountName, "Center");
}

void Table::showTableRows() {
    showTableRows("Center", "Left", "Right");
}



double Table::getSumOfAmounts() {
    return sumOfAmounts;
}
