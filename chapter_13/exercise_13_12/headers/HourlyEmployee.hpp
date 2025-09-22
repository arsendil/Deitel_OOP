#ifndef __HOURLY_EMPLOYEE_HPP__
#define __HOURLY_EMPLOYEE_HPP__

const int OVERTIME = 40;

#include "Employee.hpp"

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(const std::string& firstName, const std::string& lastName,
                   const std::string& socialSecurityNumber, const Date& birthDate,
                   const double hourlyWageWage = 0.0, const double hoursWorked = 0.0);
    virtual ~HourlyEmployee();

    void setWage(const double hourlyWage);
    void setHours(const double hoursWorked);

    double getWage()          const;
    double getHours()         const;

    virtual double earnings() const;
    virtual void print()      const;

private:
    double hourlyWage_;
    double hoursWorked_;
};

#endif /// __HOURLY_H__

