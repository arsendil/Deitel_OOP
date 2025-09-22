#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"
#include <gtest/gtest.h>
#include <vector>

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

TEST(AccountTest, BaseCreditDebit)
{
    Account acct(100.0);
    acct.credit(50.0);
    EXPECT_DOUBLE_EQ(acct.getBalance(), 150.0);

    acct.debit(25.0);
    EXPECT_DOUBLE_EQ(acct.getBalance(), 125.0);
}

TEST(AccountTest, CheckingAccountTransactions)
{
    CheckingAccount chk(100.0, 2.0);

    chk.credit(50.0);
    EXPECT_DOUBLE_EQ(chk.getBalance(), 148.0);

    chk.debit(20.0);
    EXPECT_DOUBLE_EQ(chk.getBalance(), 126.0);
}

TEST(AccountTest, SavingsAccountInterest)
{
    SavingsAccount sav(200.0, 0.05); 

    const double interest = sav.calculateInterest();
    EXPECT_DOUBLE_EQ(interest, 10.0); 

    sav.credit(interest);
    EXPECT_DOUBLE_EQ(sav.getBalance(), 210.0);
}

TEST(AccountTest, PolymorphicBehavior)
{
    Account* accounts[2];
    accounts[0] = new CheckingAccount(100.0, 1.0);
    accounts[1] = new SavingsAccount(200.0, 0.1);

    accounts[0]->credit(50.0); // +50 -1 => 149
    EXPECT_DOUBLE_EQ(accounts[0]->getBalance(), 149.0);

    SavingsAccount* savPtr = dynamic_cast<SavingsAccount*>(accounts[1]);
    ASSERT_TRUE(savPtr != NULL);
    const double interest = savPtr->calculateInterest();
    savPtr->credit(interest);
    EXPECT_DOUBLE_EQ(savPtr->getBalance(), 220.0);

    delete accounts[0];
    delete accounts[1];
}

TEST(AccountTest, PolymorphicTest)
{
    std::vector<Account*> accounts;

    accounts.push_back(new CheckingAccount(100.0, 1.5));
    accounts.push_back(new SavingsAccount(200.0, 0.05));

    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "---------------------------\n";
        accounts[i]->print();
        std::cout << std::endl;

        accounts[i]->credit(50);
        accounts[i]->debit(70);

        SavingsAccount* saving = dynamic_cast<SavingsAccount*>(accounts[i]);
        if (saving != NULL) {
            const double interest = saving->calculateInterest();
            std::cout << "Interest earned: " << interest << std::endl;
            saving->credit(interest);
        }

        std::cout << "Updated balance: " << accounts[i]->getBalance() << std::endl;
    }

    for (size_t i = 0; i < accounts.size(); ++i) {
        delete accounts[i];
    }
}

int 
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
