#include "../headers/DateAndTime.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>

DateAndTime::DateAndTime(const int month, const int day, const int year, const int hour, const int minute, const int second)
{
    setDateTime(month, day, year, hour, minute, second);
}

DateAndTime::DateAndTime(const DateAndTime& other)
{
    setDateTime(other.getMonth(), other.getDay(), other.getYear(), other.getHour(), other.getMinute(), other.getSecond());
}

void
DateAndTime::setHour(const int hour)
{
    assert(hour >= MIN_TIME && hour < HOURS_IN_DAY);
    hour_ = hour;
}

void
DateAndTime::setMinute(const int minute)
{
    assert(minute >= MIN_TIME && minute < MINUTES_IN_HOUR);
    minute_ = minute;
}

void
DateAndTime::setSecond(const int second)
{
    assert(second >= MIN_TIME && second < SECONDS_IN_MINUTE);
    second_ = second;
}

void
DateAndTime::setMonth(const int month)
{
    assert(month >= MIN_MONTH && month <= MAX_MONTH);
    month_ = month;
}

void
DateAndTime::setYear(const int year)
{
    assert(year >= MIN_YEAR);
    year_ = year;
}

void
DateAndTime::setDay(const int day)
{
    assert(day >= MIN_DAY && day <= daysInMonth(month_, year_));
    day_ = day;
}

void
DateAndTime::setTime(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void
DateAndTime::setDate(const int month, const int day, const int year)
{
    assert(validDate(month, day, year));
    setMonth(month);
    setDay(day);
    setYear(year);
}

void
DateAndTime::setDateTime(const int month, const int day, const int year, const int hour, const int minute, const int second)
{
    setDate(month, day, year);
    setTime(hour, minute, second);
}

int
DateAndTime::getHour() const
{
    return hour_;
}

int
DateAndTime::getMinute() const
{
    return minute_;
}

int
DateAndTime::getSecond() const
{
    return second_;
}

int
DateAndTime::getDay() const
{
    return day_;
}

int
DateAndTime::getMonth() const
{
    return month_;
}

int
DateAndTime::getYear() const
{
    return year_;
}

void
DateAndTime::tick()
{
    ++second_;
    if (SECONDS_IN_MINUTE == second_) {
        second_ = MIN_TIME;
        ++minute_;
        if (MINUTES_IN_HOUR == minute_) {
            minute_ = MIN_TIME;
            ++hour_;
            if (HOURS_IN_DAY == hour_) {
                hour_ = MIN_TIME;
                nextDay();
            }
        }
    }
}

void
DateAndTime::nextDay()
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
DateAndTime::isLeapYear(const int year) const
{
    return (0 == year % LEAP_YEAR_DIV_BY_4 && 0 != year % LEAP_YEAR_DIV_BY_100) || (0 == year % LEAP_YEAR_DIV_BY_400);
}

int 
DateAndTime::daysInMonth(const int month, const int year) const
{
    static const int daysPerMonth[MAX_MONTH] = {
        MAX_DAYS_LONG_MONTH, FEB_DAYS, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH,
        MAX_DAYS_LONG_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH, MAX_DAYS_SHORT_MONTH, MAX_DAYS_LONG_MONTH
    };
    if (FEB_MONTH == month && isLeapYear(year)) return FEB_DAYS_LEAP;
    return daysPerMonth[month - 1];
}

bool
DateAndTime::validDate(const int month, const int day, const int year) const
{
    return year >= MIN_YEAR && month >= MIN_MONTH && month <= MAX_MONTH &&
           day >= MIN_DAY && day <= daysInMonth(month, year);
}

void
DateAndTime::printUniversal() const
{
    const char previus = std::cout.fill('0');
    std::cout << std::setfill('0')
              << month_ << '/' << std::setw(SPACE_SIZE) << day_ << '/' << year_ << " "
              << std::setw(SPACE_SIZE) << hour_ << ':' << std::setw(SPACE_SIZE) << minute_ << ':' << std::setw(SPACE_SIZE) << second_
              << std::endl;
    std::cout << std::setfill(previus);
}

void
DateAndTime::printStandard() const
{
    const int displayHour = (0 == hour_|| MIDNIGHT == hour_) ? MIDNIGHT : hour_ % MIDNIGHT;
    std::string am_pm = (hour_ < MIDNIGHT) ? "AM" : "PM";

    const char previus = std::cout.fill('0');
    std::cout << std::setfill('0')
              << month_ << '/' << std::setw(SPACE_SIZE) << day_ << '/' << year_ << " "
              << std::setw(SPACE_SIZE) << displayHour << ':' << std::setw(SPACE_SIZE) << minute_ << ':' << std::setw(SPACE_SIZE) << second_
              << ' ' << am_pm << std::endl << std::setfill(' ');
    std::cout << std::setfill(previus);
}

