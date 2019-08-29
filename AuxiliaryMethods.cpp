#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    stringstream ss;
    string str;
    ss << setprecision(2) << fixed << number;
    ss >> str;
    //ss.clear();

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

double AuxiliaryMethods::convertStringToDouble(string number) {
    const char* str = number.c_str();
    double v = atof(str);
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
    string dateAsString = "ErrSize";
    if ((dateAsInt > 10000000) && (dateAsInt < 99991231)) {
        dateAsString = convertIntToString(dateAsInt);
        dateAsString.insert(6,"-");
        dateAsString.insert(4,"-");
    }
    return dateAsString;
}

int AuxiliaryMethods::convertDateToInt(string date) {
    int convertedDate = 0;
    if (date.size() == 10) {
        date.erase(7,1);
        date.erase(4,1);
        convertedDate = AuxiliaryMethods::convertStringToInt(date);
    }
    return convertedDate;
}

string AuxiliaryMethods::findAndReplace(string text, string textToSearchFor, string replaceWith) {
    int positionFound;
    do {
        positionFound = text.find( textToSearchFor );
        if( positionFound != string::npos ) {
            text.erase(positionFound, textToSearchFor.length());
            text.insert(positionFound, replaceWith);
        }
    } while( positionFound != string::npos );
    return text;
}

int AuxiliaryMethods::findText(string text, string textToSearchFor) {

}

int AuxiliaryMethods::divideTheTable(vector<FinancialOperation> &operations, int p, int r)
{
    FinancialOperation tmpOperation;
    int x = operations[p].getDate();
    int i = p, j = r;
    while (true)
    {
        while (operations[j].getDate() > x)
            j--;
        while (operations[i].getDate() < x)
            i++;
        if (i < j)
        {
            tmpOperation = operations[i];
            operations[i] = operations[j];
            operations[j] = tmpOperation;
            i++;
            j--;
        }
        else
            return j;
    }
}

void AuxiliaryMethods::quickSortVector(vector<FinancialOperation> &operations, int p, int r)
{
    int q;
    r--;
    if (p < r)
    {
        q = divideTheTable(operations,p,r);
        quickSortVector(operations, p, q);
        quickSortVector(operations, q+1, r);
    }
}
