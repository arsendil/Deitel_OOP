#include "../headers/Date.hpp"
#include <iostream>
#include <cassert>
#include <cstring>
#include <ctime>

static const char* mountNames[MAX_MONTH] = {"January", "February", "March","April",
                                            "May", "June", "July", "August", 
                                            "September","October", "November", "December"};


Date::Date(const char* dateName)
{
    char temp[SIZE];
    std::strcpy(temp, dateName);
    switch (getFormat(temp)) {
    case FORMAT_1: setFormat1(temp);  break;
    case FORMAT_2: setFormat2(temp);  break;
    case FORMAT_3: setFormat3(temp);  break;
    case ERROR   : errorMessage()  ; return;
    default:       assert(0);
    }
}

Date::Date()
{}

Format
Date::getFormat(const char* dateName)
{
    char temp[SIZE];
    std::strcpy(temp, dateName);
    if (isRightFormat3(temp)) {
        return FORMAT_3;
    }
    if (isRightFormat2(temp)) {
        return FORMAT_2;
    }
    if (isRightFormat1(temp)) {
        return FORMAT_1;
    }
    return ERROR;
}

Date::Date(const char* monthName, const int day, const int year)
{
    const int month = getMonthInNumber(monthName);
    assert(-1 != month);
    setDate(month, day, year);
}

Date::Date(int dayOfYears, int year)
{
    int month = 0;
    dayOfMonth(&dayOfYears, &year, &month);
    setDate(month, dayOfYears, year);
}

Date::Date(const int month, const int day, const int year)
{
    setDate(month, day, year);
}

Date::Date(const Date& other)
{
    setDate(other.getMonth(), other.getDay(), other.getYear());
}

void
Date::setDate(const int month, const int day, const int year)
{
    assert(validDate(month, day, year));
    setMonth(month);
    setYear(year);
    setDay(day);
}

void
Date::setMonth(const int month)
{
    assert(month >= MIN_MONTH && month <= MAX_MONTH);
    month_ = month; 
}

void
Date::setDay(const int day)
{   
    assert(day >= MIN_DAY && day <= daysInMonth(month_, year_));
    day_ = day;
}

void
Date::setYear(const int year)
{
    assert(year >= MIN_YEAR);
    year_ = year;
}

int
Date::getMonth() const
{
    return month_;
}

int
Date::getDay() const
{
    return day_;
}

int
Date::getYear() const
{
    return year_;
}

void
Date::nextDay()
{
    ++day_;
    if (day_ > daysInMonth(month_, year_)) {
        day_ = MIN_DAY;
        ++month_;
        if (month_ > MAX_MONTH) {
            month_ = MIN_MONTH;
            ++year_;
        }
    }
}

bool
Date::isLeapYear(const int year)
{
    return (0 == year % LEAP_YEAR_DIV_BY_4 && 0 != year % LEAP_YEAR_DIV_BY_100) || (0 == year % LEAP_YEAR_DIV_BY_400);
}

int
Date::daysInMonth(const int month, const int year)
{
    if (FEB_MONTH == month && isLeapYear(year)) {
        return FEB_DAYS_LEAP;
    }
    return daysPerMonth[month - 1];
}

bool
Date::validDate(const int month, const int day, const int year)
{
    return year >= MIN_YEAR && month >= MIN_MONTH && month <= MAX_MONTH &&
           day >= MIN_DAY && day <= daysInMonth(month, year);
}

void
Date::dayOfMonth(int* day, int* year, int* month)
{
    *month = 0;
    while (*day > daysInMonth(*month, *year)) {
        *day -= daysInMonth(*month, *year);
        ++(*month);
    }
}

int
Date::getMonthInNumber(const char* monthName)
{
    for (int i = 0; i < MAX_MONTH; ++i) {
        if (0 == std::strcmp(monthName, mountNames[i])) {
            return i + 1;
        }
    }
    return -1;   
}

bool
Date::isRightFormat1(const char* dateName)
{
    return (isDigit(POSITION_0, POSITION_2, dateName) && ' ' == dateName[POSITION_3] && isDigit(POSITION_4, POSITION_7, dateName));
}

bool
Date::isRightFormat2(const char* dateName)
{
    return (isDigit(POSITION_0, POSITION_1, dateName) && '/' == dateName[POSITION_2] &&
            isDigit(POSITION_3, POSITION_4, dateName) && '/' == dateName[POSITION_5] &&
            isDigit(POSITION_6, POSITION_7, dateName));
}

bool
Date::isRightFormat3(char* dateName)
{
    const int lengthString = std::strlen(dateName);
    return (isDigit(lengthString - POSITION_4, lengthString - 1, dateName) &&
            dateName[lengthString - POSITION_5] == ' ' &&
            dateName[lengthString - POSITION_6] == ',' &&
            isDigit(lengthString - POSITION_7, lengthString - POSITION_8, dateName) &&
            dateName[lengthString - POSITION_9] && getMonthInNumber(std::strtok(dateName, " ")) != -1);
}

bool
Date::isDigit(const int start, const int end, const char* name)
{
    for (int i = start; i <= end; ++i) {
        if (!std::isdigit(name[i])) {
            return false;
        }
    }
    return true;
}

int
Date::getStringInNumber(const int start, const int end, const char* name)
{
    int number1 = 0;
    int power = 1;

    for (int i = end; i >= start; --i) {
        number1 += power * (name[i] - '0');
        power *= POWER;
    }
    return number1;
}

void
Date::setFormat1(const char* dateName)
{
    int dayOfYears = getStringInNumber(POSITION_0, POSITION_2, dateName);
    int year = getStringInNumber(POSITION_4, POSITION_7, dateName);
    int month = 0;
    dayOfMonth(&dayOfYears, &year, &month);
    setDate(month, dayOfYears, year);
}
  
void
Date::setFormat2(const char* dateName)
{
    const int month = getStringInNumber(POSITION_0, POSITION_1, dateName);
    const int day = getStringInNumber(POSITION_3, POSITION_4, dateName);
    const int year = getStringInNumber(POSITION_6, POSITION_7, dateName);
    setDate(month, day, year); 
}

void
Date::setFormat3(char* dateName)
{
    const int lengthString = std::strlen(dateName);
    const int year = getStringInNumber(lengthString - POSITION_4, lengthString - 1, dateName);
    const int day = getStringInNumber(lengthString - POSITION_8, lengthString - POSITION_7, dateName);
    const int month = getMonthInNumber(std::strtok(dateName, " "));
    setDate(month, day, year);

}

int
Date::getRealMonth() const
{
    std::time_t time = std::time(0); 
    std::tm* now = std::localtime(&time);
    return now->tm_mon + 1;
}

void
Date::printNumeric() const
{
    std::cout << month_ << '/' << day_ << '/' << year_ << std::endl;
}

void
Date::printTextual() const
{
    std::cout << mountNames[month_ - 1] << ' ' << day_ << ", " << year_ << std::endl;
}

void
Date::errorMessage()
{
    std::cout << "Error 1: Invalid format!" << std::endl;
}
