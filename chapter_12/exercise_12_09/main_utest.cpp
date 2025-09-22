#include <gtest/gtest.h>
#include "headers/Person.hpp"
#include "headers/Package.hpp"
#include "headers/TwoDayPackage.hpp"
#include "headers/OvernightPackage.hpp"
#include <sstream>

TEST(PersonTest, ConstructorAndGetters)
{
    Person p("John", "Main 1", "Yerevan", "Yerevan", "0010");
    EXPECT_EQ(p.getName(), "John");
    EXPECT_EQ(p.getAddress(), "Main 1");
    EXPECT_EQ(p.getCity(), "Yerevan");
    EXPECT_EQ(p.getState(), "Yerevan");
    EXPECT_EQ(p.getZip(), "0010");
}

TEST(PersonTest, EqualityOperators)
{
    Person a("A", "X", "Y", "Z", "111");
    Person b("A", "X", "Y", "Z", "111");
    Person c("B", "X", "Y", "Z", "111");

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
}

TEST(PackageTest, ConstructorAndCost)
{
    Person s("Sender", "Addr1", "City1", "State1", "1000");
    Person r("Receiver", "Addr2", "City2", "State2", "2000");
    Package p(s, r, 5.0, 2.0);
    EXPECT_EQ(p.getWeight(), 5.0);
    EXPECT_EQ(p.getCostPerOunce(), 2.0);
    EXPECT_DOUBLE_EQ(p.calculateCost(), 10.0);
}

TEST(PackageTest, CopyConstructor)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    Package original(s, r, 3.0, 1.5);
    Package copy(original);
    EXPECT_EQ(copy.getWeight(), 3.0);
    EXPECT_EQ(copy.getCostPerOunce(), 1.5);
    EXPECT_TRUE(copy.getSenderPerson() == s);
    EXPECT_TRUE(copy.getRecipientPerson() == r);
}

TEST(PackageTest, AssignmentOperator)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    Package p1(s, r, 2.0, 1.0);
    Package p2 = p1;
    EXPECT_DOUBLE_EQ(p2.calculateCost(), 2.0);
}

TEST(TwoDayPackageTest, CostCalculation)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    TwoDayPackage pkg(s, r, 4.0, 2.0, 5.0);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 13.0);
}

TEST(TwoDayPackageTest, AssignmentOperator)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    TwoDayPackage a(s, r, 4.0, 2.0, 3.0);
    TwoDayPackage b = a;
    EXPECT_DOUBLE_EQ(b.getTwoDayDeliveryFee(), 3.0);
    EXPECT_DOUBLE_EQ(b.calculateCost(), 11.0);
}

TEST(OvernightPackageTest, CostCalculation)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    OvernightPackage pkg(s, r, 3.0, 2.0, 1.0);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 9.0);
}

TEST(OvernightPackageTest, AssignmentOperator)
{
    Person s("S", "A", "C", "S", "123");
    Person r("R", "B", "D", "T", "456");
    OvernightPackage a(s, r, 3.0, 1.5, 0.5);
    OvernightPackage b = a;
    EXPECT_DOUBLE_EQ(b.getExtraFeePerOunce(), 0.5);
    EXPECT_DOUBLE_EQ(b.calculateCost(), 6.0);
}

TEST(PersonStreamTest, OutputOperator)
{
    Person p("Anna", "Abovyan 23", "Gyumri", "Shirak", "3101");
    std::stringstream ss;
    ss << p;

    std::string expected =
        "  Name: Anna\n"
        "  Address: Abovyan 23\n"
        "  City: Gyumri\n"
        "  State: Shirak\n"
        "  ZIP: 3101\n";

    EXPECT_EQ(ss.str(), expected);
}

TEST(PersonStreamTest, InputOperator)
{
    std::stringstream ss;
    ss << "Mher\n"
       << "Mashtots 55\n"
       << "Vanadzor\n"
       << "Lori\n"
       << "2007\n";

    Person p;
    ss >> p;

    EXPECT_EQ(p.getName(), "Mher");
    EXPECT_EQ(p.getAddress(), "Mashtots 55");
    EXPECT_EQ(p.getCity(), "Vanadzor");
    EXPECT_EQ(p.getState(), "Lori");
    EXPECT_EQ(p.getZip(), "2007");
}

TEST(PackageStreamTest, OutputOperator)
{
    Person s("Armen", "Pushkin 1", "Yerevan", "Yerevan", "0010");
    Person r("Narek", "Komitas 5", "Gyumri", "Shirak", "3101");
    Package pkg(s, r, 2.0, 1.5);
    std::stringstream ss;
    ss << pkg;

    std::string expected =
        "Sender:\n"
        "  Name: Armen\n"
        "  Address: Pushkin 1\n"
        "  City: Yerevan\n"
        "  State: Yerevan\n"
        "  ZIP: 0010\n"
        "Recipient:\n"
        "  Name: Narek\n"
        "  Address: Komitas 5\n"
        "  City: Gyumri\n"
        "  State: Shirak\n"
        "  ZIP: 3101\n"
        "Weight (oz): 2\n"
        "Cost per ounce: 1.5\n"
        "Total cost: 3\n";

    EXPECT_EQ(ss.str(), expected);
}

TEST(TwoDayPackageStreamTest, OutputOperator)
{
    Person s("A", "A", "A", "A", "111");
    Person r("B", "B", "B", "B", "222");
    TwoDayPackage pkg(s, r, 2.0, 1.0, 3.0);
    std::stringstream ss;
    ss << pkg;

    std::string str = ss.str();
    EXPECT_NE(str.find("Flat fee for 2-day delivery: 3"), std::string::npos);
    EXPECT_NE(str.find("Total cost with 2-day delivery: 5"), std::string::npos);
}

TEST(OvernightPackageStreamTest, OutputOperator)
{
    Person s("C", "C", "C", "C", "333");
    Person r("D", "D", "D", "D", "444");
    OvernightPackage pkg(s, r, 2.0, 1.0, 0.5);
    std::stringstream ss;
    ss << pkg;

    std::string str = ss.str();
    EXPECT_NE(str.find("Extra fee per ounce for overnight delivery: 0.5"), std::string::npos);
    EXPECT_NE(str.find("Total cost with overnight delivery: 3"), std::string::npos);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
