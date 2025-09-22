#ifndef __BASE_PLUS_COMMISSION_EMPLOYEE__
#define __BASE_PLUS_COMMISSION_EMPLOYEE__

#include "CommissionEmployee.hpp"
#include <string>

class BasePlusCommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber, 
                               const double grossSales = 0.0, const double commissionRate = 0.0, const double baseSalary = 0.0);
    ~BasePlusCommissionEmployee();

    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;

    void setLastName(const std::string& lastName);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string& socialSecurityNumber);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(const double grossSales);
    double getGrossSales() const;

    void setCommissionRate(const double commissionRate);
    double getCommissionRate() const;

    void setBaseSalary(const double baseSalary);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

private:
    CommissionEmployee commissionEmployee_;
    double baseSalary_;
};

#endif /// __BASE_PLUS_COMMISSION_EMPLOYEE__
