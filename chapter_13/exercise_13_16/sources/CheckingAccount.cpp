#include "../headers/CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const double balance, const double transactionFee)
    : Account(balance)
{
    setTransactionFee(transactionFee);
}

CheckingAccount::CheckingAccount(const CheckingAccount& rhv)
    : Account(rhv.getBalance())
    , transactionFee_(rhv.getTransactionFee())
{}

CheckingAccount::~CheckingAccount()
{}

CheckingAccount&
CheckingAccount::operator=(const CheckingAccount& rhv)
{
    if (this != &rhv) {
        Account::operator=(rhv);
        setTransactionFee(rhv.getTransactionFee());
    }
    return *this;
}

double
CheckingAccount::getTransactionFee() const
{
    return transactionFee_;
}

void
CheckingAccount::setTransactionFee(const double transactionFee)
{
    assert(transactionFee >= 0);
    transactionFee_ = transactionFee;
}

void
CheckingAccount::credit(const double amount)
{
    Account::credit(amount);
    Account::debit(getTransactionFee());
}

void
CheckingAccount::debit(const double amount)
{
    assert(getBalance() >= amount + getTransactionFee());
    Account::debit(amount);
    Account::debit(getTransactionFee());
}

void
CheckingAccount::print() const
{
    Account::print();
    std::cout << " Transaction fee: " << getTransactionFee();
}

std::istream&
operator>>(std::istream& input, CheckingAccount& rhv)
{
    input >> static_cast<Account&>(rhv);
    input >> rhv.transactionFee_;
    return input;
}
