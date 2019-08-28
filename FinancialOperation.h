#ifndef FINANCIALOPERATION_H
#define FINANCIALOPERATION_H

#include <iostream>

using namespace std;

class FinancialOperation {
    int operationId, userId, date;
    string item;
    double amount;

public:
    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getUserId();
    int getOperationId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif // FINANCIALOPERATION_H
