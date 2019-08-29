#include "FileWithUsers.h"

FileWithUsers::FileWithUsers(string fileNameWithUsers) : FILE_NAME_WITH_USERS(fileNameWithUsers) {

}


void FileWithUsers::addUserToFile(User user) {
    XmlFile xmlFileWithUsers(FILE_NAME_WITH_USERS, USERS_ROOT_NAME);
    map <string, string> dataToWriteToFile;
    dataToWriteToFile["login"] = user.getLogin();
    dataToWriteToFile["password"] = user.getPassword();
    dataToWriteToFile["name"] = user.getName();
    dataToWriteToFile["surname"] = user.getSurname();

    xmlFileWithUsers.addDataWithId("User", "userId", user.getUserId(), dataToWriteToFile);

}
vector<User> FileWithUsers::loadUsersFromFile() {
    XmlFile xmlFileWithUsers(FILE_NAME_WITH_USERS, USERS_ROOT_NAME);
    int lastId;
    vector<User> users;
    User userToRead;

    xmlFileWithUsers.xml.ResetMainPos();
    xmlFileWithUsers.xml.FindElem(); // find root or first tag

    //cout << xmlFileWithUsers.xml.GetTagName() << endl;

    xmlFileWithUsers.xml.IntoElem();

    while ( xmlFileWithUsers.xml.FindElem() ) {
        //cout << xmlFileWithUsers.xml.GetTagName() << endl;

        lastId = AuxiliaryMethods::convertStringToInt( xmlFileWithUsers.xml.GetAttrib( xmlFileWithUsers.xml.GetAttribName(0) ) );
        //cout << "lastId " << lastId << endl;

        userToRead.setUserId(lastId);
        xmlFileWithUsers.xml.FindChildElem("login");
        //cout << "login " << xmlFileWithUsers.xml.GetChildData() << endl;
        userToRead.setLogin( xmlFileWithUsers.xml.GetChildData() );
        xmlFileWithUsers.xml.ResetChildPos();

        xmlFileWithUsers.xml.FindChildElem("password");
        //cout << "password " << xmlFileWithUsers.xml.GetChildData() << endl;
        userToRead.setPassword( xmlFileWithUsers.xml.GetChildData() );
        xmlFileWithUsers.xml.ResetChildPos();

        xmlFileWithUsers.xml.FindChildElem("name");
        //cout << "name " << xmlFileWithUsers.xml.GetChildData() << endl;
        userToRead.setName( xmlFileWithUsers.xml.GetChildData() );
        xmlFileWithUsers.xml.ResetChildPos();

        xmlFileWithUsers.xml.FindChildElem("surname");
        //cout << "surname " << xmlFileWithUsers.xml.GetChildData() << endl;
        userToRead.setSurname( xmlFileWithUsers.xml.GetChildData() );
        xmlFileWithUsers.xml.ResetChildPos();
        users.push_back(userToRead);
    }
    return users;
}

void FileWithUsers::saveAllUsersToFile(vector<User> users) {
    XmlFile xmlFileWithUsers(FILE_NAME_WITH_USERS, USERS_ROOT_NAME);

    xmlFileWithUsers.xml.ResetMainPos();
    xmlFileWithUsers.xml.FindElem(); // find root or first tag
    xmlFileWithUsers.xml.IntoElem();

    while (xmlFileWithUsers.xml.FindElem()) {

    }
}

void FileWithUsers::saveEditedUser(User userForSave) {
    XmlFile xmlFileWithUsers(FILE_NAME_WITH_USERS, USERS_ROOT_NAME);
    int userId;
    xmlFileWithUsers.xml.ResetMainPos();
    xmlFileWithUsers.xml.FindElem(); // find root or first tag
    xmlFileWithUsers.xml.IntoElem();

    while (xmlFileWithUsers.xml.FindElem()) {
        userId = AuxiliaryMethods::convertStringToInt( xmlFileWithUsers.xml.GetAttrib( xmlFileWithUsers.xml.GetAttribName(0) ) );
        if (userId == userForSave.getUserId()) {
            xmlFileWithUsers.xml.FindChildElem("password");
            xmlFileWithUsers.xml.SetChildData(userForSave.getPassword());
        }
    }


}
