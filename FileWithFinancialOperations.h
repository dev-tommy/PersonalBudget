#ifndef FILEWITHFINANCIALOPERATIONS_H
#define FILEWITHFINANCIALOPERATIONS_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "FinancialOperation.h"

using namespace std;

class FileWithFinancialOperations {
    int lastIdOfOperation;
    const string FILE_NAME_WITH_OPERATIONS;
    const string OPERATIONS_ROOT_NAME = "FINANCIAL_OPERATIONS";

public:
    FileWithFinancialOperations(string fileNameWithOperations);
    void addOperationToFile(FinancialOperation operation);
    vector<FinancialOperation> loadFinancialOperationsFromFile(int idOfLoggedInUser);
    int getLastIdOfOperation();
};


#endif // FILEWITHFINANCIALOPERATIONS_H
