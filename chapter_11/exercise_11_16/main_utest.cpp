#include <gtest/gtest.h>
#include "headers/String.hpp"

TEST(StringTest, ConstructorAndGetLength)
{
    String s("hello");
    EXPECT_EQ(s.getLength(), 5);
}

TEST(StringTest, CopyConstructor)
{
    String s1("abc");
    String s2(s1);
    EXPECT_STREQ(s2, "abc");
}

TEST(StringTest, AssignmentOperator)
{
    String s1("foo");
    String s2;
    s2 = s1;
    EXPECT_STREQ(s2, "foo");
}

TEST(StringTest, PlusEqualOperator)
{
    String s1("abc");
    String s2("def");
    s1 += s2;
    EXPECT_STREQ(s1, "abcdef");
}

TEST(StringTest, PlusOperator)
{
    String s1("abc");
    String s2("123");
    String s3 = s1 + s2;
    EXPECT_STREQ(s3, "abc123");
}

TEST(StringTest, LogicalNot)
{
    String s1("");
    String s2("not empty");
    EXPECT_TRUE(!s1);
    EXPECT_FALSE(!s2);
}

TEST(StringTest, EqualityOperators)
{
    String s1("abc");
    String s2("abc");
    String s3("xyz");

    EXPECT_TRUE(s1 == s2);
    EXPECT_TRUE(s1 != s3);
    EXPECT_TRUE(s1 < s3);
    EXPECT_TRUE(s3 > s1);
    EXPECT_TRUE(s1 <= s2);
    EXPECT_TRUE(s3 >= s1);
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
    String s("hello");
    String sub = s(1, 3);
    EXPECT_STREQ(sub, "ell");
}

TEST(StringTest, TypeConversionOperator)
{
    String s("text");
    const char* cstr = s;
    EXPECT_STREQ(cstr, "text");
}

TEST(StringTest, Strlen_)
{
    String s("length");
    EXPECT_EQ(s.strlen_("length"), 6);
}

TEST(StringTest, Strcpy_)
{
    String s1("abc");
    String s2("12345");
    s2.strcpy_(s1);
    EXPECT_STREQ(s2, "abc");
}

TEST(StringTest, Strncpy_)
{
    String s1("abcdef");
    String s2("xxxxxxx");
    s2.strncpy_(s1, 3);
    EXPECT_STREQ(s2, "abc");
}

TEST(StringTest, Strcat_)
{
    String s1("hi");
    String s2(" there");
    s1.strcat_(s2);
    EXPECT_STREQ(s1, "hi there");
}

TEST(StringTest, Strncat_)
{
    String s1("hi");
    String s2(" there");
    s1.strncat_(s2, 3);
    EXPECT_STREQ(s1, "hi th");
}

TEST(StringTest, Strcmp_)
{
    String s1("abc");
    String s2("abc");
    String s3("abd");
    EXPECT_EQ(s1.strcmp_(s2), 0);
    EXPECT_LT(s1.strcmp_(s3), 0);
}

TEST(StringTest, Strncmp_)
{
    String s1("abcdef");
    String s2("abcxyz");
    EXPECT_EQ(s1.strncmp_(s2, 3), 0);
    EXPECT_LT(s1.strncmp_(s2, 4), 0);
}

TEST(StringTest, Strstr_)
{
    String s1("hello world");
    String s2("world");
    String s3("bye");
    EXPECT_TRUE(s1.strstr_(s2));
    EXPECT_FALSE(s1.strstr_(s3));
}

TEST(StringTest, Strchr_)
{
    String s("banana");
    char* p = s.strchr_('n');
    EXPECT_EQ(*p, 'n');
    EXPECT_EQ(p - (const char*)s, 2);
}

TEST(StringTest, Strrchr_)
{
    String s("banana");
    char* p = s.strrchr_('a');
    EXPECT_EQ(*p, 'a');
    EXPECT_EQ(p - (const char*)s, 5);
}

TEST(StringStrtokTest, SimpleCommaDelimited)
{
    String s("one,two,three");
    char* token = s.strtok_((char*)(const char*)s, ",");

    ASSERT_STREQ("one", token);
    token = s.strtok_(0, ",");
    ASSERT_STREQ("two", token);
    token = s.strtok_(0, ",");
    ASSERT_STREQ("three", token);
    token = s.strtok_(0, ",");
    ASSERT_EQ(0, token);
}

TEST(StringStrtokTest, SpaceDelimited)
{
    String s("apple banana cherry");
    char* token = s.strtok_((char*)(const char*)s, " ");

    ASSERT_STREQ("apple", token);
    token = s.strtok_(0, " ");
    ASSERT_STREQ("banana", token);
    token = s.strtok_(0, " ");
    ASSERT_STREQ("cherry", token);
    token = s.strtok_(0, " ");
    ASSERT_EQ(0, token);
}

TEST(StringStrtokTest, MultipleDelimiters)
{
    String s("dog,cat;bird fish");
    char* token = s.strtok_((char*)(const char*)s, ",; ");

    ASSERT_STREQ("dog", token);
    token = s.strtok_(0, ",; ");
    ASSERT_STREQ("cat", token);
    token = s.strtok_(0, ",; ");
    ASSERT_STREQ("bird", token);
    token = s.strtok_(0, ",; ");
    ASSERT_STREQ("fish", token);
    token = s.strtok_(0, ",; ");
    ASSERT_EQ(0, token);
}

TEST(StringStrtokTest, AllDelimitersOnly)
{
    String s(",,,;;  ,;");
    char* token = s.strtok_((char*)(const char*)s, ",; ");
    ASSERT_EQ(0, token);
}

TEST(StringStrtokTest, EmptyString)
{
    String s("");
    char* token = s.strtok_((char*)(const char*)s, ",");
    ASSERT_EQ(0, token);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

