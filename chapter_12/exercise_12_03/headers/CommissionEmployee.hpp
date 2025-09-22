#ifndef __COMMISSION_EMPLOYEE_HPP__
#define __COMMISSION_EMPLOYEE_HPP__

#include <string>

class CommissionEmployee
{
public:
    CommissionEmployee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber,
                       const double grossSales = 0.0, const double  commissionRate = 0.0);
    ~CommissionEmployee();

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

    double earnings() const;
    void print() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    double grossSales_;
    double commissionRate_;
};

#endif /// __COMMISSION_EMPLOYEE_HPP__
