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

std::ostream&
operator<<(std::ostream& output, const SavingsAccount& rhv)
{
    output << static_cast<const Account&>(rhv)
           << "Interest rate: " << rhv.getInterestRate()
           << '%';
    return output;
}

std::istream&
operator>>(std::istream& input, SavingsAccount& rhv)
{
    input >> static_cast<Account&>(rhv);

    input >> rhv.interestRate_;
    return input;
}
