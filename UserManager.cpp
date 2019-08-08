#include "UserManager.h"

UserManager::UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
    users = fileWithUsers.loadUsersFromFile();
    idOfLoggedInUser = 0;
    isLoggedIn = false;
}

void UserManager::userRegistration() {

    system("cls");
    cout << ">>> REJESTRACJA UZYTKOWNIKA <<<" << endl << endl;
    User user = enterNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

void UserManager::listAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl << endl;
    }
}

User UserManager::enterNewUserData() {
    User user;
    string login, password;

    user.setUserId(getIdOfNewUser());
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

bool UserManager::doesLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::userLogin() {
    string login, password;
    idOfLoggedInUser = 0;
    isLoggedIn = false;

    system("cls");
    cout << ">>> LOGOWANIE UZYTKOWNIKA <<<" << endl << endl;
    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                cin >> password;

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    isLoggedIn = true;
                    system("pause");
                    idOfLoggedInUser = users[i].getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

void UserManager::changePasswordOfLoggedInUser() {
    string newPassword = "";

    system("cls");
    cout << ">>> ZMIANA HASLA UZYTKOWNIKA <<<" << endl << endl;
    if (isLoggedIn) {
        cout << "Podaj nowe haslo: ";
        cin >> newPassword;

        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUserId() == idOfLoggedInUser) {
                users[i].setPassword(newPassword);
                cout << endl << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToFile(users);
    } else {
        cout << "Uzytkownik nie zalogowany!" << endl;
        system("pause");
    }
}

void UserManager::logoutOfUser() {
    if (isLoggedIn) {
        idOfLoggedInUser = 0;
        isLoggedIn = false;
        cout << "Uzytkownik wylogowany!" << endl;
        system("pause");
    } else {
        cout << "Uzytkownik nie był zalogowany!" << endl;
    }
}

int UserManager::getIdOfLoggedInUser() {
    return idOfLoggedInUser;
}

