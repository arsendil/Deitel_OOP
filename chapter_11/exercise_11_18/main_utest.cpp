#include <gtest/gtest.h>
#include "headers/PhoneNumber.hpp"
#include <sstream>

TEST(PhoneNumberTest, ValidConstructor)
{
    PhoneNumber number("(987) 654-3210");
    EXPECT_EQ(number.getAreaCod(), 987);
    EXPECT_EQ(number.getExchange(), 654);
    EXPECT_EQ(number.getLine(), 3210);
}

TEST(PhoneNumberTest, IsPhoneNumberValidation)
{
    EXPECT_TRUE(PhoneNumber::isPhoneNumber("(111) 222-3333"));
    EXPECT_FALSE(PhoneNumber::isPhoneNumber("1234567890"));
    EXPECT_FALSE(PhoneNumber::isPhoneNumber("(123)456-7890"));
    EXPECT_FALSE(PhoneNumber::isPhoneNumber("(123 456-7890"));
}

TEST(PhoneNumberTest, OutputOperatorAsMember)
{
    PhoneNumber number("(123) 456-7890");
    std::ostringstream oss;
    number.operator<<(oss);
    EXPECT_EQ(oss.str(), "(123) 456-7890");
}

TEST(PhoneNumberTest, OutputOperatorAsNonMember)
{
    PhoneNumber number("(123) 456-7890");
    std::ostringstream oss;
    oss << number;
    EXPECT_EQ(oss.str(), "(123) 456-7890");
}

TEST(PhoneNumberTest, InputOperator)
{
    std::istringstream iss("123 456 7890");
    PhoneNumber number;
    iss >> number;
    EXPECT_EQ(number.getAreaCod(), 123);
    EXPECT_EQ(number.getExchange(), 456);
    EXPECT_EQ(number.getLine(), 7890);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

