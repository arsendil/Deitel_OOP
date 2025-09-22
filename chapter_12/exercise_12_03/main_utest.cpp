#include <gtest/gtest.h>
#include "headers/BasePlusCommissionEmployee.hpp"

TEST(BasePlusCommissionEmployeeTest, ConstructorAndGetters)
{
    BasePlusCommissionEmployee emp("Anna", "Smith", "111-22-3333", 5000.0, 0.1, 1000.0);

    EXPECT_EQ(emp.getFirstName(), "Anna");
    EXPECT_EQ(emp.getLastName(), "Smith");
    EXPECT_EQ(emp.getSocialSecurityNumber(), "111-22-3333");
    EXPECT_DOUBLE_EQ(emp.getGrossSales(), 5000.0);
    EXPECT_DOUBLE_EQ(emp.getCommissionRate(), 0.1);
    EXPECT_DOUBLE_EQ(emp.getBaseSalary(), 1000.0);
}

TEST(BasePlusCommissionEmployeeTest, SettersWorkCorrectly)
{
    BasePlusCommissionEmployee emp("A", "B", "000", 0.0, 0.0, 0.0);

    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setSocialSecurityNumber("999-88-7777");
    emp.setGrossSales(8000.0);
    emp.setCommissionRate(0.2);
    emp.setBaseSalary(1200.0);

    EXPECT_EQ(emp.getFirstName(), "John");
    EXPECT_EQ(emp.getLastName(), "Doe");
    EXPECT_EQ(emp.getSocialSecurityNumber(), "999-88-7777");
    EXPECT_DOUBLE_EQ(emp.getGrossSales(), 8000.0);
    EXPECT_DOUBLE_EQ(emp.getCommissionRate(), 0.2);
    EXPECT_DOUBLE_EQ(emp.getBaseSalary(), 1200.0);
}

TEST(BasePlusCommissionEmployeeTest, EarningsCalculationIsCorrect)
{
    BasePlusCommissionEmployee emp("Test", "User", "000", 10000.0, 0.05, 2000.0);

    const double expected = 2000.0 + (10000.0 * 0.05);
    EXPECT_DOUBLE_EQ(emp.earnings(), expected);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
