#include "gtest/gtest.h"
#include "headers/Circle.hpp"
#include "headers/Square.hpp"
#include "headers/Triangle.hpp"
#include "headers/Sphere.hpp"
#include "headers/Cube.hpp"
#include "headers/Tetrahedron.hpp"
#include <vector>

TEST(CircleTest, AreaCalculation)
{
    Circle c(5.0);
    const double expected = M_PI * 5.0 * 5.0;
    EXPECT_NEAR(expected, c.getArea(), 1e-6);
}

TEST(SquareTest, AreaCalculation)
{
    Square s(4.0);
    EXPECT_DOUBLE_EQ(16.0, s.getArea());
}

TEST(TriangleTest, ValidTriangle)
{
    Triangle t(3, 4, 5);
    const double s = (3+4+5)/2.0;
    const double expected = sqrt(s * (s-3) * (s-4) * (s-5));
    EXPECT_NEAR(expected, t.getArea(), 1e-6);
}

TEST(SphereTest, SurfaceAreaAndVolume)
{
    Sphere s(2.0);
    const double expectedArea = 4.0 * M_PI * 2.0 * 2.0;
    const double expectedVolume = 4.0/3.0 * M_PI * 2.0 * 2.0 * 2.0;
    EXPECT_NEAR(expectedArea, s.getArea(), 1e-6);
    EXPECT_NEAR(expectedVolume, s.getVolume(), 1e-6);
}

TEST(CubeTest, SurfaceAreaAndVolume)
{
    Cube c(3.0);
    EXPECT_DOUBLE_EQ(54.0, c.getArea());
    EXPECT_DOUBLE_EQ(27.0, c.getVolume());
}

TEST(TetrahedronTest, SurfaceAreaAndVolume)
{
    Tetrahedron t(2.0);
    const double expectedArea = sqrt(3.0) * 4.0;
    const double expectedVolume = (8.0) / (6.0 * sqrt(2.0));
    EXPECT_NEAR(expectedArea, t.getArea(), 1e-6);
    EXPECT_NEAR(expectedVolume, t.getVolume(), 1e-6);
}

TEST(Shape, printTest)
{
    std::vector<Shape*> ptr;    
    ptr.push_back(new Cube(4));
    ptr.push_back(new Triangle(3, 4, 5));
    ptr.push_back(new Circle(5));
    ptr.push_back(new Sphere(4));
    ptr.push_back(new Tetrahedron(6));
    ptr.push_back(new Square(8));
    
    for (size_t i = 0; i < ptr.size(); ++i) {
        ptr[i]->print();
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

