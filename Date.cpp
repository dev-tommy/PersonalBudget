#include "Date.h"

Date::Date() {
    date = getActualDate();
    isCurrentDate = true;
}

Date::Date(string enteredDate) {
    setDate(enteredDate);
}

Date::Date(string enteredDate, bool checked = false) {
    if (checked) {
        date = enteredDate;
        day = getDayFromDate(enteredDate);
        month = getMonthFromDate(enteredDate);
        year = getYearFromDate(enteredDate);
    } else {
        setDate(enteredDate);
    }
}

bool Date::operator < ( Date const &secondDate ) {
    if (((this->year) > secondDate.year)) {
        return false;
    }
    if (((this->year) < secondDate.year)) {
        return true;
    }
    if ((this->month > secondDate.month)) {
        return false;
    }
    if ((this->month < secondDate.month)) {
        return true;
    }
    if ((this->day < secondDate.day)) {
        return true;
    } else {
        return false;
    }
}


string Date::getActualDate() {
    char buffer [11]; //yyyy-mm-dd0
    time_t rawTime;
    time(&rawTime); // set actual time to rawTime
    const tm *actualTime = localtime(&rawTime);
    strftime(buffer,sizeof(buffer),"%Y-%m-%d",actualTime);
    day = actualTime->tm_mday;
    month = actualTime->tm_mon+1;  // 0-11 -> +1
    year = actualTime->tm_year + 1900;    // +1900

    return buffer;
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
        system("cls");
        cout << "Numer miesiaca poza zakresem <1,12>. Podaj ponownie: ";
        cin >> month;
    }

    numberOfDaysOfTheMonth = daysOfMonth[month-1];
    if ((month == 2) && isLeapYear(year)) {
        numberOfDaysOfTheMonth++;
    }
    return numberOfDaysOfTheMonth;
}


bool Date::isDateCorrect(string dateToCheck) {
    bool correctDate = true;
    string dateToBeDivaded = dateToCheck;
    Date actualDate;
    Date startDate("2000-01-01", true);
    //0123456789
    //2000-12-31
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

    Date testDate(dateToCheck, true);

    if ( !isItInRange(testDate.month, 1, 12) ) {
        cout << "Miesiac " << testDate.month << " poza zakresem." << endl;
        return false;
    }

    if ( !isItInRange(testDate.day, 1, getNumberOfDaysOfTheMonth(testDate.month, testDate.year)) ) {
        cout << "Dany dzien: " << testDate.day << " nie wystepuje w miesiacu: " << testDate.month << endl;
        return false;
    }

    if (actualDate < testDate) {
        cout << "Wprowadzona data " << testDate.date << " przekracza date dzisiejsza " << actualDate.date << endl;
        return false;
    }

    if (testDate < startDate) {
        cout << "Wprowadzona data " << testDate.date << " jest mniejsza od daty minimalnej " << startDate.date << endl;
        return false;
    }

    return true;
}

int Date::getDayFromDate(string dateToBeDivaded) {
    return (dateToBeDivaded[8]-'0')*10 + (dateToBeDivaded[9]-'0');
}

int Date::getMonthFromDate(string dateToBeDivaded) {
    return (dateToBeDivaded[5]-'0')*10 + (dateToBeDivaded[6]-'0');
}

int Date::getYearFromDate(string dateToBeDivaded) {
    return (dateToBeDivaded[0]-'0')*1000 + (dateToBeDivaded[1]-'0')*100 + (dateToBeDivaded[2]-'0')*10 + (dateToBeDivaded[3]-'0');
}

string Date::getDate() {
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
    system("cls");
    date = enteredDate;  // 2000-12-31
}
