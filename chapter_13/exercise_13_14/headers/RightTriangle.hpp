#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "TwoDimensionalShape.hpp"

class RightTriangle : public TwoDimensionalShape
{
private:
    static bool isRightTriangle(const double sideA, const double sideB, const double sideC);

public:
    RightTriangle(const double sideA = 1, const double sideB = 1, const double sideC = 1, const char fill = '$');
    virtual ~RightTriangle();

    void setRightTriangle(const double sideA, const double sideB, const double sideC);
    void setFill(const char fill);
        
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    char   getFill()  const;

    virtual double getArea() const;
    virtual void print()     const;
    virtual void draw()      const;

private:
    void setSideA(const double side);
    void setSideB(const double side);
    void setSideC(const double side);

private:
    double sideA_;
    double sideB_;
    double sideC_;
    char fill_;
};

#endif /// __TRIANGLE_HPP__

