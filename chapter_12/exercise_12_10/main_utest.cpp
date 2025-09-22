#include <gtest/gtest.h>
#include "headers/Account.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"

TEST(AccountTest, CreditIncreasesBalance)
{
    Account acc(100.0);
    acc.credit(50.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150.0);
}

TEST(AccountTest, DebitDecreasesBalance)
{
    Account acc(100.0);
    acc.debit(40.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 60.0);
}

TEST(SavingsAccountTest, InterestCalculation)
{
    SavingsAccount sacc(1000.0, 0.05);
    EXPECT_DOUBLE_EQ(sacc.calculateInterest(), 50.0);
}

TEST(SavingsAccountTest, AddInterest)
{
    SavingsAccount sacc(1000.0, 0.05);
    sacc.credit(sacc.calculateInterest());
    EXPECT_DOUBLE_EQ(sacc.getBalance(), 1050.0);
}

TEST(CheckingAccountTest, CreditChargesFee)
{
    CheckingAccount cacc(100.0, 2.0);
    cacc.credit(50.0);
    EXPECT_DOUBLE_EQ(cacc.getBalance(), 148.0);
}

TEST(CheckingAccountTest, DebitChargesFee)
{
    CheckingAccount cacc(100.0, 2.0);
    cacc.debit(20.0);
    EXPECT_DOUBLE_EQ(cacc.getBalance(), 78.0);
}

int 
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

