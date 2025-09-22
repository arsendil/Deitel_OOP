#include "headers/Date.hpp"
#include <iostream>
#include <cassert>

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
    setDay(day);
    setYear(year);
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
Date::printDate() const
{
    std::cout << month_ << '/' << day_ << '/' << year_ << std::endl;
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
Date::isLeapYear(const int year) const
{
    return (0 == year % LEAP_YEAR_DIV_BY_4 && 0 != year % LEAP_YEAR_DIV_BY_100) || (0 == year % LEAP_YEAR_DIV_BY_400);
}

int
Date::daysInMonth(const int month, const int year) const
{
    static const int daysPerMonth[MAX_MONTH] = {MAX_DAYS_LONG_MONTH, FEB_DAYS, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH,
        MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_LONG_MONTH,
        MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH};
    if (FEB_MONTH == month && isLeapYear(year)) {
        return FEB_DAYS_LEAP;
    }
    return daysPerMonth[month - 1];
}

bool
Date::validDate(const int month, const int day, const int year) const
{
    return year >= MIN_YEAR && month >= MIN_MONTH && month <= MAX_MONTH &&
           day >= MIN_DAY && day <= daysInMonth(month, year);
}

