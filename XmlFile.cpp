#include "XmlFile.h"

XmlFile::XmlFile(string xmlFileName) : XML_FILE_NAME(xmlFileName) {
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
    bool emptyFile = false;

    file.open(XML_FILE_NAME.c_str(), ios::in);

    if (file.good()) {
        while(getline(file,tmpLine)) {
            allXmlFileInString += (tmpLine + "\n");
        }
        file.close();
    }
    if (allXmlFileInString.size() == 0) {
        allXmlFileInString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        emptyFile = true;
    }
    setXmlFileToStringSuccess = xml.SetDoc(allXmlFileInString);
    if (!setXmlFileToStringSuccess) {
        system("cls");
        cout << "Incorrect xml file. Failed to load!" << endl;
        errorReceived = xml.GetError();
        cout << "Error: " << errorReceived << endl;

        if ((errorReceived == ERR_NO_ROOT)) {
            cout << "The file is empty. Enter the name of root element: " << endl;
            cin.clear();
            cin.sync();
            getline(cin,rootElementName);
            xml.AddElem(rootElementName);
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

void XmlFile::addData(map<string, string> User) {
    int lastId;

    lastId = atoi(findLastId("User").c_str());
    if (lastId < 1)
        lastId = 0;
    xml.AddElem("User");
    xml.SetAttrib("userId", ++lastId);

    map<string, string>::iterator itr;
    for (itr = User.begin(); itr != User.end(); ++ itr) {
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

