#include "headers/IntegerSet.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>

TEST(IntegerSetTest, DefaultConstructorCreatesEmptySet)
{
    IntegerSet set;
    for (int i = 0; i < SIZE; ++i) {
        EXPECT_FALSE(set.getElement(i));
    }
}

TEST(IntegerSetTest, ConstructorFromArrayInitializesCorrectly)
{
    int arr[] = {0, 3, 5, 100};
    IntegerSet set(arr, 4);
    for (int i = 0; i < SIZE; ++i) {
        if (i == 0 || i == 3 || i == 5 || i == 100) {
            EXPECT_TRUE(set.getElement(i));
        } else {
            EXPECT_FALSE(set.getElement(i));
        }
    }
}

TEST(IntegerSetTest, InsertAndDeleteElement)
{
    IntegerSet set;
    set.insertElement(10);
    EXPECT_TRUE(set.getElement(10));
    set.deleteElement(10);
    EXPECT_FALSE(set.getElement(10));
}

TEST(IntegerSetTest, UnionOfSetsWorks)
{
    int a1[] = {1, 3, 5};
    int a2[] = {2, 3, 6};
    IntegerSet set1(a1, 3);
    IntegerSet set2(a2, 3);
    IntegerSet result = set1.unionOfSets(set2);

    EXPECT_TRUE(result.getElement(1));
    EXPECT_TRUE(result.getElement(2));
    EXPECT_TRUE(result.getElement(3));
    EXPECT_TRUE(result.getElement(5));
    EXPECT_TRUE(result.getElement(6));
    EXPECT_FALSE(result.getElement(0));
    EXPECT_FALSE(result.getElement(4));
}

TEST(IntegerSetTest, IntersectionOfSetsWorks)
{
    int a1[] = {1, 3, 5};
    int a2[] = {2, 3, 5};
    IntegerSet set1(a1, 3);
    IntegerSet set2(a2, 3);
    IntegerSet result = set1.intersectionOfSets(set2);

    EXPECT_TRUE(result.getElement(3));
    EXPECT_TRUE(result.getElement(5));
    EXPECT_FALSE(result.getElement(1));
    EXPECT_FALSE(result.getElement(2));
}

TEST(IntegerSetTest, IsEqualToTrueWhenSame)
{
    int a1[] = {10, 20, 30};
    int a2[] = {10, 20, 30};
    IntegerSet set1(a1, 3);
    IntegerSet set2(a2, 3);
    EXPECT_TRUE(set1.isEqualTo(set2));
}

TEST(IntegerSetTest, IsEqualToFalseWhenDifferent)
{
    int a1[] = {10, 20, 30};
    int a2[] = {10, 20};
    IntegerSet set1(a1, 3);
    IntegerSet set2(a2, 2);
    EXPECT_FALSE(set1.isEqualTo(set2));
}

TEST(IntegerSetTest, CopyConstructorWorks)
{
    int a1[] = {1, 2, 3};
    IntegerSet original(a1, 3);
    IntegerSet copy(original);

    EXPECT_TRUE(copy.isEqualTo(original));
    copy.insertElement(4);
    EXPECT_FALSE(copy.isEqualTo(original));
}

TEST(IntegerSetTest, PrintSet_NonEmptySet)
{
    IntegerSet set;
    set.insertElement(1);
    set.insertElement(42);
    set.insertElement(100);

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    set.printSet();

    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    EXPECT_EQ(output, "1 42 100 \n");
}

TEST(IntegerSetTest, PrintSet_EmptySet) {
    IntegerSet set;

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    set.printSet();

    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    EXPECT_EQ(output, "---\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

