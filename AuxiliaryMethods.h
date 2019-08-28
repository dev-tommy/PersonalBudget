#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int liczba);
    static string convertFloatToString(float number);
    static string replaceFirstLetterIntoLargeAndRestIntoSmall(string tekst);
    static string getNumber(string tekst, int pozycjaZnaku);
    static int convertStringToInt(string liczba);
    static float convertStringToFloat(string number);
    static char getSign();
    static string getLineOfText();
    static string getDateAsString(int dateAsInt);
    static string findAndReplace(string text, string textToSearchFor, string replaceWith);
};

#endif // AUXILIARYMETHODS_H
