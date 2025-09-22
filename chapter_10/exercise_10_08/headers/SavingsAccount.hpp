#ifndef __SAVINGS_ACCOUNT__
#define __SAVINGS_ACCOUNT__

const double COUNT_OF_MONTS = 12.00;
const int SIZE_OF_FILL = 2;

class SavingsAccount
{
public:
    static void modifyInterestRate(const double rate);
    static double getAnnualInterestRate();
    static void setAnnualInterestRate(const double rate);

private:
    static double annualInterestRate_;

public:
    SavingsAccount(const double savingsBalance = 0);
    SavingsAccount(const SavingsAccount& other);
    void calculateMonthlyInterest();
    void setSavingsBalance(const double savingsBalance);
    double getSavingsBalance() const;
    void printBalance() const;

private:
    double savingsBalance_;
};

#endif /// __SAVINGS_ACCOUNT__

