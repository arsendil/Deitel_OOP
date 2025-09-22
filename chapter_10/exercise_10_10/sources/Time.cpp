#include "../headers/Time.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>

Time::Time(const int hour, const int minute, const int second) : secondsSinceMidnight_(0)
{
    setTime(hour, minute, second);
}

Time&
Time::setTime(const int hour, const int minute, const int second)
{
    assert(hour >= MIN_TIME && hour < HOUR_IN_DAY && 
           minute >= MIN_TIME && minute < SECOND_IN_MINUTE && 
           second >= MIN_TIME && second < SECOND_IN_MINUTE);
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    return *this;
}

void
Time::setHour(const int hour)
{
    assert(hour >= MIN_TIME && hour < HOUR_IN_DAY);
    secondsSinceMidnight_ += hour * SECONDS_PER_HOUR - (getHour() * SECONDS_PER_HOUR);
}

void
Time::setMinute(const int minute)
{
    assert(minute >= MIN_TIME && minute < SECOND_IN_MINUTE);
    secondsSinceMidnight_ += minute * SECONDS_PER_MINUTE - (getMinute() * SECONDS_PER_MINUTE);
}

void
Time::setSecond(const int second)
{
    assert(second >= MIN_TIME && second < SECOND_IN_MINUTE);
    secondsSinceMidnight_ += second - getSecond();
}

int
Time::getHour() const
{
    return secondsSinceMidnight_ / SECONDS_PER_HOUR;
}

int
Time::getMinute() const
{
    return (secondsSinceMidnight_ % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
}

int
Time::getSecond() const
{
    return secondsSinceMidnight_ % SECONDS_PER_MINUTE;
}

void
Time::printUniversal() const
{  
    const char previus = std::cout.fill('0');
    std::cout << std::setfill('0')    
              << std::setw(SPACE_SIZE) << getHour()   << ":"
              << std::setw(SPACE_SIZE) << getMinute() << ":"
              << std::setw(SPACE_SIZE) << getSecond();   
    std::cout << std::setfill(previus);
}

void
Time::printStandard() const
{
    const int hour = getHour();
    const char previus = std::cout.fill('0');
    std::cout << ((MIN_TIME  == hour || MIDNIGHT == hour) ? MIDNIGHT : hour % MIDNIGHT)
              << ":" << std::setfill('0')     << std::setw(SPACE_SIZE) << getMinute()
              << ":" << std::setw(SPACE_SIZE) << getSecond()
              << (hour < MIDNIGHT ? " AM" : " PM");
    std::cout << std::setfill(previus);
}

