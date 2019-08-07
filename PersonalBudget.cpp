#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses):
//    userManager(fileNameWithUsers),
    FILE_NAME_WITH_INCOMES(fileNameWithIncomes),
    FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
    //adresatMenedzer = NULL;
}
PersonalBudget::~PersonalBudget() {
    //delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

void PersonalBudget::userRegistration() {
    //userManager.userRegistration();
}

void PersonalBudget::userLogin() {
    //userManager.userLogin()
    //adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void PersonalBudget::changePasswordOfLoggedInUser() {
/*    if (userManager.isLoggedIn) {
        userManager.zmianaHaslaZalogowanegoUzytkownika();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    } */
}

void PersonalBudget::logoutOfUser() {
    //userManager.wylogowanieUzytkownika();
    //delete adresatMenedzer;
    //adresatMenedzer = NULL;
}


void PersonalBudget::addIncome() {
}

void PersonalBudget::addExpense() {
    //if (userManager.isLoggedIn) {

}


bool PersonalBudget::isUserLoggedIn() {
    //return userManager.isLoggedIn;
    return false;
}
