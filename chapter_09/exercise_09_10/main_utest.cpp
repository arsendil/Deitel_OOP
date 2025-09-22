#include "headers/Time.hpp"

#include "gtest/gtest.h"

TEST(Time, tick)
{
    Time time1(12, 2, 96);

    EXPECT_EQ(time1.getHour(), 12);
    EXPECT_EQ(time1.getMinute(), 2);
    EXPECT_EQ(time1.getSecond(), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
