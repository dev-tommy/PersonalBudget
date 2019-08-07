#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string login, password, name, surname;
    const string OBJECT_NAME = "USER";

public:
    void setUserId(int newUserId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getUserId();
    string getLogin();
    string getPasswrod();
    string getName();
    string getSurname();
};



#endif // USER_H
