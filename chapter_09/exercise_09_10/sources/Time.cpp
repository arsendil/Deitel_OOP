#include "../headers/Time.hpp"
#include <iostream>
#include <iomanip>


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
    if (hour >= MIN_TIME && hour < SECOND_IN_MINUTE) {
        hour_ = hour;
        return;
    }
    std::cout << "Warrning 3: Invalid hour! It set 0." << std::endl;
    hour_ = 0; 
}

void
Time::setMinute(const int minute)
{
    if (minute >= MIN_TIME && minute < SECOND_IN_MINUTE) {
        minute_ = minute;
        return;
    }
    std::cout << "Warrning 2: Invalid minute! It set 0." << std::endl;
    minute_ = 0;
}

void 
Time::setSecond(const int second)
{
    if (second >= MIN_TIME && second < SECOND_IN_MINUTE) {
        second_ = second;
        return;
    }
    std::cout << "Warrning 1: Invalid second! It set 0." << std::endl;
    second_ = 0;
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

