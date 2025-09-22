#include <gtest/gtest.h>
#include "headers/Complex.hpp"

TEST(ComplexTest, DefaultConstructor)
{
    Complex c;
    EXPECT_DOUBLE_EQ(c.getReal(), 0.0);
    EXPECT_DOUBLE_EQ(c.getImaginary(), 0.0);
}

TEST(ComplexTest, ParameterizedConstructor)
{
    Complex c(3.5, -2.1);
    EXPECT_DOUBLE_EQ(c.getReal(), 3.5);
    EXPECT_DOUBLE_EQ(c.getImaginary(), -2.1);
}

TEST(ComplexTest, CopyConstructor)
{
    Complex original(1.1, 2.2);
    Complex copy(original);
    EXPECT_DOUBLE_EQ(copy.getReal(), 1.1);
    EXPECT_DOUBLE_EQ(copy.getImaginary(), 2.2);
}

TEST(ComplexTest, AdditionPositive)
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex result = a + b;
    EXPECT_DOUBLE_EQ(result.getReal(), 4.0);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 6.0);
}

TEST(ComplexTest, AdditionNegative)
{
    Complex a(-2.5, 1.5);
    Complex b(1.0, -3.0);
    Complex result = a + b;
    EXPECT_DOUBLE_EQ(result.getReal(), -1.5);
    EXPECT_DOUBLE_EQ(result.getImaginary(), -1.5);
}

TEST(ComplexTest, Subtraction)
{
    Complex a(5.0, 4.0);
    Complex b(2.0, 3.0);
    Complex result = a - b;
    EXPECT_DOUBLE_EQ(result.getReal(), 3.0);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 1.0);
}

TEST(ComplexTest, Multiplication)
{
    Complex a(2.0, 3.0);
    Complex b(4.0, -5.0);
    Complex result = a * b;
    EXPECT_DOUBLE_EQ(result.getReal(), 23.0);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 2.0);
}

TEST(ComplexTest, EqualityTrue)
{
    Complex a(3.3, 4.4);
    Complex b(3.3, 4.4);
    EXPECT_TRUE(a == b);
}

TEST(ComplexTest, EqualityFalse)
{
    Complex a(3.3, 4.4);
    Complex b(4.4, 3.3);
    EXPECT_FALSE(a == b);
}

TEST(ComplexTest, InequalityTrue)
{
    Complex a(1.1, 2.2);
    Complex b(2.2, 1.1);
    EXPECT_TRUE(a != b);
}

TEST(ComplexTest, InequalityFalse)
{
    Complex a(-7.7, 8.8);
    Complex b(-7.7, 8.8);
    EXPECT_FALSE(a != b);
}

TEST(ComplexTest, InputOperator)
{
    Complex c;
    std::istringstream input("9.9 -1.1");
    input >> c;
    EXPECT_DOUBLE_EQ(c.getReal(), 9.9);
    EXPECT_DOUBLE_EQ(c.getImaginary(), -1.1);
}

TEST(ComplexTest, OutputOperatorFormat)
{
    Complex c(5.0, -6.0);
    std::ostringstream output;
    output << c;
    EXPECT_EQ(output.str(), "(5, -6)");
}

TEST(ComplexTest, ChainedAddition)
{
    Complex a(1, 1);
    Complex b(2, 2);
    Complex c(3, 3);
    Complex result = a + b + c;
    EXPECT_DOUBLE_EQ(result.getReal(), 6.0);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 6.0);
}

TEST(ComplexTest, ComplexZeroBehavior)
{
    Complex zero;
    Complex a(10.5, -7.3);
    Complex result = a + zero;
    EXPECT_TRUE(result == a);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
