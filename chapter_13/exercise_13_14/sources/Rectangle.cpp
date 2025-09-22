#include "../headers/Rectangle.hpp"
#include <cctype>

Rectangle::Rectangle(const double width, const double length, const char fill)
{
    setWidth(width);
    setLength(length);
    setFill(fill);
}

Rectangle::~Rectangle()
{}

void
Rectangle::setWidth(const double width)
{
    assert(width > 0);
    width_ = width;
}

void
Rectangle::setLength(const double length)
{
    assert(length > 0);
    length_ = length;
}

void
Rectangle::setFill(const char fill)
{
    assert(std::isprint(fill));
    fill_ = fill;
}

double
Rectangle::getWidth() const
{
    return width_;
}

double
Rectangle::getLength() const
{
    return length_;
}

char
Rectangle::getFill() const
{
    return fill_;
}

double
Rectangle::getArea() const
{
    return getWidth() * getLength();
}

void
Rectangle::print() const
{
    std::cout << "Rectangle (width = " << getWidth() << ", Length = " << getLength()
              << ")\n" << "Area is " << getArea();
}

void
Rectangle::draw() const
{
    const int width = static_cast<int>(getWidth());
    const int length = static_cast<int>(getLength());
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << ((0 == i || 0 == j || i == width - 1 || j == length - 1) ? getFill() : ' ');
        }
        std::cout << std::endl;
    }
}
