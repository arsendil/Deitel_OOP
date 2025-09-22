#include <gtest/gtest.h>
#include "headers/Rectangle.hpp"
#include "headers/Square.hpp"
#include "headers/RightTriangle.hpp"

TEST(RectangleTest, AreaCalculation)
{
    Rectangle r(4, 5, '#');
    EXPECT_DOUBLE_EQ(r.getArea(), 20.0);
}

TEST(RectangleTest, FillCharacter)
{
    Rectangle r(2, 3, '@');
    EXPECT_EQ(r.getFill(), '@');
}

TEST(SquareTest, AreaCalculation)
{
    Square s(5, '*');
    EXPECT_DOUBLE_EQ(s.getArea(), 25.0);
}

TEST(SquareTest, FillCharacter)
{
    Square s(3, '+');
    EXPECT_EQ(s.getFill(), '+');
}

TEST(RightTriangleTest, AreaCalculation)
{
    RightTriangle t(3, 4, 5, '$');
    const double expectedArea = 6.0; 
    EXPECT_NEAR(t.getArea(), expectedArea, 1e-6);
}

TEST(RightTriangleTest, FillCharacter)
{
    RightTriangle t(3, 4, 5, '#');
    EXPECT_EQ(t.getFill(), '#');
}

TEST(TriangleTest, ValidTriangle)
{
    std::vector<Shape*> ptr;    
    ptr.push_back(new RightTriangle(20, 21, 29, '$'));
    ptr.push_back(new Rectangle(5, 10, '$'));
    ptr.push_back(new Square(5, '$'));
    
    for (size_t i = 0; i < ptr.size(); ++i) {
        ptr[i]->print();
        std::cout << std::endl;
        ptr[i]->draw();
        std::cout << std::endl << std::endl;
    }
    for (size_t i = 0; i < ptr.size(); ++i) {
        delete ptr[i];
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
