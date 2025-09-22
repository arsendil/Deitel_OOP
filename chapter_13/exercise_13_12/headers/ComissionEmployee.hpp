#ifndef __COMMISSION_EMPLOYEE_HPP__
#define __COMMISSION_EMPLOYEE_HPP__

#include "Date.hpp"
#include "Employee.hpp"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string& firstName, const std::string& lastName,
                       const std::string& socialSecurityNumber, const Date& birthDate,
                       const double grossSales = 0.0, const double commissionRate = 0.0);
    virtual ~CommissionEmployee();

    void setCommissionRate(const double grossSales);
    void setGrossSales(const double commissionRate);

    double getCommissionRate() const;
    double getGrossSales()     const;

    virtual double earnings()  const;
    virtual void print()       const;

private:
    double grossSales_;
    double commissionRate_;
};

#endif /// __COMMISSION_EMPLOYEE_HPP__

