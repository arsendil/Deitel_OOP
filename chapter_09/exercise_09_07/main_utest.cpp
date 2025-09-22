#include "headers/Time.hpp"

#include "gtest/gtest.h"

TEST(Time, tick1)
{
    Time time1(12, 0, 59);
    time1.tick();

    EXPECT_EQ(time1.getHour(), 12);
    EXPECT_EQ(time1.getMinute(), 1);
    EXPECT_EQ(time1.getSecond(), 0);
}

TEST(Time, tick2)
{
    Time time2(1, 59, 59);
    time2.tick();

    EXPECT_EQ(time2.getHour(), 2);
    EXPECT_EQ(time2.getMinute(), 0);
    EXPECT_EQ(time2.getSecond(), 0);
}

TEST(Time, tick3)
{
    Time time3(23, 59, 59);
    time3.tick();

    EXPECT_EQ(time3.getHour(), 0);
    EXPECT_EQ(time3.getMinute(), 0);
    EXPECT_EQ(time3.getSecond(), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
