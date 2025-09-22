#ifndef __DATE_HPP_
#define __DATE_HPP_

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

class Date
{
public:
    Date(const int month = 1, const int day = 1, const int year = 2000);
    Date(const Date& other);
    void setDate(const int month, const int day, const int year);
    void setMonth(const int month);
    void setDay(const int day);
    void setYear(const int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void printDate() const;
    void nextDay();

private:
    bool isLeapYear(const int year) const;
    bool validDate(const int month, const int day, const int year) const;
    int daysInMonth(const int month, const int year) const;

private:
    int month_;
    int day_;
    int year_;
};

#endif /// __DATE_HPP_

