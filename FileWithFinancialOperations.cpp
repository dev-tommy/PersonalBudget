#include "FileWithFinancialOperations.h"

FileWithFinancialOperations::FileWithFinancialOperations(string fileNameWithOperations) : FILE_NAME_WITH_OPERATIONS(fileNameWithOperations) {

}

void FileWithFinancialOperations::addOperationToFile(FinancialOperation operation) {
    XmlFile xmlFileWithFinancialOperations(FILE_NAME_WITH_OPERATIONS, OPERATIONS_ROOT_NAME);
    map <string, string> dataToWriteToFile;
    dataToWriteToFile["userId"] = operation.getUserId();
    dataToWriteToFile["date"] = operation.getDate();
    dataToWriteToFile["item"] = operation.getItem();
    dataToWriteToFile["amount"] = operation.getAmount();
    xmlFileWithFinancialOperations.addDataWithId("Operation", "operationId", operation.getOperationId(), dataToWriteToFile);

}

