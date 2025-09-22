#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include "Person.hpp"

#include <iostream>
#include <cassert>

class Package
{
    friend std::ostream& operator<<(std::ostream& output, const Package& rhv);
    friend std::istream& operator>>(std::istream& input, Package& rhv);

public:
    Package(const Person& senderPerson, const Person& recipientPerson, const double weight = 1, const double costPerOunce = 1);
    Package(const Package& rhv);
   
    Package& operator=(const Package& rhv);

    void setSenderPerson(const Person& rhv);
    void setRecipientPerson(const Person& rhv);
    Person getSenderPerson()    const;
    Person getRecipientPerson() const;

    void setWeight(const double weight);
    void setCostPerOunce(const double costPerOunce);
    double getWeight()       const;
    double getCostPerOunce() const;
    
    double calculateCost()   const;

private:
    Person senderPerson_;
    Person recipientPerson_;
    double weight_;
    double costPerOunce_;
};

#endif /// __PACKAGE_HPP__
