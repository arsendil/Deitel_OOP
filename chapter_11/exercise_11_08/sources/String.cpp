#include "../headers/String.hpp"
#include <cstddef>

String::String(const char* expression)
    : length_((expression != NULL) ? strlen(expression) : 0)
    , sPtr_(NULL)
{
    setString(expression);
}


String::String(const String& rhv)
    : length_(rhv.length_)
    , sPtr_(NULL)
{
    setString(rhv.sPtr_);
}

String::String(const size_t count, const char choice)
    : length_(static_cast<int>(count))
    , sPtr_(NULL)
{
    sPtr_ = new char[length_ + 1];
    for (int i = 0; i < length_; ++i) {
        sPtr_[i] = choice;
    }
    sPtr_[length_] = '\0';
}

String::~String()
{
    if (NULL != sPtr_) {
        delete[] sPtr_;
        sPtr_ = NULL;
    }
}

const String&
String::operator=(const String& rhv)
{
    if (this == &rhv) return *this;
    if (getLength() == rhv.getLength()) {
        std::strcpy(sPtr_, rhv.sPtr_);
        return *this;
    }
    delete[] sPtr_;
    length_ = rhv.length_;
    setString(rhv.sPtr_);
    return *this;
}

const String&
String::operator+=(const String& rhv)
{
    const size_t newLength = length_ + rhv.length_;
    char* tempPtr = new char[newLength + 1];

    std::strcpy(tempPtr, sPtr_);
    std::strcpy(tempPtr + length_, rhv.sPtr_);

    delete[] sPtr_;
    sPtr_ = tempPtr;
    length_ = newLength;

    return *this;
}

String
String::operator+(const String& rhv) const
{
    String temp;
    temp.length_ = length_ + rhv.length_;
    temp.sPtr_ = new char[temp.length_ + 1];

    std::strcpy(temp.sPtr_, sPtr_);
    std::strcat(temp.sPtr_, rhv.sPtr_);
    return temp;
}

bool
String::operator!() const
{
    return 0 == length_;
}

bool
String::operator==(const String& rhv) const
{
    if (sPtr_ == NULL || rhv.sPtr_ == NULL) return true;
    return 0 == std::strcmp(sPtr_, rhv.sPtr_);
}



bool
String::operator<(const String& rhv) const
{
    return std::strcmp(sPtr_, rhv.sPtr_) < 0;
}

bool
String::operator!=(const String& rhv) const
{ 
    return !(*this == rhv);
}

bool
String::operator>(const String& rhv) const
{
    return rhv < *this;
}
 
bool
String::operator<=(const String& rhv) const
{
    return !(rhv < *this);
}

bool
String::operator>=(const String& rhv) const
{
    return !(*this < rhv);
}

char&
String::operator[](const int subscript)
{
    assert(subscript >= 0 && subscript < length_);
    return sPtr_[subscript];
}

char
String::operator[](const int subscript) const
{
    assert(subscript >= 0 && subscript < length_);
    return sPtr_[subscript];
}

const String
String::operator()(const int index, const int subLength) const
{
    assert(index >= 0 && index < length_ && subLength >= 0 && subLength < length_);
    const int len = (0 == subLength || index + subLength > length_)
              ? length_ - index
              : subLength;

    String temp;
    temp.length_ = len;
    temp.sPtr_ = new char[len + 1];
    
    std::strncpy(temp.sPtr_, &sPtr_[index], len);
    temp.sPtr_[len] = '\0';
    return temp;
}

String::operator const char*() const
{
    return sPtr_;
}

int
String::getLength() const
{
    return length_;
}

void
String::setString(const char* expression)
{
    if (expression != NULL && std::strlen(expression) != 0) {
        sPtr_ = new char[length_ + 1];
        std::strcpy(sPtr_, expression);
        return;
    }
    sPtr_ = NULL;
}

std::ostream& 
operator<<(std::ostream& output, const String& expression)
{
    output << expression.sPtr_;
    return output;
}

std::istream&
operator>>(std::istream& input, String& expression)
{
    char temp[SIZE];
    input >> std::setw(SIZE) >> temp;
    expression = temp;
    return input;
}
