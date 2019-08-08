#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <map>

#include "Markup.h"

using namespace std;

class XmlFile : public CMarkup {
    const string XML_FILE_NAME;
    const string ROOT_NAME;
    const string ERR_NO_ROOT = "no root element";

    bool setXmlFileToStringSuccess = false;

    void loadXml();
    void saveXml();

public:
    CMarkup xml;
    XmlFile(string xmlFileName, string rootName);
    ~XmlFile();

    void showXmlByString();
    void addData(string tagNameOfElementWithId, string attributeNameWithId, map<string, string> dataToWriteToFile);
    void addDataWithId(string tagNameOfElementWithId, string attributeNameWithId, int id, map<string, string> dataToWriteToFile);
    void addElem(string tagNameOfElement);
    string findLastId(string tagNameOfElementWithId);

};

#endif // XMLFILE_H
