#include "../headers/Account.hpp"

Account::Account(const double balance)
{
    setBalance(balance); 
}

Account::Account(const Account& rhv)
    : balance_(rhv.getBalance())
{}

Account&
Account::operator=(const Account& rhv)
{
    if (this != &rhv) {
        setBalance(rhv.getBalance());
    }
    return *this;
}

void
Account::credit(const double amount)
{
    assert(amount >= amount);
    setBalance(getBalance() + amount);
}

void
Account::debit(const double amount)
{
    assert(getBalance() >= amount && amount >= 0);
    setBalance(getBalance() - amount);
}

double
Account::getBalance() const
{
    return balance_;
}

void
Account::setBalance(const double amount)
{
    assert(amount >= 0);
    balance_ = amount;
}

std::ostream&
operator<<(std::ostream& output, const Account& rhv)
{
    output << "Balance: " << rhv.getBalance();
    return output;
}

std::istream&
operator>>(std::istream& input, Account& rhv)
{
    input >> rhv.balance_;
    return input;
}
