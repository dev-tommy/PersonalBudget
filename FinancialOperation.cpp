#include "FinancialOperation.h"

    void FinancialOperation::setOperationId(int newOperationId) {
        operationId = newOperationId;
    }

    void FinancialOperation::setUserId(int newUserId) {
        userId = newUserId;
    }

    void FinancialOperation::setDate(int newDate) {
        date = newDate;
    }

    void FinancialOperation::setItem(string newItem) {
        item = newItem;
    }

    void FinancialOperation::setAmount(double newAmount) {
        amount = newAmount;
    }


    int FinancialOperation::getOperationId() {
        return operationId;
    }

    int FinancialOperation::getUserId() {
        return userId;
    }

    int FinancialOperation::getDate() {
        return date;
    }

    string FinancialOperation::getItem() {
        return item;
    }

    double FinancialOperation::getAmount() {
        return amount;
    }

