#include "../headers/SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const double amount, const double interestRate)
    : Account(amount)
{
    setInterestRate(interestRate);
}

SavingsAccount::SavingsAccount(const SavingsAccount& rhv)
    : Account(rhv.getBalance())
    , interestRate_(rhv.getInterestRate())
{}

SavingsAccount::~SavingsAccount()
{}

SavingsAccount&
SavingsAccount::operator=(const SavingsAccount& rhv)
{
    if (this != &rhv) {
        Account::operator=(rhv);
        setInterestRate(rhv.getInterestRate());
    }
    return *this;
}

double
SavingsAccount::getInterestRate() const
{
    return interestRate_;
}

void
SavingsAccount::setInterestRate(const double interestRate)
{
    assert(interestRate >= 0);
    interestRate_ = interestRate;
}

double
SavingsAccount::calculateInterest() const
{
    return getBalance() * getInterestRate();
}

void
SavingsAccount::print() const
{
    Account::print();
    std::cout << "Interest rate: " << getInterestRate()
              << '%';
}

std::istream&
operator>>(std::istream& input, SavingsAccount& rhv)
{
    input >> static_cast<Account&>(rhv);

    input >> rhv.interestRate_;
    return input;
}

