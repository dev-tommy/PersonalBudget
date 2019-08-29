#include "XmlFile.h"

XmlFile::XmlFile(string xmlFileName, string rootName) :
    XML_FILE_NAME(xmlFileName),
    ROOT_NAME(rootName) {
    loadXml();
}


XmlFile::~XmlFile() {
    saveXml();
}

void XmlFile::loadXml() {
    fstream file;
    string tmpLine="";
    string errorReceived="";
    string rootElementName="";
    string allXmlFileInString="";

    file.open(XML_FILE_NAME.c_str(), ios::in);

    if (file.good()) {
        while(getline(file,tmpLine)) {
            allXmlFileInString += (tmpLine + "\n");
        }
        file.close();
    }
    if (allXmlFileInString.size() == 0) {
        allXmlFileInString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    }
    setXmlFileToStringSuccess = xml.SetDoc(allXmlFileInString);
    if (!setXmlFileToStringSuccess) {
        system("cls");
        errorReceived = xml.GetError();
        cout << "Error loading XML file: " << errorReceived << endl;

        if ((errorReceived == ERR_NO_ROOT)) {
            cout << "The file " << XML_FILE_NAME << " is empty. Root element has been added: " << ROOT_NAME << endl;
            xml.AddElem(ROOT_NAME);
        }
        system("pause");
    }
}

void XmlFile::saveXml() {
    fstream file;
    string allXmlFileInString="";
    file.open(XML_FILE_NAME.c_str(), ios::out);

    if (file.good()) {
        allXmlFileInString = xml.GetDoc();
        file << allXmlFileInString;
        file.close();
    }
}



void XmlFile::showXmlByString() {
    string allXmlFileInString="";
    system("cls");
    cout << "Loaded contents of the xml file: " << endl;
    allXmlFileInString = xml.GetDoc();
    cout << allXmlFileInString << endl;
    system("pause");
}

void XmlFile::addData(string tagNameOfElementWithId, string attributeNameWithId, map<string, string> DataToWriteToFile) {
    int lastId;

    lastId = atoi(findLastId(tagNameOfElementWithId).c_str());
    if (lastId < 1)
        lastId = 0;
    xml.AddElem(tagNameOfElementWithId);
    xml.SetAttrib(attributeNameWithId, ++lastId);

    map<string, string>::iterator itr;
    for (itr = DataToWriteToFile.begin(); itr != DataToWriteToFile.end(); ++ itr) {
        xml.AddChildElem(itr->first, itr->second);
    }
}

void XmlFile::addDataWithId(string tagNameOfElementWithId, string attributeNameWithId, int id, map<string, string> DataToWriteToFile) {
    xml.ResetMainPos();
    xml.FindElem(); // find root or first tag
    xml.IntoElem();
    xml.AddElem(tagNameOfElementWithId);
    xml.SetAttrib(attributeNameWithId, id);

    map<string, string>::iterator itr;
    for (itr = DataToWriteToFile.begin(); itr != DataToWriteToFile.end(); ++ itr) {
        xml.AddChildElem(itr->first, itr->second);
    }
}

string XmlFile::findLastId(string tagNameOfElementWithId) {
    string lastId;
    xml.ResetMainPos();
    xml.FindElem(); // find root or first tag
    xml.IntoElem();

    while ( xml.FindElem(tagNameOfElementWithId)) {
        lastId = xml.GetAttrib(xml.GetAttribName(0));
    }
    return lastId;
}

