#ifndef __DOUBLE_SUBSCRIPTED_ARRAY__
#define __DOUBLE_SUBSCRIPTED_ARRAY__

#include "Proxy.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

class DoubleSubscriptedArray
{
    friend class Proxy;
    friend std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& matrix);
    friend std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& matrix);

public:
    DoubleSubscriptedArray(const int row = 1, const int column = 1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray& rhv);
    ~DoubleSubscriptedArray();

    Proxy operator()(const int row, const int column);
    int operator()(const int row, const int column) const;
    bool operator==(const DoubleSubscriptedArray& rhv) const;
    bool operator!=(const DoubleSubscriptedArray& rhv) const;
    const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& rhv);
    
    int getRow() const;
    int getColumn() const;
    int getSize() const;

private:
    void sortingArray();
    void setRow(const int row);
    void setColumn(const int column);

private:
    int row_;
    int column_;
    int* array_;
};

#endif /// __DOUBLE_SUBSCRIPTED_ARRAY__

