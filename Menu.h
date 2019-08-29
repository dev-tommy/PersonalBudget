#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Menu {
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

public:
    void show();
};

#endif // MENU_H
