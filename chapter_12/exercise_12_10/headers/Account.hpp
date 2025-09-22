#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>
#include <cassert>

class Account
{
    friend std::ostream& operator<<(std::ostream& output, const Account& rhv);
    friend std::istream& operator>>(std::istream& input, Account& rhv);

public:
    Account(const double balance = 0.0);
    Account(const Account& rhv);

    Account& operator=(const Account& rhv);

    void credit(const double amount);
    void debit(const double amount);
    double getBalance() const;
    void setBalance(const double amount);

private:
    double balance_;
};

#endif /// __ACCOUNT_HPP__
