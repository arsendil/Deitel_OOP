#include "../headers/HourlyEmployee.hpp"

#include <cassert>
#include <iostream>

HourlyEmployee::HourlyEmployee(const std::string& firstName, const std::string& lastName,
                               const std::string& socialSecuritiNunber, const Date& birthDate,
                               const double hourlyWage, const double hoursWorked)
    : Employee(firstName, lastName, socialSecuritiNunber, birthDate)
{
    setWage(hourlyWage);
    setHours(hoursWorked);
}

HourlyEmployee::~HourlyEmployee()
{}

void 
HourlyEmployee::setWage(const double hourlyWage)
{
    assert(hourlyWage >= 0.0);
    hourlyWage_ = hourlyWage;
}

double
HourlyEmployee::getWage() const
{
    return hourlyWage_;
}

void
HourlyEmployee::setHours(const double hoursWorked)
{
    assert(hoursWorked > 0.0 && hoursWorked <= 168.0);
    hoursWorked_ = hoursWorked;
}

double
HourlyEmployee::getHours() const
{
    return hoursWorked_;
}

double
HourlyEmployee::earnings() const
{
    double salary = getHours() * getWage();
    if (getHours() > OVERTIME) {
        salary += ((getHours() - OVERTIME) * getWage() * 0.5);
    }
    return salary + (isBirthMonth() ? BONUS : 0);
}

void
HourlyEmployee::print() const
{
    std::cout << "hourly employee: ";
    Employee::print();
    std::cout << "\nhourly wage: "  << getWage()
              << "; hours worked: " << getHours();
}

