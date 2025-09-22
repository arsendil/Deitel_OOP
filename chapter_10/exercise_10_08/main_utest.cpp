#include "headers/SavingsAccount.hpp"
#include <gtest/gtest.h>
#include <cmath>

const double INITIAL_BALANCE_1 = 2000.0;
const double INITIAL_BALANCE_2 = 3000.0;
const double INTEREST_RATE_3 = 0.03;
const double INTEREST_RATE_4 = 0.04;
const double EPSILON = 0.0001;

bool doubleEquals(const double number1, const double number2, const double epsilon);

TEST(SavingsAccountTest, InterestCalculation)
{
    SavingsAccount saver1(INITIAL_BALANCE_1);
    SavingsAccount saver2(INITIAL_BALANCE_2);

    SavingsAccount::modifyInterestRate(INTEREST_RATE_3);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    double expected1_after3 = INITIAL_BALANCE_1 + INITIAL_BALANCE_1 * (INTEREST_RATE_3 / COUNT_OF_MONTS);
    double expected2_after3 = INITIAL_BALANCE_2 + INITIAL_BALANCE_2 * (INTEREST_RATE_3 / COUNT_OF_MONTS);

    ASSERT_TRUE(doubleEquals(saver1.getSavingsBalance(), expected1_after3, EPSILON));
    ASSERT_TRUE(doubleEquals(saver2.getSavingsBalance(), expected2_after3, EPSILON));

    SavingsAccount::modifyInterestRate(INTEREST_RATE_4);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    const double expected1_after4 = expected1_after3 + expected1_after3 * (INTEREST_RATE_4 / COUNT_OF_MONTS);
    const double expected2_after4 = expected2_after3 + expected2_after3 * (INTEREST_RATE_4 / COUNT_OF_MONTS);

    ASSERT_TRUE(doubleEquals(saver1.getSavingsBalance(), expected1_after4, EPSILON));
    ASSERT_TRUE(doubleEquals(saver2.getSavingsBalance(), expected2_after4, EPSILON));
}


int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool
doubleEquals(const double number1, const double number2, const double epsilon)
{
    return std::fabs(number1 - number2) < epsilon;
}
