#include <gtest/gtest.h>
#include "headers/Rational.hpp"
#include <sstream>

TEST(RationalTest, ConstructorAndSimplification)
{
    Rational r(4, 8);
    EXPECT_EQ(r.getNumeratorNumber(), 1);
    EXPECT_EQ(r.getDenominatorNumber(), 2);
}

TEST(RationalTest, Addition)
{
    Rational r1(1, 3);
    Rational r2(1, 6);
    Rational result = r1 + r2;
    EXPECT_EQ(result, Rational(1, 2));
}

TEST(RationalTest, Subtraction)
{
    Rational r1(2, 3);
    Rational r2(1, 3);
    Rational result = r1 - r2;
    EXPECT_EQ(result, Rational(1, 3));
}

TEST(RationalTest, Multiplication)
{
    Rational r1(2, 3);
    Rational r2(3, 4);
    Rational result = r1 * r2;
    EXPECT_EQ(result, Rational(1, 2));
}

TEST(RationalTest, Division)
{
    Rational r1(2, 3);
    Rational r2(4, 5);
    Rational result = r1 / r2;
    EXPECT_EQ(result, Rational(5, 6));
}

TEST(RationalTest, ComparisonOperators)
{
    Rational r1(1, 2);
    Rational r2(2, 3);
    EXPECT_TRUE(r1 < r2);
    EXPECT_TRUE(r2 > r1);
    EXPECT_TRUE(r1 <= r2);
    EXPECT_TRUE(r2 >= r1);
    EXPECT_TRUE(r1 != r2);
    EXPECT_TRUE(r1 == Rational(1, 2));
}

TEST(RationalTest, OutputOperator)
{
    Rational r(3, 4);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "3/4");
}

TEST(RationalTest, InputOperator)
{
    std::istringstream iss("5 6");
    Rational r;
    iss >> r;
    EXPECT_EQ(r, Rational(5, 6));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
