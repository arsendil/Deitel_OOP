#include "../headers/CommissionEmployee.hpp"
#include <iostream>
#include <cassert>


CommissionEmployee::CommissionEmployee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber,
                                       const double grossSales, const double commissionRate)
    : firstName_(firstName)
    , lastName_(lastName)
    , socialSecurityNumber_(socialSecurityNumber)
{
    setGrossSales(grossSales);
    setCommissionRate(commissionRate);
    std::cout << "Commission employee constructor:" << std::endl;
    print();
    std::cout << "\n\n";
}

CommissionEmployee::~CommissionEmployee()
{
    std::cout << "Commission employee destructor:" << std::endl;
    print();
    std::cout << "\n\n";
}

void
CommissionEmployee::setFirstName(const std::string& firstName)
{
    firstName_ = firstName;
}

std::string
CommissionEmployee::getFirstName() const
{
    return firstName_;
}

void
CommissionEmployee::setLastName(const std::string& lastName)
{
    lastName_ = lastName;
}

std::string
CommissionEmployee::getLastName() const
{
    return lastName_;
}

void
CommissionEmployee::setSocialSecurityNumber(const std::string& socialSecurityNumber)
{
    socialSecurityNumber_ = socialSecurityNumber;
}

std::string
CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

void
CommissionEmployee::setGrossSales(const double grossSales)
{
    assert(grossSales >= 0);
    grossSales_ = grossSales;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

void
CommissionEmployee::setCommissionRate(const double commissionRate)
{
    assert(commissionRate >= 0);
    commissionRate_ = commissionRate;
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

double
CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: "      << getFirstName() << ' ' << getLastName()
              << "\nsocial security number: " << getSocialSecurityNumber()
              << "\ngross sales: "            << getGrossSales()
              << "\ncommission rate: "        << getCommissionRate();
}

