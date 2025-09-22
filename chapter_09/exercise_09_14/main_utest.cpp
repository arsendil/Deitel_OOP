#include "headers/HugeInteger.hpp"

#include <sstream>
#include <gtest/gtest.h>

TEST(HugeIntegerTest, ConstructFromInt)
{
    HugeInteger h(165445);
    HugeInteger expected("165445");
    EXPECT_TRUE(h.isEqualTo(expected));
}

TEST(HugeIntegerTest, ConstructFromCString)
{
    HugeInteger h("987654321");
    HugeInteger expected("987654321");
    EXPECT_TRUE(h.isEqualTo(expected));
}

TEST(HugeIntegerTest, CopyConstructor)
{
    HugeInteger original = 123456789;
    HugeInteger copy(original);
    EXPECT_TRUE(copy.isEqualTo(original));
}

TEST(HugeIntegerTest, Addition)
{
    HugeInteger a("123456");
    HugeInteger b("654321");
    HugeInteger result = a.add(b);
    HugeInteger expected("777777");
    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(HugeIntegerTest, SubtractionWithoutBorrow)
{
    HugeInteger a("1000");
    HugeInteger b("1");
    HugeInteger result = a.subtract(b);
    HugeInteger expected("999");
    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(HugeIntegerTest, SubtractionWithBorrow)
{
    HugeInteger a("10000");
    HugeInteger b("1");
    HugeInteger result = a.subtract(b);
    HugeInteger expected("9999");
    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(HugeIntegerTest, Multiplication)
{
    HugeInteger a("123");
    HugeInteger b("456");
    HugeInteger result = a.multiply(b);
    HugeInteger expected("56088");
    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(HugeIntegerTest, ComparisonEqual)
{
    HugeInteger a("8888");
    HugeInteger b("8888");
    EXPECT_TRUE(a.isEqualTo(b));
    EXPECT_FALSE(a.isNotEqualTo(b));
}

TEST(HugeIntegerTest, ComparisonGreaterLess)
{
    HugeInteger a = "9999";
    HugeInteger b = "8888";
    EXPECT_TRUE(a.isGreaterThan(b));
    EXPECT_TRUE(b.isLessThan(a));
}

TEST(HugeIntegerTest, ZeroCheck)
{
    HugeInteger a("0");
    EXPECT_TRUE(a.isZero());
    HugeInteger b("1");
    EXPECT_FALSE(b.isZero());
}

TEST(HugeIntegerTest, OutputFromLong)
{
    HugeInteger number(12345);

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    number.output();

    std::cout.rdbuf(oldCout);

    EXPECT_EQ(buffer.str(), "12345\n");
}

TEST(HugeIntegerTest, OutputFromChar)
{
    HugeInteger number("987654321");

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    number.output();

    std::cout.rdbuf(oldCout);

    EXPECT_EQ(buffer.str(), "987654321\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

