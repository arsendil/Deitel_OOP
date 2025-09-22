#include "headers/Rectangle.hpp"

#include "gtest/gtest.h"

TEST(Rectangle, area)
{
    Rectangle rectangle1(7.0, 9.0);
    EXPECT_EQ(rectangle1.area(), 63.0);
}

TEST(Rectangle, perimeter)
{
    Rectangle rectangle1(5.5, 5.0);
    EXPECT_EQ(rectangle1.perimeter(), 21.0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

