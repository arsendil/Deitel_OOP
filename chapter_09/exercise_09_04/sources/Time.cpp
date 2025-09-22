#include "headers/Time.hpp"
#include <iostream>
#include <ctime>
#include <cassert>

Time::Time()
{
    const int timeSinceCreation = std::time(0);
    const int hour = (timeSinceCreation / SECOND_IN_HOUR + DIFFERENCE_IN_HOURS) % HOUR_IN_DAY;
    const int minute = (timeSinceCreation / SECOND_IN_MINUTE) % SECOND_IN_MINUTE;
    const int second = timeSinceCreation % SECOND_IN_MINUTE;
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

Time::Time(const Time& other)
{   
    setHour(other.getHour()); 
    setMinute(other.getMinute()); 
    setSecond(other.getSecond()); 
}

void
Time::setHour(const int hour)
{
    assert(hour >= MIN_TIME && hour < MAX_HOUR);    
    hour_ = hour; 
}

void
Time::setMinute(const int minute)
{
    assert(minute >= MIN_TIME && minute <= MAX_MINUTE);
    minute_ = minute; 
}

void
Time::setSecond(const int second)
{
    assert(second >= MIN_TIME && second <= MAX_SECOND);
    second_ = second; 
}

void
Time::displayTime() const
{
    std::cout << "Current Time: "
              << (hour_ <   ADD_ZERO_PREFIX ? "0" : "") << hour_   << ":"
              << (minute_ < ADD_ZERO_PREFIX ? "0" : "") << minute_ << ":"
              << (second_ < ADD_ZERO_PREFIX ? "0" : "") << second_ << std::endl;
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

