#include "headers/Date.hpp"
#include "gtest/gtest.h"

TEST(Date, IncrementToNextMonth)
{
    Date date(1, 31, 2024); 
    date.nextDay();
    EXPECT_EQ(date.getMonth(), 2);
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getYear(), 2024);
}

TEST(Date, IncrementToNextYear)
{
    Date date(12, 31, 2024);
    date.nextDay();
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getYear(), 2025);
}

TEST(Date, LeapYearFebruary)
{
    Date date(2, 28, 2024);
    date.nextDay();
    EXPECT_EQ(date.getMonth(), 2);
    EXPECT_EQ(date.getDay(), 29);
    EXPECT_EQ(date.getYear(), 2024);
}

TEST(Date, NonLeapYearFebruary)
{
    Date date(2, 28, 2023);
    date.nextDay();
    EXPECT_EQ(date.getMonth(), 3);
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getYear(), 2023);
}

TEST(Date, SimpleIncrement)
{
    Date date(5, 15, 2025);
    date.nextDay();
    EXPECT_EQ(date.getMonth(), 5);
    EXPECT_EQ(date.getDay(), 16);
    EXPECT_EQ(date.getYear(), 2025);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

