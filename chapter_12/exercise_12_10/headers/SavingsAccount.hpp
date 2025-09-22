#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

#include "Account.hpp"

class SavingsAccount : public Account
{
    friend std::ostream& operator<<(std::ostream& output, const SavingsAccount& rhv);
    friend std::istream& operator>>(std::istream& input, SavingsAccount& rhv);

public:
    SavingsAccount(const double amount = 0.0, const double interestRate = 0.0);
    SavingsAccount(const SavingsAccount& rhv);

    SavingsAccount& operator=(const SavingsAccount& rhv);

    double getInterestRate() const;
    void setInterestRate(const double interestRate);
    double calculateInterest() const;

private:
    double interestRate_;
};

#endif /// __SAVINGS_ACCOUNT_HPP__
       ///
