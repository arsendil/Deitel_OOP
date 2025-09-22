#ifndef __TIME_HPP__
#define __TIME_HPP__

const int MAX_HOUR = 23;
const int MAX_MINUTE = 59;
const int MAX_SECOND = 59;
const int MIN_TIME = 0;
const int ADD_ZERO_PREFIX = 10;
const int SECOND_IN_HOUR = 3600;
const int HOUR_IN_DAY = 24;
const int SECOND_IN_MINUTE = 60;
const int DIFFERENCE_IN_HOURS = 4;

class Time
{
public:
    Time();
    Time(const Time& other);
    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const int second);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void displayTime() const;

private:
    int hour_;
    int minute_;
    int second_;
};

#endif /// __TIME_HPP__
