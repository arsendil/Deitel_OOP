#include "../headers/Package.hpp"

Package::Package(const Person& senderPerson, const Person& recipientPerson,
                 const double weight, const double costPerOunce)
    : senderPerson_(senderPerson)
    , recipientPerson_(recipientPerson) 
{
    assert(getSenderPerson() != getRecipientPerson());
    setWeight(weight);
    setCostPerOunce(costPerOunce);
}

Package::Package(const Package& rhv)
    : senderPerson_(rhv.senderPerson_)
    , recipientPerson_(rhv.recipientPerson_)
    , weight_(rhv.weight_)
    , costPerOunce_(rhv.costPerOunce_)
{}

Package&
Package::operator=(const Package& rhv)
{
     if (this != &rhv) {
        senderPerson_ = rhv.getSenderPerson();
        recipientPerson_ = rhv.getRecipientPerson();
        setWeight(rhv.getWeight());
        setCostPerOunce(rhv.getCostPerOunce());
    }
    return *this;
}

void
Package::setWeight(const double weight)
{
    assert(weight > 0);
    weight_ = weight;
}
void
Package::setCostPerOunce(const double costPerOunce)
{
    assert(costPerOunce > 0);
    costPerOunce_ = costPerOunce;
}

double
Package::getWeight() const
{
    return weight_;
}
    
double
Package::getCostPerOunce() const
{
    return costPerOunce_;
}

void
Package::setSenderPerson(const Person& rhv)
{
    senderPerson_ = rhv;
}

void
Package::setRecipientPerson(const Person& rhv)
{
    recipientPerson_ = rhv;
}

Person
Package::getSenderPerson() const
{
    return senderPerson_;
}

Person
Package::getRecipientPerson() const
{
    return recipientPerson_;
}

double
Package::calculateCost() const
{
    return getCostPerOunce() * getWeight();
}

std::ostream&
operator<<(std::ostream& output, const Package& rhv)
{
    output << "Sender:\n"
           << rhv.getSenderPerson()
           << "Recipient:\n"
           << rhv.getRecipientPerson()
           << "Weight (oz): "    << rhv.getWeight()           << '\n'
           << "Cost per ounce: " << rhv.getCostPerOunce()     << '\n'
           << "Total cost: "     << rhv.calculateCost()       << '\n';
    return output;
}

std::istream&
operator>>(std::istream& input, Package& rhv)
{
    std::cin >> rhv.senderPerson_;
    std::cin >> rhv.recipientPerson_;
    double value;

    input >> value;
    rhv.setWeight(value);

    input >> value;
    rhv.setCostPerOunce(value);

    input.ignore();

    return input;
}

