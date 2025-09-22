#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__

#include "Account.hpp"
#include <cassert>

class CheckingAccount : public Account
{
    friend std::istream& operator>>(std::istream& input, CheckingAccount& rhv);

public:
    CheckingAccount(const double balance = 0.0, const double transactionFee = 0.0);
    CheckingAccount(const CheckingAccount& rhv);
    virtual ~CheckingAccount();

    CheckingAccount& operator=(const CheckingAccount& rhv);

    double getTransactionFee() const;
    void setTransactionFee(const double transactionFee);

    virtual void print() const;
    virtual void credit(const double amount);
    virtual void debit(const double amount);

private:
    double transactionFee_;
};

#endif // __CHECKING_ACCOUNT_HPP__
