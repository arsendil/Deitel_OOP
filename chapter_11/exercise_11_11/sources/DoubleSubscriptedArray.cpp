#include "../headers/DoubleSubscriptedArray.hpp"

#include <cassert>
#include <cstddef>
#include <iomanip>

DoubleSubscriptedArray::DoubleSubscriptedArray(const int row, const int column)
{
    assert(row > 0 && column > 0);
    setColumn(column);
    setRow(row);
    array_ = new int[getSize()];

    for (int i = 0; i < getSize(); ++i) {
        array_[i] = 0;
    }
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& other) 
    : row_(other.getRow()),
      column_(other.getColumn())
{
    array_ = new int[getSize()];
    for (int i= 0; i < getSize(); ++i) {
        array_[i] = other.array_[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    if (NULL != array_) {
        delete [] array_;
        array_ = NULL;
    }
}

int& 
DoubleSubscriptedArray::operator()(const int row, const int column)
{
    assert(row < row_ && row >= 0 && column < column_ && column >= 0);
    return array_[row * getColumn() + column];
}

int
DoubleSubscriptedArray::getSize() const
{
    return getRow() * getColumn();
}

int
DoubleSubscriptedArray::operator()(const int row, const int column) const
{
    assert(row < row_ && row >= 0 && column < column_ && column >= 0);
    return array_[row * getColumn() + column];
}

bool
DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& other) const
{
    if (this == &other)               return true; 
    if (getSize() != other.getSize()) return false;
    for (int i = 0; i < getSize(); ++i) {
        if (array_[i] != other.array_[i]) {
            return false;
        }
    }
    return true;
}

bool
DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& other) const
{
    return ! (*this == other);
}

const DoubleSubscriptedArray& 
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& other)
{
    if (&other == this) return *this;
    if (getSize() != other.getSize()) {
        delete [] array_;
        setColumn(other.getColumn());
        setRow(other.getRow());
        array_ = new int[getSize()];
    }
    for (int i = 0; i < getSize(); ++i) {
        array_[i] = other.array_[i];
    }

    return *this;
}

void
DoubleSubscriptedArray::setRow(const int row)
{
    assert(row > 0);
    row_ = row;
}

void
DoubleSubscriptedArray::setColumn(const int column)
{
    assert(column > 0);
    column_ = column;
}

int
DoubleSubscriptedArray::getRow() const
{
    return row_;
}

int
DoubleSubscriptedArray::getColumn() const
{
    return column_;
}

std::istream&
operator>>(std::istream& input, DoubleSubscriptedArray& matrix)
{
    for (int i = 0; i < matrix.getSize(); ++i) {
        input >> matrix.array_[i];
    }
    return input;
}

std::ostream&
operator<<(std::ostream& output, const DoubleSubscriptedArray& matrix)
{
    for (int row = 0; row < matrix.row_; ++row) {
        for (int column = 0; column < matrix.column_; ++column) {
            output << std::setw(5) << matrix(row, column);
        }
        output << '\n';
    }
    return output;
}

