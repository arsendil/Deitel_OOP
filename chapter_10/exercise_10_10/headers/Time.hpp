#ifndef __TIME_HPP__
#define __TIME_HPP__

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
const int SPACE_SIZE = 2;
const int HOUR_IN_DAY = 24;
const int SECOND_IN_MINUTE = 60;
const int MIN_TIME = 0;
const int MIDNIGHT = 12;

class Time
{
public:
    Time(const int hour = MIN_TIME, const int minute = MIN_TIME, const int second = MIN_TIME);
    Time& setTime(const int hour, const int minute, const int second);
    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;

private:
    int secondsSinceMidnight_;
};

#endif /// __TIME_HPP__

