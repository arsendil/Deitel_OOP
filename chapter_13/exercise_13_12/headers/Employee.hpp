#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

const int BONUS = 100;

#include "Date.hpp"

#include <string>

class Employee
{
public:
    Employee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber, const Date& birthDate);
    virtual ~Employee();

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setSocialSecurityNumber(const std::string& socialSecurityNumber);
    void setBirthDate(const Date& date);

    std::string getFirstName()            const;
    std::string getLastName()             const;
    std::string getSocialSecurityNumber() const;
    Date getBirthDate()                   const;
    bool isBirthMonth()                   const;

    virtual double earnings() const = 0;
    virtual void print()      const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    Date birthDate_;
};

#endif // __EMPLOYEE_HPP__

