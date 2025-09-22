#include "../headers/SavingsAccount.hpp"

#include <ios>
#include <iostream>
#include <cassert>
#include <iomanip>

double SavingsAccount::annualInterestRate_ = 0.0;

SavingsAccount::SavingsAccount(const double rate)
{
    setSavingsBalance(rate);
}

SavingsAccount::SavingsAccount(const SavingsAccount& rhv)
{
    setSavingsBalance(rhv.getSavingsBalance());
}

void
SavingsAccount::setSavingsBalance(const double savingsBalance)
{
    assert(savingsBalance >= 0);
    savingsBalance_ = savingsBalance;
}

double
SavingsAccount::getSavingsBalance() const
{
    return savingsBalance_;
}

void
SavingsAccount::calculateMonthlyInterest()
{
    const double interest = getSavingsBalance() * (getAnnualInterestRate() / COUNT_OF_MONTS);
    setSavingsBalance(interest + getSavingsBalance());
}

void
SavingsAccount::printBalance() const
{
    std::cout << "$" << std::fixed << std::setprecision(SIZE_OF_FILL) << savingsBalance_ << std::endl;
}

void
SavingsAccount::modifyInterestRate(const double rate)
{
    assert(rate >= 0);
    annualInterestRate_ = rate;
}

double
SavingsAccount::getAnnualInterestRate()
{
    return annualInterestRate_;
}

