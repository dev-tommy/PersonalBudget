#include "User.h"

    void User::setUserId(int newUserId) {
        userId = newUserId;
    }

    void User::setLogin(string newLogin) {
        login = newLogin;
    }

    void User::setPassword(string newPassword) {
        password = newPassword;
    }

    void User::setName(string newName) {
        name = newName;
    }

    void User::setSurname(string newSurname) {
        surname = newSurname;
    }

    int User::getUserId() {
        return userId;
    }

    string User::getLogin() {
        return login;
    }

    string User::getPasswrod() {
        return password;
    }

    string User::getName() {
        return name;
    }

    string User::getSurname() {
        return surname;
    }
