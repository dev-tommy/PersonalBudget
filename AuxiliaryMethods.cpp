#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::replaceFirstLetterIntoLargeAndRestIntoSmall(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

string AuxiliaryMethods::getNumber(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int AuxiliaryMethods::convertStringToInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

float AuxiliaryMethods::convertStringToFloat(string number) {
        float floatNumber = 0;





        return floatNumber;
}

char AuxiliaryMethods::getSign() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string AuxiliaryMethods::getLineOfText() {
    string wejscie = "";
    cin.clear();
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}
