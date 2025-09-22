#include "headers/Complex.hpp"

#include "gtest/gtest.h"

TEST(Complex, sumComplexcomplexNumbers)
{
    Complex complexNumber1(4, 5);
    Complex complexNumber2(5, 7);
    Complex complexNumber3 = complexNumber1.sumComplexNumbers(complexNumber2);
    EXPECT_EQ(complexNumber3.getRealNumber(), 9);
    EXPECT_EQ(complexNumber3.getImaginaryNumber(), 12);
}

TEST(Complex, diffComplexcomplexNumbers)
{
    Complex complexNumber1(4, 5);
    Complex complexNumber2(5, 7);
    Complex complexNumber3 = complexNumber1.diffComplexNumbers(complexNumber2);
    EXPECT_EQ(complexNumber3.getRealNumber(), -1);
    EXPECT_EQ(complexNumber3.getImaginaryNumber(), -2);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
