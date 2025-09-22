#ifndef __DATE_HPP_
#define __DATE_HPP_

enum Format {ERROR, FORMAT_1, FORMAT_2, FORMAT_3};

const int MIN_DAY = 1;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_YEAR = 1;
const int FEB_DAYS = 28;
const int FEB_DAYS_LEAP = 29;
const int MAX_DAYS_LONG_MONTH = 31;
const int MAX_DAYS_SHORT_MONTH = 30;
const int LEAP_YEAR_DIV_BY_4 = 4;
const int LEAP_YEAR_DIV_BY_100 = 100;
const int LEAP_YEAR_DIV_BY_400 = 400;
const int FEB_MONTH = 2;
const int CENTURY_CUTOFF = 25;
const int BASE_CENTURY_1900 = 1900;
const int BASE_CENTURY_2000 = 2000;
const int SIZE = 100;
const int POSITION_0 = 0;
const int POSITION_1 = 1;
const int POSITION_2 = 2;
const int POSITION_3 = 3;
const int POSITION_4 = 4;
const int POSITION_5 = 5;
const int POSITION_6 = 6;
const int POSITION_7 = 7;
const int POSITION_8 = 8;
const int POSITION_9 = 9;
const int POWER = 10;

static const int daysPerMonth[MAX_MONTH] = {MAX_DAYS_LONG_MONTH, FEB_DAYS, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH,
        MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_LONG_MONTH,
        MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH};

class Date
{
public:
    static Format getFormat(const char* dateName);

private:
    static bool isRightFormat1(const char* dateName);
    static bool isRightFormat2(const char* dateName);
    static bool isRightFormat3(char* dateName);
    static bool isDigit(const int start, const int end, const char* name);
    static int getMonthInNumber(const char* monthName);
    static bool isLeapYear(const int year);
    static bool validDate(const int month, const int day, const int year);
    static int daysInMonth(const int month, const int year);
    static void errorMessage();
    static int getStringInNumber(const int start, const int end, const char* name);

public:
    Date();
    Date(const char* dateName);
    Date(int dayOfYears, int year);
    Date(const int month, const int day, const int year);
    Date(const char* monthName, const int day, const int year);
    Date(const Date& other);
    void setDate(const int month, const int day, const int year);
    void setMonth(const int month);
    void setDay(const int day);
    void setYear(const int year);
    int getMonth() const;
    int getDay()   const;
    int getYear()  const;
    void printNumeric() const;
    void printTextual() const;
    int getRealMonth()  const;
    
    void nextDay();

private:
    void dayOfMonth(int* day, int* year, int* month);
    void setFormat1(const char* dateName);
    void setFormat2(const char* dateName);
    void setFormat3(char* dateName);

private:
    int month_;
    int day_;
    int year_;
};

#endif /// __DATE_HPP_
