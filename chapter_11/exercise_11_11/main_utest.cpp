#include <gtest/gtest.h>
#include <sstream>
#include "headers/DoubleSubscriptedArray.hpp"

TEST(DoubleSubscriptedArrayTest, ConstructorAndSize)
{
    DoubleSubscriptedArray arr(3, 4);
    EXPECT_EQ(arr.getRow(), 3);
    EXPECT_EQ(arr.getColumn(), 4);
    EXPECT_EQ(arr.getSize(), 12);
}

TEST(DoubleSubscriptedArrayTest, DefaultValuesAreZero)
{
    DoubleSubscriptedArray arr(2, 3);
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 3; ++c) {
            EXPECT_EQ(arr(r, c), 0);
        }
    }
}

TEST(DoubleSubscriptedArrayTest, SetAndGetElement)
{
    DoubleSubscriptedArray arr(2, 2);
    arr(0, 1) = 42;
    EXPECT_EQ(arr(0, 1), 42);
}

TEST(DoubleSubscriptedArrayTest, EqualityOperator)
{
    DoubleSubscriptedArray a(2, 2), b(2, 2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;

    b(0, 0) = 1;
    b(0, 1) = 2;
    b(1, 0) = 3;
    b(1, 1) = 4;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(DoubleSubscriptedArrayTest, AssignmentOperator)
{
    DoubleSubscriptedArray a(2, 2);
    a(0, 0) = 10;

    DoubleSubscriptedArray b;
    b = a;

    EXPECT_EQ(b.getRow(), 2);
    EXPECT_EQ(b.getColumn(), 2);
    EXPECT_EQ(b(0, 0), 10);
}

TEST(DoubleSubscriptedArrayTest, InputOperator)
{
    std::istringstream input("1 2 3 4");
    DoubleSubscriptedArray arr(2, 2);
    input >> arr;

    EXPECT_EQ(arr(0, 0), 1);
    EXPECT_EQ(arr(0, 1), 2);
    EXPECT_EQ(arr(1, 0), 3);
    EXPECT_EQ(arr(1, 1), 4);
}

TEST(DoubleSubscriptedArrayTest, OutputOperator)
{
    DoubleSubscriptedArray arr(2, 2);
    arr(0, 0) = 5;
    arr(0, 1) = 6;
    arr(1, 0) = 7;
    arr(1, 1) = 8;

    std::ostringstream out;
    out << arr;

    std::string expected =
        "    5    6\n"
        "    7    8\n";

    EXPECT_EQ(out.str(), expected);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

