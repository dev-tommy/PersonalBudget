#include "Menu.h"

void Menu::show() {
    char choice;
//    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
//    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");
    while (true) {
        if (!budgetManager.isUserLoggedIn()) {
            choice = selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                //budgetManager.userRegistation();
                break;
            case '2':
                //budgetManager.userLogin();
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
                //budgetManager.addIncome();
                break;
            case '2':
                //budgetManager.addExpense();
                break;
            case '3':
                //budgetManager.showBudgetForCurrentMonth();
                break;
            case '4':
                //budgetManager.showBudgetFromPreviousMonth();
                break;
            case '5':
                //budgetManager.showBudgetFromSelectedPeriod();
                break;
            case '6':
                //budgetManager.changePasswordOfLoggedInUser();
                break;
            case '7':
                //budgetManager.logoutOfUser();
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
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getSign();

    return choice;
}

