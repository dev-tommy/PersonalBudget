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
}

vector<FinancialOperation> FileWithFinancialOperations::loadFinancialOperationsFromFile(int idOfLoggedInUser) {
    XmlFile xmlFileWithFinancialOperations(FILE_NAME_WITH_OPERATIONS, OPERATIONS_ROOT_NAME);
    int lastId, readedUserId;
    vector<FinancialOperation> operations;
    FinancialOperation operationToRead;

    xmlFileWithFinancialOperations.xml.ResetMainPos();
    xmlFileWithFinancialOperations.xml.FindElem(); // find root or first tag

    //cout << xmlFileWithFinancialOperations.GetTagName() << endl;

    xmlFileWithFinancialOperations.xml.IntoElem();

    while ( xmlFileWithFinancialOperations.xml.FindElem() ) {
        //cout << xmlFileWithFinancialOperations.xml.GetTagName() << endl;

        operationToRead.setUserId(idOfLoggedInUser);
        lastId = AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetAttrib( xmlFileWithFinancialOperations.xml.GetAttribName(0) ) );
        //cout << "lastId " << lastId << endl;

        operationToRead.setOperationId(lastId);
        xmlFileWithFinancialOperations.xml.FindChildElem("userId");
        //cout << "login " << xmlFileWithFinancialOperations.xml.GetChildData() << endl;

        readedUserId = AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetChildData() );
        if (idOfLoggedInUser != readedUserId) {
            continue;
        }

        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("amount");
        //cout << "password " << xmlFileWithFinancialOperations.xml.GetChildData() << endl;
        operationToRead.setAmount( AuxiliaryMethods::convertStringToDouble( xmlFileWithFinancialOperations.xml.GetChildData() ) );
        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("item");
        //cout << "name " << xmlFileWithFinancialOperations.xml.GetChildData() << endl;
        operationToRead.setItem( xmlFileWithFinancialOperations.xml.GetChildData() );
        xmlFileWithFinancialOperations.xml.ResetChildPos();

        xmlFileWithFinancialOperations.xml.FindChildElem("date");
        //cout << "surname " << xmlFileWithFinancialOperations.xml.GetChildData() << endl;
        operationToRead.setDate( AuxiliaryMethods::convertStringToInt( xmlFileWithFinancialOperations.xml.GetChildData() ) );
        xmlFileWithFinancialOperations.xml.ResetChildPos();
        operations.push_back(operationToRead);
    }
    return operations;
}

