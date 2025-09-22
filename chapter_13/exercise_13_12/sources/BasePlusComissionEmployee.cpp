#include "../headers/BasePlusComissionEmployee.hpp"

#include <cassert>
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber,
    const Date& birthDate, const double grossSales, const double commissionRate, const double baseSalary)
    : CommissionEmployee(firstName, lastName, socialSecurityNumber, birthDate, grossSales, commissionRate)
{
    setBaseSalary(baseSalary);
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{}

void
BasePlusCommissionEmployee::setBaseSalary(const double baseSalary)
{
    assert(baseSalary >= 0.0);
    baseSalary_ = baseSalary;
}

double
BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
}

double
BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings() + (isBirthMonth() ? BONUS : 0);
}

void
BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried ";
    CommissionEmployee::print();
    std::cout << "; base salary: " << getBaseSalary();
}

