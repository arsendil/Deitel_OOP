#include <gtest/gtest.h>
#include "headers/String.hpp"

TEST(StringTest, ConstructorFromCString)
{
    String s("hello");
    EXPECT_EQ(s.getLength(), 5);
    EXPECT_STREQ(s(0).operator const char*(), "hello");
}

TEST(StringTest, CopyConstructor)
{
    String s1("world");
    String s2(s1);
    EXPECT_EQ(s1.getLength(), s2.getLength());
    EXPECT_TRUE(s1 == s2);
}

TEST(StringTest, AssignmentOperator)
{
    String s1("abc");
    String s2;
    s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(StringTest, PlusEqualsOperator)
{
    String s1("hello");
    String s2(" world");
    s1 += s2;
    EXPECT_EQ(s1.getLength(), 11);
    EXPECT_STREQ(s1(0).operator const char*(), "hello world");
}

TEST(StringTest, PlusOperator)
{
    String s1("foo");
    String s2("bar");
    String s3 = s1 + s2;
    EXPECT_STREQ(s3(0).operator const char*(), "foobar");
}

TEST(StringTest, NotOperator) 
{
    String s1;
    EXPECT_TRUE(!s1);
    String s2("abc");
    EXPECT_FALSE(!s2);
}

TEST(StringTest, ComparisonOperators)
{
    String a("abc");
    String b("abc");
    String c("xyz");

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(c > b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(c >= b);
}

TEST(StringTest, SubscriptOperator)
{
    String s("hello");
    EXPECT_EQ(s[0], 'h');
    s[1] = 'a';
    EXPECT_EQ(s[1], 'a');
}

TEST(StringTest, FunctionCallOperator)
{
    String s("substring");
    String sub = s(3, 3);
    EXPECT_EQ(sub.getLength(), 3);
    EXPECT_STREQ(sub(0).operator const char*(), "str");
}

TEST(StringTest, StreamOutput)
{
    String s("stream");
    std::ostringstream oss;
    oss << s;
    EXPECT_EQ(oss.str(), "stream");
}

TEST(StringTest, StreamInput) 
{
    String s;
    std::istringstream iss("hello123");
    iss >> s;
    EXPECT_EQ(s.getLength(), 8);
    EXPECT_STREQ(s(0).operator const char*(), "hello123");
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

