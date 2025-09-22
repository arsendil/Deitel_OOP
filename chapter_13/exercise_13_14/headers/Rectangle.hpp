#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "TwoDimensionalShape.hpp"

class Rectangle : public TwoDimensionalShape
{
public:
    Rectangle(const double width = 1, const double length = 1, const char fill = '$');
    virtual ~Rectangle();
    
    void setWidth(const double with);
    void setLength(const double length);
    void setFill(const char fill);

    double getWidth()   const;
    double getLength()  const;
    char getFill()      const; 
    
    virtual void draw()      const; 
    virtual double getArea() const;
    virtual void print()     const;

private:
    double width_;
    double length_;
    char fill_;
};

#endif /// __SQUARE_HPP__

