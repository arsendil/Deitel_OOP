#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class Person
{
    friend std::ostream& operator<<(std::ostream& output, const Person& rhv);
    friend std::istream& operator>>(std::istream& input, Person& rhv);

public:
    Person(const std::string& name = "Gago", const std::string& address = "123", const std::string& city = "Goris",
           const std::string& state = "Syuniq", const std::string& zip = "12345");
    Person(const Person& rhv);

    Person& operator=(const Person& rhv);
    bool operator==(const Person& rhv) const;
    bool operator!=(const Person& rhv) const;
    
    void setName(const std::string& name); 
    void setAddress(const std::string& address);
    void setCity(const std::string& city);
    void setState(const std::string& state);
    void setZip(const std::string& zip);
    
    std::string getName()    const;
    std::string getAddress() const;
    std::string getCity()    const;
    std::string getState()   const;
    std::string getZip()     const;

private:
    std::string name_;
    std::string address_;
    std::string city_;
    std::string state_;
    std::string zip_;
};

#endif /// ___PERSON_HPP__

