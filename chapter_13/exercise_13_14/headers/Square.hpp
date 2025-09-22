#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "TwoDimensionalShape.hpp"

class Square : public TwoDimensionalShape
{
public:
    Square(const double side, const char fill = '$');
    virtual ~Square();

    void setSide(const double side);
    void setFill(const char fill);

    double getSide() const;
    char getFill()   const;

    virtual double getArea() const;
    virtual void print()     const;
    virtual void draw()      const;

private:
    double side_;
    char fill_;
};

#endif /// __SQUARE_HPP__
