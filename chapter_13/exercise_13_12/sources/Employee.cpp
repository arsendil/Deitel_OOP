#include <iostream>
#include "../headers/Employee.hpp"

Employee::Employee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber, const Date& birthDate)
    : firstName_(firstName)
    , lastName_(lastName)
    , socialSecurityNumber_(socialSecurityNumber)
    , birthDate_(birthDate)
{}

Employee::~Employee()
{}

void
Employee::setFirstName(const std::string& firstName)
{
    firstName_ = firstName;
}

std::string
Employee::getFirstName() const
{
    return firstName_;
}

void
Employee::setLastName(const std::string& lastName)
{
    lastName_ = lastName;
}

std::string
Employee::getLastName() const
{
    return lastName_;
}

void
Employee::setSocialSecurityNumber(const std::string& socialSecurityNumber)
{
    socialSecurityNumber_ = socialSecurityNumber;
}

void
Employee::setBirthDate(const Date& birthDate)
{
    birthDate_ = birthDate;
}

std::string 
Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

Date
Employee::getBirthDate() const
{
    return birthDate_;
}

bool
Employee::isBirthMonth() const
{
    return birthDate_.getMonth() == birthDate_.getRealMonth();
}

void
Employee::print() const
{
    std::cout << getFirstName() << ' '        << getLastName()
              << "\nsocial security number: " << getSocialSecurityNumber();
}

