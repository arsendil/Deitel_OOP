#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cassert>

const int SIZE = 100;

class String
{
    friend std::ostream &operator<<(std::ostream& output, const String& expression);
    friend std::istream &operator>>(std::istream& input, String& expression);

public:
    String(const char* expression = "");
    String(const String& rhv);
    ~String();

    const String& operator=(const String& rhv);
    const String& operator+=(const String& rhv);
    String operator+(const String& rhv) const;

    bool operator!() const;
    bool operator==(const String& rhv) const;
    bool operator<(const String& rhv)  const;
    bool operator!=(const String& rhv) const;
    bool operator>(const String& rhv)  const; 
    bool operator<=(const String& rhv) const;
    bool operator>=(const String& rhv) const;

    int strlen_(const char* s1)     const;
    int strcmp_(const String& rhv)  const;
    int strncmp_(const String& rhv, const int size) const;
    char* strchr_(const  char choice) const;
    char* strrchr_(const char choice) const;
    void strcpy_(const String& rhv);
    void strncpy_(const String& rhv, const int size);
    void strcat_(const String& rhv);
    void strncat_(const String& rhv, const int size);
    char* strtok_(char* s1, const char* delimiters);
    const char* strstr_(const String& rhv) const;

    char& operator[](const int subscript);
    char operator[](const int subscript) const;
    const String operator()(const int index, const int subLength = 0) const;
    operator const char*() const;
    int getLength() const;

private:
    void setString(const char* expression);

private:
    int length_;
    char* sPtr_;
};

#endif /// __STRING_HPP__
