#include "headers/DoubleSubscriptedArray.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(DoubleSubscriptedArrayTest, DefaultConstructor)
{
    DoubleSubscriptedArray array;
    EXPECT_EQ(array.getRow(), 1);
    EXPECT_EQ(array.getColumn(), 1);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(DoubleSubscriptedArrayTest, CustomConstructor)
{
    DoubleSubscriptedArray array(3, 4);
    EXPECT_EQ(array.getRow(), 3);
    EXPECT_EQ(array.getColumn(), 4);
    EXPECT_EQ(array.getSize(), 12);
}

TEST(DoubleSubscriptedArrayTest, InputSortDescending)
{
    DoubleSubscriptedArray array(2, 3);
    std::istringstream input("5 1 3 2 6 4");
    input >> array;

    EXPECT_EQ(array(0, 0), 6);
    EXPECT_EQ(array(0, 1), 5);
    EXPECT_EQ(array(0, 2), 4);
    EXPECT_EQ(array(1, 0), 3);
    EXPECT_EQ(array(1, 1), 2);
    EXPECT_EQ(array(1, 2), 1);
}

TEST(DoubleSubscriptedArrayTest, OutputFormat)
{
    DoubleSubscriptedArray array(1, 3);
    std::istringstream input("3 2 1");
    input >> array;

    std::ostringstream output;
    output << array;
    EXPECT_EQ(output.str(), "    3    2    1\n");
}

TEST(DoubleSubscriptedArrayTest, EqualityTrue)
{
    DoubleSubscriptedArray a(2, 2);
    std::istringstream in("1 2 3 4");
    in >> a;

    DoubleSubscriptedArray b(2, 2);
    std::istringstream in2("4 3 2 1");
    in2 >> b;

    EXPECT_TRUE(a == b);
}

TEST(DoubleSubscriptedArrayTest, EqualityFalseDifferentSize)
{
    DoubleSubscriptedArray a(2, 2), b(3, 2);
    EXPECT_FALSE(a == b);
}

TEST(DoubleSubscriptedArrayTest, InequalityOperator)
{
    DoubleSubscriptedArray a(2, 2), b(2, 2);
    std::istringstream in("1 2 3 4");
    std::istringstream in2("4 3 2 2");
    in >> a;
    in2 >> b;
    EXPECT_TRUE(a != b);
}

TEST(DoubleSubscriptedArrayTest, AssignmentOperator)
{
    DoubleSubscriptedArray a(2, 2), b(1, 1);
    std::istringstream in("1 2 3 4");
    in >> a;
    b = a;
    EXPECT_TRUE(a == b);
}

TEST(DoubleSubscriptedArrayTest, CopyConstructor)
{
    DoubleSubscriptedArray a(2, 2);
    std::istringstream in("1 2 3 4");
    in >> a;
    DoubleSubscriptedArray b(a);
    EXPECT_TRUE(a == b);
}

TEST(DoubleSubscriptedArrayTest, SelfAssignment)
{
    DoubleSubscriptedArray a(2, 2);
    std::istringstream in("4 3 2 1");
    in >> a;
    a = a;
    EXPECT_EQ(a(0, 0), 4);
}

TEST(DoubleSubscriptedArrayTest, ModifyElementTriggersSort)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;
    array(1, 1) = 10;
    EXPECT_EQ(array(0, 0), 10);
}

TEST(DoubleSubscriptedArrayTest, MaxElementTracking)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;
    EXPECT_EQ(array(0, 0), 4);
}

TEST(DoubleSubscriptedArrayTest, ChangeGreatestAndCheckAgain)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;

    EXPECT_EQ(array(0, 0), 4);
    array(0, 1) = 99;
    EXPECT_EQ(array(0, 0), 99);
}

TEST(DoubleSubscriptedArrayTest, ManualInputAndSortWithPrint)
{
    DoubleSubscriptedArray arr(2, 3);

    arr(0, 0) = 5;
    arr(0, 1) = 1;
    arr(0, 2) = 9;
    arr(1, 0) = 3;
    arr(1, 1) = 7;
    arr(1, 2) = 2;


    EXPECT_EQ(arr(0, 0), 9);
    EXPECT_EQ(arr(0, 1), 7);
    EXPECT_EQ(arr(0, 2), 5);
    EXPECT_EQ(arr(1, 0), 3);
    EXPECT_EQ(arr(1, 1), 2);
    EXPECT_EQ(arr(1, 2), 1);

    std::ostringstream oss;
    oss << arr;
    std::string expectedOutput =
        "    9    7    5\n"
        "    3    2    1\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(DoubleSubscriptedArrayTest, InputStreamSortsCorrectly)
{
    DoubleSubscriptedArray arr(2, 3);

    std::istringstream iss("5 1 9 3 7 2");
    iss >> arr;

    EXPECT_EQ(arr(0, 0), 9);
    EXPECT_EQ(arr(0, 1), 7);
    EXPECT_EQ(arr(0, 2), 5);
    EXPECT_EQ(arr(1, 0), 3);
    EXPECT_EQ(arr(1, 1), 2);
    EXPECT_EQ(arr(1, 2), 1);

    std::ostringstream oss;
    oss << arr;
    std::string expectedOutput =
        "    9    7    5\n"
        "    3    2    1\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
