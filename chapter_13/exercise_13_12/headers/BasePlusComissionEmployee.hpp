#ifndef __BASE_PLUS_COMMISION_EMPLOYEE__
#define __BASE_PLUS_COMMISION_EMPLOYEE__

#include "ComissionEmployee.hpp"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string& firstName, const std::string& lastName,
                               const std::string& socialSecurityNumber,
                               const Date& birthDate, const double grossSales = 0.0,
                               const double commissionRate = 0.0, const double baseSalary = 0.0);
    virtual ~BasePlusCommissionEmployee();

    void setBaseSalary(const double baseSalary);
    double getBaseSalary()    const;

    virtual double earnings() const;
    virtual void print()      const;

private:
    double baseSalary_;
};

#endif /// __BASE_PLUS_COMMISION_EMPLOYEE__

