#include "../headers/Person.hpp"

Person::Person(const std::string& name,  const std::string& address, const std::string& city,
               const std::string& state, const std::string& zip) 
    : name_(name), address_(address)
    , city_(city), state_(state)
    , zip_(zip)
{}

Person::Person(const Person& rhv)
    : name_(rhv.getName())
    , address_(rhv.getAddress())
    , city_(rhv.getCity())
    , state_(rhv.getState())
    , zip_(rhv.getZip())
{}

Person&
Person::operator=(const Person& rhv)
{
    if (this != &rhv) {
        setAddress(rhv.getAddress());
        setName(rhv.getName());
        setCity(rhv.getCity());
        setZip(rhv.getZip());
        setState(rhv.getState());
    }
    return *this;
}

bool
Person::operator==(const Person& rhv) const
{
    return getName()    == rhv.getName()    &&
           getAddress() == rhv.getAddress() &&
           getCity()    == rhv.getCity()    &&
           getState()   == rhv.getState()   &&
           getZip()     == rhv.getZip(); 
}

bool
Person::operator!=(const Person& rhv) const
{
    return !(*this == rhv);
}

void
Person::setName(const std::string& name)
{
    name_ = name;
}

void
Person::setAddress(const std::string& address)
{
    address_ = address;
}

void
Person::setCity(const std::string& city)
{
    city_ = city;
}

void
Person::setState(const std::string& state)
{
    state_ = state;
}

void
Person::setZip(const std::string& zip)
{
    zip_ = zip;
}

std::string
Person::getName() const
{
    return name_;
}

std::string
Person::getAddress() const
{
    return address_;
}

std::string
Person::getCity() const
{
    return city_;
}

std::string
Person::getState() const
{
    return state_;
}

std::string
Person::getZip() const
{
    return zip_;
}

std::ostream&
operator<<(std::ostream& output, const Person& rhv)
{
    output << "  Name: "    << rhv.getName()    << '\n'
           << "  Address: " << rhv.getAddress() << '\n'
           << "  City: "    << rhv.getCity()    << '\n'
           << "  State: "   << rhv.getState()   << '\n'
           << "  ZIP: "     << rhv.getZip()     << '\n';
    return output;

}

std::istream&
operator>>(std::istream& input, Person& rhv)
{
    std::string stringMember;

    std::getline(input, stringMember);
    rhv.setName(stringMember);

    std::getline(input, stringMember);
    rhv.setAddress(stringMember);

    std::getline(input, stringMember);
    rhv.setCity(stringMember);

    std::getline(input, stringMember);
    rhv.setState(stringMember);

    std::getline(input, stringMember);
    rhv.setZip(stringMember);
    
    input.ignore();

    return input;
}

