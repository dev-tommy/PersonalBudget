#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>

#include "AuxiliaryMethods.h"
#include "FinancialOperation.h"

using namespace std;

class Table {
    double sumOfAmounts = 0;
    const int COLUMN_DATE_SIZE, COLUMN_ITEM_SIZE, COLUMN_AMOUNT_SIZE;
    vector<FinancialOperation> operations;

    void showFullLine();
    void showTableRows();
    void showTableRows(string columnDateAlign, string columnItemAlign, string columnAmountAlign);
    void showTableOneRow(string columnDateName, string columnItemName, string columnAmountName);
    void showTableOneRow(string columnDateName, string columnDateAlign, string columnItemName, string columnItemAlign,string columnAmountName, string columnAmountAlign);
    string alignText(string toAlignText, string alignType, int spaceSize);
public:
    Table(int columnDateSize, int columnItemSize, int columnAmountSize, vector<FinancialOperation> operations);
    void showTable();
    void showSumOfAmounts(string titleOfOperationsSum);
    void showBalance(double balanceValue);
    double getSumOfAmounts();
};

#endif // TABLE_H
