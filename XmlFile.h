#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <map>

#include "Markup.h"

using namespace std;

class XmlFile : public CMarkup {
    const string XML_FILE_NAME;
    const string ERR_NO_ROOT = "no root element";

    bool setXmlFileToStringSuccess = false;

    void loadXml();
    void saveXml();

public:
    CMarkup xml;
    XmlFile(string xmlFileName);
    ~XmlFile();

    void showXmlByString();
    void addData(map<string, string> User);
    string findLastId(string tagNameOfElementWithId);

};

#endif // XMLFILE_H
