#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int liczba);
    static string replaceFirstLetterIntoLargeAndRestIntoSmall(string tekst);
    static string getNumber(string tekst, int pozycjaZnaku);
    static int convertStringToInt(string liczba);
    static char getSign();
    static string getLineOfText();
};

#endif // AUXILIARYMETHODS_H
