#include "../headers/Salaried.hpp"

#include <cassert>
#include <iostream>

SalariedEmployee::SalariedEmployee(const std::string& firstName,
                                   const std::string& lastName,
                                   const std::string& socialSecurityNumber,
                                   const Date& birthDate,
                                   const double weeklySalary)
    : Employee(firstName, lastName, socialSecurityNumber, birthDate)
{
    setWeeklySalary(weeklySalary);
}

SalariedEmployee::~SalariedEmployee()
{}

void
SalariedEmployee::setWeeklySalary(double weeklySalary)
{
    assert(weeklySalary >= 0.0);
    weeklySalary_ = weeklySalary;
}

double
SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary_;
}

double
SalariedEmployee::earnings() const
{
    return getWeeklySalary() + (isBirthMonth() ? BONUS : 0);
}

void
SalariedEmployee::print() const
{
    std::cout << "salaried employee: ";
    Employee::print();
    std::cout << "\nweekly salary: " << getWeeklySalary();
}

