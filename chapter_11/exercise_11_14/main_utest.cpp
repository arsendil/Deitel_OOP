#include "headers/HugeInteger.hpp"
#include <gtest/gtest.h>

TEST(HugeIntegerTest, ConstructFromInt)
{
    HugeInteger num(12345);
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "12345");
}

TEST(HugeIntegerTest, ConstructFromString)
{
    HugeInteger num("98765432101234567890");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "98765432101234567890");
}

TEST(HugeIntegerTest, AddOperation)
{
    HugeInteger a("999");
    HugeInteger b("1");
    HugeInteger result = a + b;
    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "1000");
}

TEST(HugeIntegerTest, SubtractOperation)
{
    HugeInteger a("1000");
    HugeInteger b("1");
    HugeInteger result = a - b;
    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "999");
}

TEST(HugeIntegerTest, MultiplyOperation)
{
    HugeInteger a("123");
    HugeInteger b("456");
    HugeInteger result = a * b;
    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "56088");
}

TEST(HugeIntegerTest, DivisionOperation)
{
    HugeInteger a("56088");
    HugeInteger b("123");
    HugeInteger result = a / b;
    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "456");
}

TEST(HugeIntegerTest, EqualityOperators)
{
    HugeInteger a("123456789");
    HugeInteger b("123456789");
    HugeInteger c("987654321");
    
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a != b);
}

TEST(HugeIntegerTest, ComparisonOperators)
{
    HugeInteger a("1000");
    HugeInteger b("999");

    EXPECT_TRUE(a > b);
    EXPECT_TRUE(b < a);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(b <= a);
    EXPECT_TRUE(a >= a);
    EXPECT_TRUE(b <= b);
}

TEST(HugeIntegerTest, AddLongToHugeInteger)
{
    HugeInteger h1("999");
    long value = 1;

    HugeInteger result = h1 + value;
    EXPECT_EQ(result, HugeInteger("1000"));
}

TEST(HugeIntegerTest, AddLongWithCarryPropagation)
{
    HugeInteger h1("1999");
    long value = 2;

    HugeInteger result = h1 + value;
    EXPECT_EQ(result, HugeInteger("2001"));
}

TEST(HugeIntegerTest, AddLongZero)
{
    HugeInteger h1("123456");
    long value = 3;

    HugeInteger result = h1 + value;
    EXPECT_EQ(result, "123459");
}

TEST(HugeIntegerTest, SubtractLong)
{
    HugeInteger a("1000");
    long b = 1;
    HugeInteger result = a - b;
    EXPECT_EQ(result, HugeInteger("999"));
}

TEST(HugeIntegerTest, SubtractCString)
{
    HugeInteger a("2000");
    const char* b = "1000";
    HugeInteger result = a - b;
    EXPECT_EQ(result, HugeInteger("1000"));
}

TEST(HugeIntegerTest, MultiplyByCharPtr)
{
    HugeInteger num1("12345");
    const char* multiplier = "10";

    HugeInteger result = num1 * multiplier;

    HugeInteger expected("123450");
    EXPECT_EQ(result, expected);
}

TEST(HugeIntegerTest, MultiplyByLargeCharPtr)
{
    HugeInteger num1("999999999999999999999999999999");
    const char* multiplier = "2";

    HugeInteger result = num1 * multiplier;

    HugeInteger expected("1999999999999999999999999999998");
    EXPECT_EQ(result, expected);
}

TEST(HugeIntegerTest, MultiplyByCharPtrWithZero)
{
    HugeInteger num1("123456789");
    const char* multiplier = "0";

    HugeInteger result = num1 * multiplier;

    HugeInteger expected("0");
    EXPECT_EQ(result, expected);
}

TEST(HugeIntegerDivisionTest, DivideByLong)
{
    HugeInteger a("9876543210");
    long divisor = 5;
    HugeInteger result = a / divisor;

    HugeInteger expected("1975308642"); 

    EXPECT_EQ(result, expected);
}

TEST(HugeIntegerDivisionTest, DivideSmallByLargeLong)
{
    HugeInteger a("123");
    long divisor = 1000;
    HugeInteger result = a / divisor;

    HugeInteger expected("0");
    EXPECT_EQ(result, expected);
}

TEST(HugeIntegerDivisionTest, DivideWithRemainder)
{
    HugeInteger a("1000");
    long divisor = 3;
    HugeInteger result = a / divisor;

    HugeInteger expected("333");
    EXPECT_EQ(result, expected);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
