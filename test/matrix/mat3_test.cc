#include "matrix/mat.h"

#include "gtest/gtest.h"

namespace testing
{
    TEST(Mat3x3Test, Determinant)
    {
        auto m = tml::mat3(
            1, 2, -1,
            2, 1, 2,
            -1, 2, 1);
        auto expected = -16;

        EXPECT_EQ(expected, m.Det());
    }

    TEST(Mat3x3Test, Inverse)
    {
        auto m = tml::mat3(
            4, 7, 2,
            3, 6, 1,
            2, 5, 1);

        auto expected = tml::mat3(
            0.3333, 1.0, -1.6666,
            -0.3333, 0, 0.6666,
            1, -2, 1);

        EXPECT_EQ(expected, m.Inverse());
    }
}