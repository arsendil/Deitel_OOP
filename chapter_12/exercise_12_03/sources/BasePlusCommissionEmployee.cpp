#include "../headers/BasePlusCommissionEmployee.hpp"
#include <iostream>
#include <cassert>


BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber,
                                                       const double grossSales, const double commissionRate, const double baseSalary)
    : commissionEmployee_(firstName, lastName, socialSecurityNumber, grossSales, commissionRate)
{
    setBaseSalary(baseSalary);
    std::cout << "BasePlusCommissionEmployee constructor:" << std::endl;
    print();
    std::cout << "\n\n";
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
    std::cout << "BasePlusCommissionEmployee destructor:" << std::endl;
    print();
    std::cout << "\n\n";
}

void
BasePlusCommissionEmployee::setFirstName(const std::string& firstName)
{
    commissionEmployee_.setFirstName(firstName);
}

std::string
BasePlusCommissionEmployee::getFirstName() const
{
    return commissionEmployee_.getFirstName();
}

void
BasePlusCommissionEmployee::setLastName(const std::string& lastName)
{
    commissionEmployee_.setLastName(lastName);
}

std::string
BasePlusCommissionEmployee::getLastName() const
{
    return commissionEmployee_.getLastName();
}

void
BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string& socialSecurityNumber)
{
    commissionEmployee_.setSocialSecurityNumber(socialSecurityNumber);
}

std::string
BasePlusCommissionEmployee::getSocialSecurityNumber() const
{
    return commissionEmployee_.getSocialSecurityNumber();
}

void
BasePlusCommissionEmployee::setGrossSales(const double grossSales)
{
    commissionEmployee_.setGrossSales(grossSales);
}

double
BasePlusCommissionEmployee::getGrossSales() const
{
    return commissionEmployee_.getGrossSales();
}

void
BasePlusCommissionEmployee::setCommissionRate(const double commissionRate)
{
    commissionEmployee_.setCommissionRate(commissionRate);
}

double
BasePlusCommissionEmployee::getCommissionRate() const
{
    return commissionEmployee_.getCommissionRate();
}

void
BasePlusCommissionEmployee::setBaseSalary(const double baseSalary)
{
    assert(baseSalary_ >= 0);
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
    return getBaseSalary() + commissionEmployee_.earnings();
}

void
BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried ";
    commissionEmployee_.print();
    std::cout << "\nbase salary: " << getBaseSalary();
}

