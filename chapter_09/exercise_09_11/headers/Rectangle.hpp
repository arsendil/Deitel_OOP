#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

const float MAX_LENGTH = 20.0;
const float MIN_LENGTH = 0.0;

class Rectangle
{
public:
    Rectangle(const float width = 1, const float length = 1);
    Rectangle(const Rectangle& other);
    float area() const;
    float perimeter() const;
    float getWidth() const;
    float getLength() const;
    void setWidth(const float width);
    void setLength(const float length);

private:
    float length_;
    float width_;
};

#endif /// __RECTANGLE_HPP__

