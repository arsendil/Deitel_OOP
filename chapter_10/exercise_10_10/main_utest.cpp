#include "headers/Time.hpp"
#include <gtest/gtest.h>

TEST(TimeTest, ParameterizedConstructor)
{
    Time t(12, 30, 45);
    t.setHour(6);
    t.setMinute(56);
    t.setSecond(54);
    EXPECT_EQ(t.getHour(), 6);
    EXPECT_EQ(t.getMinute(), 56);
    EXPECT_EQ(t.getSecond(), 54);
}

TEST(TimeTest, SetTimeValid)
{
    Time t(23, 59, 59);
    EXPECT_EQ(t.getHour(), 23);
    EXPECT_EQ(t.getMinute(), 59);
    EXPECT_EQ(t.getSecond(), 59);
}

TEST(TimeTest, SetTimeInvalid)
{
    Time t(23, 0, 0);
    EXPECT_EQ(t.getHour(), 23);
    EXPECT_EQ(t.getMinute(), 0);
    EXPECT_EQ(t.getSecond(), 0);
}

int
main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

