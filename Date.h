#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h> // time
#include <cstdlib>
#include <string>

using namespace std;

class Date {
    string date = "";
    int day = 0, month = 0, year = 0;
    bool isCurrentDate = false;

    bool isLeapYear(unsigned int yearToCheck);
    bool isItInRange(int value, int minValue, int maxValue);
    bool operator< (Date const &secondDate);
    bool isDateCorrect(string dateToCheck);

    int getNumberOfDaysOfTheMonth(int month, unsigned int year);
    int getDayFromDate(string dateToBeDivaded);
    int getMonthFromDate(string dateToBeDivaded);
    int getYearFromDate(string dateToBeDivaded);

    void setDate(string enteredDate);

    string getActualDate();
    string getDate();

public:
    Date();
    Date(string enteredDate);
    Date(string enteredDate, bool checked);

};

#endif // DATE_H
