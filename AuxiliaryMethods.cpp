#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number) {
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    ss.clear();

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
    const char* str = number.c_str();
    float v = atof(str);
    std::cout << std::setprecision(2) << std::fixed << v << std::endl;
    return v;
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

string AuxiliaryMethods::getDateAsString(int dateAsInt) {
    string dateAsString = "";
    dateAsString = convertIntToString(dateAsInt);
    dateAsString.insert(6,"-");
    dateAsString.insert(4,"-");
    return dateAsString;
}
