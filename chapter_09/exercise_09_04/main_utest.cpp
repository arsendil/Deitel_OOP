#include "headers/Time.hpp"

#include "gtest/gtest.h"
#include <ctime>


TEST(Time, displayTime)
{
    Time myTime;
    myTime.displayTime();
    time_t now = std::time(0);
    tm* localTime = std::localtime(&now);

    EXPECT_EQ(myTime.getHour(), localTime -> tm_hour);
    EXPECT_EQ(myTime.getMinute(), localTime -> tm_min);
    EXPECT_EQ(myTime.getSecond(), localTime -> tm_sec);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
