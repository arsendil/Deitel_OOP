#include "headers/Date.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <cstring>
#include <cassert>
#include <cctype> 

TEST(DateTest, Initialization1) 
{
    Date birth("140 2024");
    EXPECT_EQ(birth.getMonth(), 5);
    EXPECT_EQ(birth.getDay(), 19);
    EXPECT_EQ(birth.getYear(), 2024);
}

TEST(DateTest, Initialization2) 
{
    Date birth("06/30/92");
    EXPECT_EQ(birth.getMonth(), 6);
    EXPECT_EQ(birth.getDay(), 30);
    EXPECT_EQ(birth.getYear(), 92);
}

TEST(DateTest, Initialization3) 
{
    Date birth("June 10, 1992");
    EXPECT_EQ(birth.getMonth(), 6);
    EXPECT_EQ(birth.getDay(), 10);
    EXPECT_EQ(birth.getYear(), 1992);
}

TEST(DateTest, Initialization4) 
{
    Date birth(7, 24, 1949);
    EXPECT_EQ(birth.getMonth(), 7);
    EXPECT_EQ(birth.getDay(), 24);
    EXPECT_EQ(birth.getYear(), 1949);
}

TEST(DateTest, Initialization5) 
{
    Date hire(60, 2024);
    EXPECT_EQ(hire.getMonth(), 2);
    EXPECT_EQ(hire.getDay(), 29);
    EXPECT_EQ(hire.getYear(), 2024);
}

TEST(DateTest, Initialization6) 
{
    Date newYear("December", 31, 2003);
    EXPECT_EQ(newYear.getMonth(), 12);
    EXPECT_EQ(newYear.getDay(), 31);
    EXPECT_EQ(newYear.getYear(), 2003);
}

TEST(DateTest, PrintTextualFormat)
{
    Date date(12, 25, 2023);
        std::ostringstream buffer;
        std::streambuf* prevcout = std::cout.rdbuf(buffer.rdbuf());
    
        date.printTextual();
    
        std::cout.rdbuf(prevcout);
        EXPECT_EQ(buffer.str(), "December 25, 2023\n");
}

TEST(DateFormatTest, GetFormatDetectsInvalid)
{
    EXPECT_EQ(Date::getFormat("blabla"), ERROR);
    EXPECT_EQ(Date::getFormat("12345"), ERROR);
    EXPECT_EQ(Date::getFormat("Jan 35, 2020"), ERROR);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

