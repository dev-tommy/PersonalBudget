#include "FileWithFinancialOperations.h"

FileWithFinancialOperations::FileWithFinancialOperations(string fileNameWithOperations) : FILE_NAME_WITH_OPERATIONS(fileNameWithOperations) {

}

void FileWithFinancialOperations::addOperationToFile(FinancialOperation operation) {
    XmlFile xmlFileWithFinancialOperations(FILE_NAME_WITH_OPERATIONS, OPERATIONS_ROOT_NAME);
    map <string, string> dataToWriteToFile;
    dataToWriteToFile["userId"] = AuxiliaryMethods::convertIntToString(operation.getUserId());
    dataToWriteToFile["date"] = AuxiliaryMethods::getDateAsString(operation.getDate()); // dodac myslniki: rrrr-mm-dd
    dataToWriteToFile["item"] = operation.getItem();
    dataToWriteToFile["amount"] = AuxiliaryMethods::convertDoubleToString(operation.getAmount());
    xmlFileWithFinancialOperations.addDataWithId("Operation", "operationId", operation.getOperationId(), dataToWriteToFile);
    lastIdOfOperation++;
}

vector<FinancialOperation> FileWithFinancialOperations::loadFinancialOperationsFromFile(int idOfLoggedInUser) {
    XmlFile xmlFileWithFinancialOperations(FILE_NAME_WITH_OPERATIONS, OPERATIONS_ROOT_NAME);
    int readedUserId;
    vector<FinancialOperation> operations;
    FinancialOperation operationToRead;

    lastIdOfOperation = 0;

    xmlFileWithFinancialOperations.xml.ResetMainPos();
    xmlFileWithFinancialOperations.xml.FindElem(); // find root or first tag
    xmlFileWithFinancialOperations.xml.IntoElem(); // go inside root

    operationToRead.setUserId(idOfLoggedInUser);

    while ( xmlFileWithFinancialOperations.xml.FindElem() ) {
        lastIdOfOperation = AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetAttrib( xmlFileWithFinancialOperations.xml.GetAttribName(0) ) );
        operationToRead.setOperationId(lastIdOfOperation);

        xmlFileWithFinancialOperations.xml.FindChildElem("userId");
        readedUserId = AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetChildData() );
        if (idOfLoggedInUser != readedUserId) {
            continue;
        }
        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("amount");
        operationToRead.setAmount( AuxiliaryMethods::convertStringToDouble( xmlFileWithFinancialOperations.xml.GetChildData() ) );
        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("item");
        operationToRead.setItem( xmlFileWithFinancialOperations.xml.GetChildData() );
        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("date");
        operationToRead.setDate( AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetChildData() ) );
        xmlFileWithFinancialOperations.xml.ResetChildPos();
        operations.push_back(operationToRead);
    }
    return operations;
}

int FileWithFinancialOperations::getLastIdOfOperation() {
    return lastIdOfOperation;
}

