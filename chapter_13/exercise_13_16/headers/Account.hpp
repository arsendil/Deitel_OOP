#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>
#include <cassert>

class Account
{
    friend std::istream& operator>>(std::istream& input, Account& rhv);

public:
    Account(const double balance = 0.0);
    Account(const Account& rhv);
    virtual ~Account();

    Account& operator=(const Account& rhv);

    void setBalance(const double amount);
    double getBalance() const;

    virtual void print() const;
    virtual void credit(const double amount);
    virtual void debit(const double amount);

private:
    double balance_;
};

#endif /// __ACCOUNT_HPP__
