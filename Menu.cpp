#include "Menu.h"


void Menu::show() {
    char choice;
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    while (true) {
        if (!personalBudget.isUserLoggedIn()) {
            choice = selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            choice = selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                //personalBudget.addIncome();
                break;
            case '2':
                //personalBudget.addExpense();
                break;
            case '3':
                //personalBudget.showBudgetForCurrentMonth();
                break;
            case '4':
                //personalBudget.showBudgetFromPreviousMonth();
                break;
            case '5':
                //personalBudget.showBudgetFromSelectedPeriod();
                break;
            case '6':
                personalBudget.changePasswordOfLoggedInUser();
                break;
            case '7':
                personalBudget.logoutOfUser();
                break;
            }
        }
    }

}

char Menu::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getSign();

    return choice;
}

char Menu::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "[ NIEDOSTEPNE ] 1. Dodaj przychod" << endl;
    cout << "[ NIEDOSTEPNE ] 2. Dodaj wydatek" << endl;
    cout << "[ NIEDOSTEPNE ] 3. Bilans z biezacego miesiaca" << endl;
    cout << "[ NIEDOSTEPNE ] 4. Bilans z poprzedniego miesiaca" << endl;
    cout << "[ NIEDOSTEPNE ] 5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getSign();

    return choice;
}

