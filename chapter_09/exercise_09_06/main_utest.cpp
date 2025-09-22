#include "headers/Rational.hpp"

#include "gtest/gtest.h"


TEST(Rational, addRationalNumbers)
{
    Rational number1(8, 4);
    Rational number2(2, 2);
    Rational number3 = number1.addRationalNumbers(number2);
    EXPECT_EQ(number3.getNumeratorNumber(), 3);
    EXPECT_EQ(number3.getDenominatorNumber(), 1);
}

TEST(Rational, subtractRationalNumbers)
{
    Rational number1(8, 4);
    Rational number2(2, 2);
    Rational number3 = number1.subtractRationalNumbers(number2);
    EXPECT_EQ(number3.getNumeratorNumber(), 1);
    EXPECT_EQ(number3.getDenominatorNumber(), 1);
}

TEST(Rational, multiplyRationalNumbers)
{
    Rational number1(8, 4);
    Rational number2(2, 2);
    Rational number3 = number1.multiplyRationalNumbers(number2);
    EXPECT_EQ(number3.getNumeratorNumber(), 2);
    EXPECT_EQ(number3.getDenominatorNumber(), 1);
}

TEST(Rational, divideRationalNumbers)
{
    Rational number1(8, 4);
    Rational number2(2, 2);
    Rational number3 = number1.divideRationalNumbers(number2);
    EXPECT_EQ(number3.getNumeratorNumber(), 2);
    EXPECT_EQ(number3.getDenominatorNumber(), 1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

