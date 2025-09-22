#include "../headers/Time.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>


Time::Time(const int hour, const int minute, const int second)
{
    setTime(hour, minute, second);
}

Time::Time(const Time& other)
{
    setTime(other.getHour(), other.getMinute(), other.getSecond());
}

void
Time::setTime(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void
Time::setHour(const int hour)
{
    assert(hour >= MIN_TIME && hour < HOUR_IN_DAY);
    hour_ = hour;
}

void
Time::setMinute(const int minute)
{
    assert(minute >= MIN_TIME && minute < SECOND_IN_MINUTE);
    minute_ = minute;
}

void 
Time::setSecond(const int second)
{   
    assert(second >= MIN_TIME && second < SECOND_IN_MINUTE);
    second_ = second;
}

int
Time::getHour() const
{
    return hour_;
}

int
Time::getMinute() const
{
    return minute_;
}

int
Time::getSecond() const
{
    return second_;
}

void
Time::printUniversal() const
{
    const char previus = std::cout.fill('0');
    std::cout << std::setfill('0') << std::setw(SPACE_SIZE) << getHour() << ':'
              << std::setw(SPACE_SIZE) << getMinute() << ':' << std::setw(SPACE_SIZE) << getSecond();
    std::cout << std::setfill(previus);
}

void
Time::printStandard() const
{
    const int hour = getHour();
    const char previus = std::cout.fill('0');
    std::cout << ((MIN_TIME == hour || MIDNIGHT == hour) ? MIDNIGHT : hour % MIDNIGHT)
         << ':' << std::setfill('0') << std::setw(SPACE_SIZE) << getMinute()
         << ':' << std::setw(SPACE_SIZE) << getSecond() << (hour_ < MIDNIGHT ? " AM" : " PM");
    std::cout << std::setfill(previus);
}

void
Time::tick()
{
    ++second_;
    if (SECOND_IN_MINUTE == second_) {
        second_ = MIN_TIME;
        ++minute_;
        if (SECOND_IN_MINUTE == minute_) {
            minute_ = MIN_TIME;
            ++hour_;
            if (HOUR_IN_DAY == hour_) {
                hour_ = MIN_TIME;
            }
        }
    }
}

