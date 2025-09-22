#include "../headers/PhoneNumber.hpp"
#include <cassert>

PhoneNumber::PhoneNumber(const std::string& phoneNumber)
{
    assert(SIZE == phoneNumber.size());
    assert(isPhoneNumber(phoneNumber));
    setPhoneNumber(phoneNumber);
}

bool
PhoneNumber::isPhoneNumber(const std::string& phoneNumber)
{
    return (SIZE == phoneNumber.size() &&
            '(' == phoneNumber[AREA_COD_START - 1]  &&
            ')' == phoneNumber[AREA_COD_END + 1]    &&
            ' ' == phoneNumber[EXCHANGE_START - 1] &&
            '-' == phoneNumber[EXCHANGE_END + 1]   &&
            isDigit(phoneNumber.substr(AREA_COD_START, AREA_COD_END - AREA_COD_START + 1)) &&
            isDigit(phoneNumber.substr(EXCHANGE_START, EXCHANGE_END - EXCHANGE_START + 1)) &&
            isDigit(phoneNumber.substr(LINE_START, LINE_END - LINE_START + 1)));
}

void
PhoneNumber::setPhoneNumber(const std::string& phoneNumber)
{
    assert(SIZE == phoneNumber.size());
    assert(isPhoneNumber(phoneNumber));
    areaCode_ = std::atoi(phoneNumber.substr(1, 3).c_str());
    exchange_ = std::atoi(phoneNumber.substr(6, 3).c_str());
    line_     = std::atoi(phoneNumber.substr(10, 4).c_str());
}

bool
PhoneNumber::isDigit(const std::string& word)
{
    for (size_t i = 0; i < word.size(); ++i) {
        if (!std::isdigit(word[i])) {
            return false;
        }
    }
    return true;
}

int
PhoneNumber::getAreaCod() const
{
    return areaCode_;
}

int
PhoneNumber::getExchange() const
{
    return exchange_;
}

int
PhoneNumber::getLine() const
{
    return line_;
}

std::istream&
operator>>(std::istream& input, PhoneNumber& rhv)
{
    input >> rhv.areaCode_ >> rhv.exchange_ >> rhv.line_;
    return input;
}

std::ostream&
operator<<(std::ostream& output, const PhoneNumber& rhv) 
{
    output << "(" << rhv.getAreaCod() << ") " << rhv.getExchange() << "-" << rhv.getLine();
    return output;
}

std::ostream& 
PhoneNumber::operator<<(std::ostream& output) const 

{
    output << "(" << areaCode_ << ") " << exchange_ << "-" << line_;
    return output;
}

