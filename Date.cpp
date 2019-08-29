#include "Date.h"

Date::Date() {
    date = getActualDate();
    isCurrentDate = true;
}

Date::Date(string enteredDate) {
    setDate(enteredDate);
}

int Date::getActualDate() {
    int date = 0;
    time_t rawTime;
    time(&rawTime); // set actual time to rawTime
    const tm *actualTime = localtime(&rawTime);
    day = actualTime->tm_mday;
    month = actualTime->tm_mon+1;  // 0-11 -> +1
    year = actualTime->tm_year + 1900;    // +1900

    date = year*10000+month*100+day;
    return date;
}

bool Date::isLeapYear(unsigned int yearToCheck) {
    if (yearToCheck % 4 == 0) {
        return true;
    }
    return false;
}

bool Date::isItInRange(int value, int minValue, int maxValue) {
    if ( (value >= minValue) && (value<=maxValue) ) {
        return true;
    }
    return false;
}

int Date::getNumberOfDaysOfTheMonth(int month, unsigned int year) {
    int numberOfDaysOfTheMonth = 0;
    int daysOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while ( !isItInRange(month, 1, 12) ) {
        cout << "Numer miesiaca poza zakresem <1,12>. Podaj ponownie: ";
        cin >> month;
    }

    numberOfDaysOfTheMonth = daysOfMonth[month-1];
    if ((month == 2) && isLeapYear(year)) {
        numberOfDaysOfTheMonth++;
    }
    return numberOfDaysOfTheMonth;
}

int Date::getEndDate(int actualDate) {
    int endDate = actualDate;
    endDate /= 100;
    endDate = endDate*100 + getNumberOfDaysOfTheMonth((endDate % 100), (endDate / 100));
    return endDate;
}

int Date::getStartDate(int actualDate) {
    int startDate = actualDate;
    startDate /= 100;
    startDate = startDate * 100 + 1;
    return startDate;
}

bool Date::isDateCorrect(string dateToCheck) {
    string dateToBeDivaded = dateToCheck;
    int actualDate = getActualDate();
    int startDate = 20000101;
    int testDate = 0;
    int endDate;

    if (dateToBeDivaded.length() != 10) {
        cout << "Nieprawidlowa dlugosc. " << endl;
        return false;
    }
    if ( (dateToBeDivaded[4] != '-') || (dateToBeDivaded[7] != '-') )  {
        cout << "Nieprawidlowa znak rozdzielajacy date. " << endl;
        return false;
    } else {
        dateToBeDivaded.erase(7,1);
        dateToBeDivaded.erase(4,1);
    }
    for (int i=0; i<dateToBeDivaded.length(); i++) {
        if ((dateToBeDivaded[i]<'0') || (dateToBeDivaded[i]>'9')) {
            cout << "Data powinna zawierac tylko cyfry. " << endl;
            return false;
        }
    }

    testDate = AuxiliaryMethods::convertStringToInt(dateToBeDivaded);

    day = testDate % 100;
    testDate /= 100;
    month = testDate % 100;
    testDate /= 100;
    year = testDate;

    if ( !isItInRange(month, 1, 12) ) {
        cout << "Miesiac " << month << " poza zakresem." << endl;
        return false;
    }

    if ( !isItInRange(day, 1, getNumberOfDaysOfTheMonth(month, year)) ) {
        cout << "Dany dzien: " << day << " nie wystepuje w miesiacu: " << month << endl;
        return false;
    }

    testDate = AuxiliaryMethods::convertStringToInt(dateToBeDivaded);
    endDate = getEndDate(actualDate);


    if (endDate < testDate) {
        cout << "Wprowadzona data: " << AuxiliaryMethods::getDateAsString(testDate) << " jest pozniejsza od daty: " << AuxiliaryMethods::getDateAsString(endDate) << endl;
        return false;
    }

    if (testDate < startDate) {
        cout << "Wprowadzona data: " << AuxiliaryMethods::getDateAsString(testDate) << " jest wczesniejsza od daty: " << AuxiliaryMethods::getDateAsString(startDate) << endl;
        return false;
    }
    date = testDate;
    return true;
}

int Date::getDayFromDate(int date) {
    return (date % 100);
}

int Date::getMonthFromDate(int date) {
    date /= 100;
    return (date % 100);
}

int Date::getYearFromDate(int date) {
    return (date /= 10000);
}

int Date::getDate() {
    if (isCurrentDate) {
        date = getActualDate();
    }
    return date;
}



void Date::setDate(string enteredDate) {
    isCurrentDate = false;
    while (!isDateCorrect(enteredDate)) {
        cout << "Podaj prawidlowa date (w formacie: rrrr-mm-dd): ";
        cin >> enteredDate;
    }
}
