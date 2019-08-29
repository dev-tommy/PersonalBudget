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
    static string convertDoubleToString(double number);
    static string replaceFirstLetterIntoLargeAndRestIntoSmall(string tekst);
    static string getNumber(string tekst, int pozycjaZnaku);
    static string getLineOfText();
    static string getDateAsString(int dateAsInt);
    static string findAndReplace(string text, string textToSearchFor, string replaceWith);

    static int convertStringToInt(string liczba);
    static int convertDateToInt(string date);
    static int findText(string text, string textToSearchFor);

    static double convertStringToDouble(string number);

    static char getSign();


};

#endif // AUXILIARYMETHODS_H
