#include "../headers/ComissionEmployee.hpp"

#include <cassert>
#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& firstName,
                                       const std::string& lastName,
                                       const std::string& socialSecurityNumber,
                                       const Date& birthDate,
                                       const double grossSales, double commissionRate)
    : Employee(firstName, lastName, socialSecurityNumber, birthDate)
{
    setGrossSales(grossSales);
    setCommissionRate(commissionRate);
}

CommissionEmployee::~CommissionEmployee()
{}

void
CommissionEmployee::setCommissionRate(const double commissionRate)
{
    assert(commissionRate >= 0.0 && commissionRate < 1.0);
    commissionRate_ = commissionRate;
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

void
CommissionEmployee::setGrossSales(const double grossSales)
{
    assert(grossSales > 0.0);
    grossSales_ = grossSales;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

double
CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales() + (isBirthMonth() ? BONUS : 0);
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: ";
    Employee::print();
    std::cout << "\ngross sales: " <<     getGrossSales()
              << "; commission rate: " << getCommissionRate();
}

