#include <gtest/gtest.h>
#include "headers/Rectangle.hpp"
#include "headers/Point.hpp"
#include <iostream>
#include <sstream>

Rectangle createTestRectangle()
{
    Point A(5, 5);
    Point B(15, 5);
    Point C(15, 10);
    Point D(5, 10);
    return Rectangle(A, B, C, D, '&', '*');
}

TEST(RectangleTest, ValidConstructionAndGetters)
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r(A, B, C, D);

    EXPECT_DOUBLE_EQ(r.getCoordinateA().x_, 0.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateA().y_, 0.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateB().x_, 0.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateB().y_, 2.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateC().x_, 3.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateC().y_, 2.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateD().x_, 3.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateD().y_, 0.0);
}

TEST(RectangleTest, CorrectAreaPerimeter)
{
    Rectangle r(Point(1, 1), Point(1, 4), Point(5, 4), Point(5, 1));
    EXPECT_DOUBLE_EQ(r.length(), 4.0);
    EXPECT_DOUBLE_EQ(r.width(), 3.0);
    EXPECT_DOUBLE_EQ(r.perimeter(), 14.0);
    EXPECT_DOUBLE_EQ(r.area(), 12.0);
}

TEST(RectangleTest, IsSquareTrue)
{
    Rectangle r(Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0));
    EXPECT_TRUE(r.square());
}

TEST(RectangleTest, IsSquareFalse)
{
    Rectangle r(Point(0, 0), Point(0, 2), Point(3, 2), Point(3, 0));
    EXPECT_FALSE(r.square());
}

TEST(RectangleTest, SetCoordinatesCorrectly)
{
    Rectangle r(Point(1, 1), Point(1, 2), Point(2, 2), Point(2, 1));
    Point A(2, 2), B(2, 5), C(6, 5), D(6, 2);
    r.setCoordinates(A, B, C, D);
    EXPECT_DOUBLE_EQ(r.getCoordinateA().x_, 2.0);
    EXPECT_DOUBLE_EQ(r.getCoordinateB().y_, 5.0);
    EXPECT_DOUBLE_EQ(r.area(), 12.0);
}

TEST(RectanglePerimeter, DrawExactAsciiTest)
{
    Point A(0, 9);
    Point B(9, 0);
    Point C(11, 2);
    Point D(2, 11);
    Rectangle rectangle(A, B, C, D, '$', '*');

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    rectangle.draw();

    std::cout.rdbuf(oldCout);

    std::string expectedOutput =
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "                          \n"
        "  *                       \n"
        " *$*                      \n"
        "*$$$*                     \n"
        " *$$$*                    \n"
        "  *$$$*                   \n"
        "   *$$$*                  \n"
        "    *$$$*                 \n"
        "     *$$$*                \n"
        "      *$$$*               \n"
        "       *$$$*              \n"
        "        *$*               \n"
        "         *                \n";

    EXPECT_EQ(buffer.str(), expectedOutput);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

