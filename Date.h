#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h> // time
#include <cstdlib>
#include <string>
#include <sstream>

#include "AuxiliaryMethods.h"

using namespace std;

class Date {
    int date = 0;
    int day = 0, month = 0, year = 0;
    bool isCurrentDate = false;

    bool isLeapYear(unsigned int yearToCheck);
    bool isItInRange(int value, int minValue, int maxValue);
    bool isDateCorrect(string dateToCheck);

    int getNumberOfDaysOfTheMonth(int month, unsigned int year);
    int getDayFromDate(int date);
    int getMonthFromDate(int date);
    int getYearFromDate(int date);
    int getEndDate(int actualDate);
    int getActualDate();

    void setDate(string enteredDate);



public:
    Date();
    Date(string enteredDate);
    int getDate();
};

#endif // DATE_H
