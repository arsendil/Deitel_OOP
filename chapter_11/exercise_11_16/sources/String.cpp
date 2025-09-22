#include "../headers/String.hpp"
#include <cstddef>

String::String(const char* expression) : length_((expression != 0) ? strlen(expression) : 0)
{
    setString(expression);
}

String::String(const String& rhv) : length_(rhv.getLength())
{
    setString(rhv.sPtr_);
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
    length_ = rhv.getLength();
    setString(rhv.sPtr_);
    return *this;
}

const String&
String::operator+=(const String& rhv)
{
    const size_t newLength = getLength() + rhv.getLength();
    char* tempPtr = new char[newLength + 1];

    std::strcpy(tempPtr, sPtr_);
    std::strcpy(tempPtr + getLength(), rhv.sPtr_);

    delete[] sPtr_;
    sPtr_ = tempPtr;
    length_ = newLength;

    return *this;
}

String
String::operator+(const String& rhv) const
{
    String temp = *this;
    temp += rhv;
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
    assert(subscript >= 0 && subscript < getLength());
    return sPtr_[subscript];
}

char
String::operator[](const int subscript) const
{
    assert(subscript >= 0 && subscript < getLength());
    return sPtr_[subscript];
}

const String
String::operator()(const int index, const int subLength) const
{
    assert(index >= 0 && index < getLength() && subLength >= 0 && subLength < getLength());
    const int len = (0 == subLength || index + subLength > getLength())
              ? getLength() - index
              : subLength;

    char *tempPtr = new char[len + 1];
    std::strncpy(tempPtr, &sPtr_[index], len);
    tempPtr[len] = '\0';

    String tempString(tempPtr);
    delete[] tempPtr;

    return tempString;
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

char*
String::strtok_(char* s1, const char* delimiters)
{
    static char* last = 0;

    if (s1 != 0) {
        last = s1;
    } else if (0 == last) {
        return 0;
    }
    while (*last != '\0' && std::strchr(delimiters, *last)) {
        ++last;
    }

    if ('\0' == *last) {
        last = 0;
        return 0;
    }

    char* tokenStart = last;
    while (*last != '\0' && !std::strchr(delimiters, *last)) {
        ++last;
    }

    if (*last != '\0') {
        *last = '\0';
        ++last;
    } else {
        last = 0;
    }
    return tokenStart;
}

int
String::strlen_(const char* s1) const
{
    int i = 0;
    while (s1[i] != '\0') {
        ++i;
    }
    return i;
}

void
String::strcpy_(const String& rhv)
{
    delete[] sPtr_;
    length_ = rhv.getLength();
    setString(rhv.sPtr_);
}

void
String::strncpy_(const String& rhv, const int size)
{
    assert(size >= 0 && size <= rhv.getLength());
    char* temp = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = rhv.sPtr_[i];
    }
    temp[size] = '\0';
    delete[] sPtr_;
    length_ = size;
    sPtr_ = temp;
}

void
String::strcat_(const String& rhv)
{
    char* temp = new char[getLength() + rhv.getLength() + 1];
    for (int i = 0; i < getLength(); ++i) {
        temp[i] = sPtr_[i];
    }
    for (int i = 0; i < rhv.getLength(); ++i) {
        temp[getLength() + i] = rhv.sPtr_[i];
    }
    temp[getLength() + rhv.getLength()] = '\0';

    delete[] sPtr_;
    sPtr_ = temp;
    length_ += rhv.getLength();
}

void
String::strncat_(const String& rhv, const int size)
{
    assert(size >= 0 && size <= rhv.getLength());
    char* temp = new char[getLength() + size + 1];
    for (int i = 0; i < getLength(); ++i) {
        temp[i] = sPtr_[i];
    }
    for (int i = 0; i < size; ++i) {
        temp[getLength() + i] = rhv.sPtr_[i];
    }
    temp[getLength() + size] = '\0';

    delete[] sPtr_;
    sPtr_ = temp;
    length_ += size;
}

int
String::strcmp_(const String& rhv) const
{
    int i = 0;
    while (i < getLength() && i < rhv.getLength()) {
        if (sPtr_[i] != rhv.sPtr_[i]) {
            return sPtr_[i] - rhv.sPtr_[i];
        }
        ++i;
    }
    return getLength() - rhv.getLength();
}

int
String::strncmp_(const String& rhv, const int size) const
{
    assert(size >= 0 && size <= getLength() && size <= rhv.getLength());
    int i = 0;
    while (i < size) {
        if (sPtr_[i] != rhv.sPtr_[i]) {
            return sPtr_[i] - rhv.sPtr_[i];
        }
        ++i;
    }
    return getLength() - rhv.getLength();
}

const char* 
String::strstr_(const String& rhv) const
{
    if (0 == rhv.getLength() || rhv.getLength() > getLength()) {
        return NULL;
    }

    for (int i = 0; i <= getLength() - rhv.getLength(); ++i) {
        bool match = true;
        for (int j = 0; j < rhv.getLength(); ++j) {
            if (sPtr_[i + j] != rhv.sPtr_[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return sPtr_ + i; 
        }
    }
    return NULL;
}
char*
String::strchr_(const char choice) const
{
    for (int i = 0; i < getLength(); ++i) {
        if (choice == sPtr_[i]) {
            return sPtr_ + i;
        }
    }
    return NULL;
}

char*
String::strrchr_(const char choice) const
{
    for (int i = getLength() - 1; i >= 0; --i) {
        if (choice == sPtr_[i]) {
            return sPtr_ + i;
        }
    }
    return NULL;
}

void
String::setString(const char* expression)
{
    if (expression != 0) {
        sPtr_ = new char[getLength() + 1];
        std::strcpy(sPtr_, expression);
    }
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

