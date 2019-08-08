#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class FileWithUsers : public XmlFile {
    const string FILE_NAME_WITH_USER;
    User getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    FileWithUsers(string nazwaPlikuZUzytkownikami);
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void saveAllUsersToFile(vector<User> users);
};

#endif // FILEWITHUSERS_H
