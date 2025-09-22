#ifndef __PHONENUMBER_HPP__
#define __PHONENUMBER_HPP__

#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <cstdlib>

const int SIZE           = 14;
const int AREA_COD_START = 1;
const int AREA_COD_END   = 3;
const int EXCHANGE_START = 6;
const int EXCHANGE_END   = 8;
const int LINE_START     = 10;
const int LINE_END       = 13;

class PhoneNumber
{
    friend std::istream& operator>>(std::istream& input, PhoneNumber& rhv);
    friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& rhv);
public:
    static bool isPhoneNumber(const std::string& phoneNumber);

private:
    static bool isDigit(const std::string& phoneNumber);

public:
    PhoneNumber(const std::string& phoneNumber = "(123) 456-7890");
    void setPhoneNumber(const std::string& phoneNumber);
    int getAreaCod() const;
    int getExchange() const;
    int getLine() const;
    std::ostream& operator<<(std::ostream& output) const;

private:
    int areaCode_; 
    int exchange_;
    int line_;
};

#endif /// __PHONENUMBER_HPP__
