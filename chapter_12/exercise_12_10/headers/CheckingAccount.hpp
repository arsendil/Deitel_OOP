#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__

#include "Account.hpp"
#include <cassert>

class CheckingAccount : public Account
{
    friend std::ostream& operator<<(std::ostream& output, const CheckingAccount& rhv);
    friend std::istream& operator>>(std::istream& input, CheckingAccount& rhv);

public:
    CheckingAccount(const double balance = 0.0, const double transactionFee = 0.0);
    CheckingAccount(const CheckingAccount& rhv);

    CheckingAccount& operator=(const CheckingAccount& rhv);

    void credit(const double amount); 
    void debit(const double amount);

    double getTransactionFee() const;
    void setTransactionFee(const double transactionFee);

private:
    double transactionFee_;
};

#endif // __CHECKING_ACCOUNT_HPP__


