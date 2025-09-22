#ifndef __DOUBLE_SUBSCRIPTED_ARRAY__
#define __DOUBLE_SUBSCRIPTED_ARRAY__

#include <iostream>

class DoubleSubscriptedArray
{
    friend  std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& matrix);
    friend  std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& matrix);

public:
    DoubleSubscriptedArray(const int row = 1, const int column = 1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray& other);
    ~DoubleSubscriptedArray();

    int& operator()(const int row, const int column);
    int operator()(const int row, const int column) const;
    bool operator==(const DoubleSubscriptedArray& other) const;
    bool operator!=(const DoubleSubscriptedArray& other) const;
    const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& other);

    int getRow() const;
    int getColumn() const;
    int getSize() const;

private:
    void setRow(const int row);
    void setColumn(const int column);

private:
    int row_;
    int column_;
    int* array_; 
};

#endif /// __DOUBLE_SUBSCRIPTED_ARRAY__

