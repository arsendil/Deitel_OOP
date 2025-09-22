#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

#include "Account.hpp"

class SavingsAccount : public Account
{
    friend std::istream& operator>>(std::istream& input, SavingsAccount& rhv);

public:
    SavingsAccount(const double amount = 0.0, const double interestRate = 0.0);
    SavingsAccount(const SavingsAccount& rhv);
    virtual ~SavingsAccount();

    SavingsAccount& operator=(const SavingsAccount& rhv);

    void setInterestRate(const double interestRate);
    double getInterestRate()   const;
    
    virtual void print() const;

    double calculateInterest() const; 

private:
    double interestRate_;
};

#endif /// __SAVINGS_ACCOUNT_HPP__
