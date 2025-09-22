#include "headers/DateAndTime.hpp"

#include "gtest/gtest.h"

TEST(DateAndTimeT, EndOfMonthToNext)
{
    DateAndTime date(4, 30, 2025, 23, 59, 59);
    date.tick();
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 5);
}

TEST(DateAndTime, EndOfYearToNext)
{
    DateAndTime date(12, 31, 2025, 23, 59, 59);
    date.tick();
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getYear(), 2026);
}

TEST(DateAndTime, tick1)
{
    DateAndTime date(4, 11, 2024, 1, 59, 59);
    date.tick();

    EXPECT_EQ(date.getHour(), 2);
    EXPECT_EQ(date.getMinute(), 0);
    EXPECT_EQ(date.getSecond(), 0);

}

TEST(DateAndTime, tick2)
{
    DateAndTime date(4, 11, 2024, 12, 0, 59);
    date.tick();

    EXPECT_EQ(date.getHour(), 12);
    EXPECT_EQ(date.getMinute(), 1);
    EXPECT_EQ(date.getSecond(), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

