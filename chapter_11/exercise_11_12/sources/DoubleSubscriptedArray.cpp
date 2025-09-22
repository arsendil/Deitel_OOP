#include "../headers/DoubleSubscriptedArray.hpp"
#include <cstddef>

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

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& rhv)
    : row_(rhv.getRow())
    , column_(rhv.getColumn())
{
    array_ = new int[getSize()]; 
    for (int i = 0; i < getSize(); ++i) {
        array_[i] = rhv.array_[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    if (NULL != array_) {
        delete [] array_;
        array_ = NULL;
    }
}

Proxy
DoubleSubscriptedArray::operator()(const int row, const int column)
{
    assert(row < row_ && row >= 0 && column < column_ && column >= 0);
    const int index = row * getColumn() + column;
    return Proxy(*this, index);
}

int
DoubleSubscriptedArray::operator()(const int row, const int column) const
{
    assert(row < row_ && row >= 0 && column < column_ && column >= 0);
    return array_[row * getColumn() + column];
}

bool
DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& rhv) const
{
    if (this == &rhv)                 return true;
    if ((getSize() != rhv.getSize())) return false;

    for (int i = 0; i < getSize(); ++i) {
        if (array_[i] != rhv.array_[i]) {
            return false;
        }
    }
    return true;
}

bool
DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& rhv) const
{
    return !(*this == rhv); 
}

const DoubleSubscriptedArray&
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& rhv)
{
    if (&rhv == this) return *this;

    if (getSize() != rhv.getSize()) {
        delete [] array_;
        setColumn(rhv.getColumn());
        setRow(rhv.getRow());
        array_ = new int[getSize()];
    }
    for (int i = 0; i  < getSize(); ++i) {
        array_[i] = rhv.array_[i];
    }
    return *this;
}

void
DoubleSubscriptedArray::sortingArray()
{
    int k = 0;
    for (int i = 0; i < getSize() - 1; ++i) {
        for (int j = 0; j < getSize() - i - 1; ++j) {
            if (array_[j] < array_[j + 1]) {
                std::swap(array_[j], array_[j + 1]);
                ++k;
            }
        }
        if (0 == k) break;
    }
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

int
DoubleSubscriptedArray::getSize() const
{
    return getRow() * getColumn();
}

std::istream&
operator>>(std::istream& input, DoubleSubscriptedArray& matrix)
{
    for (int i = 0; i < matrix.getSize(); ++i) {
        input >> matrix.array_[i];
    }
    matrix.sortingArray();
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

