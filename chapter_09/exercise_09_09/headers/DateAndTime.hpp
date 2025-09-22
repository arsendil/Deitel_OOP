#ifndef __DATEANDTIME_HPP__
#define __DATEANDTIME_HPP__

const int SECONDS_IN_MINUTE = 60;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;
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
const int MIN_TIME = 0;
const int SPACE_SIZE = 2;
const int MIDNIGHT = 12;
const int DEFAULT_2000 = 2000;

class DateAndTime
{
public:
    DateAndTime(const int month = MIN_MONTH, const int day = MIN_DAY, const int year = DEFAULT_2000,
                const int hour = MIN_TIME, const int minute = MIN_TIME, const int second = MIN_TIME);
    DateAndTime(const DateAndTime& other);
    void tick();
    void printUniversal() const;
    void printStandard() const;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);
    void setTime(const int hour, const int minute, const int second);
    void setDate(const int month, const int day, const int year);
    void setDateTime(const int month, const int day, const int year, const int hour, const int minute, const int second);
    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

private:
    bool isLeapYear(const int year) const;
    int daysInMonth(const int month, const int year) const;
    void nextDay();
    bool validDate(const int month, const int day, const int year) const;

private:
    int hour_;
    int minute_;
    int second_;

    int day_;
    int month_;
    int year_;
};

#endif /// __DATEANDTIME_HPP__

