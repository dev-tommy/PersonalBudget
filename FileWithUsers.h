#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class FileWithUsers{
    const string FILE_NAME_WITH_USERS;
    const string USERS_ROOT_NAME = "USERS";
    User getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    FileWithUsers(string fileNameWithUsers);
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void saveAllUsersToFile(vector<User> users);
    void saveEditedUser(User user);
};

#endif // FILEWITHUSERS_H
