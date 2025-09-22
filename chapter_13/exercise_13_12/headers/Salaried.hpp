#ifndef __SALARIED_HPP__
#define __SALARIED_HPP__

#include "Employee.hpp"

#include <string>

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string& firstName, const std::string& lastName,
                     const std::string& socialSecurityNumber, const Date& birthDate, const double weeklySalary = 0.0);
    virtual ~SalariedEmployee();

    void setWeeklySalary(const double weeklySalary);
    double getWeeklySalary()  const;

    virtual double earnings() const;
    virtual void print()      const;

private:
    double weeklySalary_;
};

#endif /// __SALARIED_HPP__

