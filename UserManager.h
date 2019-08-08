#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int idOfLoggedInUser;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist(string login);


public:
    UserManager(string fileNameWithUsers);
    int getIdOfLoggedInUser();
    bool isLoggedIn;
    void userRegistration();
    void userLogin();
    void listAllUsers();
    void logoutOfUser();
    void changePasswordOfLoggedInUser();
};

#endif // USERMANAGER_H
