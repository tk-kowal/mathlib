#include "matrix/mat.h"

#include "gtest/gtest.h"

#include "helpers/helpers.h"
#include "geometry/funcs.h"

namespace testing
{
    TEST(Mat4x4Test, DefaultConstructor)
    {
        auto m = tml::mat4();
        ASSERT_EQ(4, m.width);
        ASSERT_EQ(4, m.height);
        for (const auto &c : m.cols)
        {
            EXPECT_EQ(0, c.x);
            EXPECT_EQ(0, c.y);
            EXPECT_EQ(0, c.z);
            EXPECT_EQ(0, c.w);
        }
    }

    TEST(Mat4x4Test, ScalarConstructor)
    {
        auto m = tml::mat4(2);
        for (const auto &c : m.cols)
        {
            EXPECT_EQ(2, c.x);
            EXPECT_EQ(2, c.y);
            EXPECT_EQ(2, c.z);
            EXPECT_EQ(2, c.w);
        }
    }

    TEST(Mat4x4Test, ValuesConstructor)
    {
        auto m = tml::mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
        EXPECT_EQ(1.0, m[0][0]);
        EXPECT_EQ(1.0, m[1][1]);
        EXPECT_EQ(1.0, m[2][2]);
        EXPECT_EQ(1.0, m[3][3]);
    }

    TEST(Mat4x4Test, IdentityFactory)
    {
        auto m = tml::mat4::Identity();
        auto n = tml::mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
        EXPECT_EQ(m, n);
    }

    TEST(Mat4x4Test, MultiplyMatrices)
    {
        auto m = tml::mat4(
            1, 2, 3, 4,
            4, 3, 2, 1,
            9, 8, 7, 6,
            6, 7, 8, 9);
        auto n = tml::mat4(
            1, 2, 3, 4,
            4, 3, 2, 1,
            9, 8, 7, 6,
            6, 7, 8, 9);
        auto e = tml::mat4(
            60, 60, 60, 60,
            40, 40, 40, 40,
            140, 140, 140, 140,
            160, 160, 160, 160);
        EXPECT_EQ(e, m * n);
    }

    TEST(Mat4x4Test, Transpose)
    {
        auto m = tml::mat4(
            1, 2, 3, 4,
            4, 3, 2, 1,
            9, 8, 7, 6,
            6, 7, 8, 9);
        auto e = tml::mat4(
            1, 4, 9, 6,
            2, 3, 8, 7,
            3, 2, 7, 8,
            4, 1, 6, 9);
        EXPECT_EQ(e, m.Transpose());
    }

    TEST(Mat4x4Test, TranslationMatrix)
    {
        const float x = 1;
        const float y = -2;
        const float z = 3;
        auto m = tml::mat4::Identity().Translate(x, y, z);
        auto e = tml::mat4(
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1);
        EXPECT_EQ(e, m);

        auto vec = tml::vec4{1, 0, 0, 1};
        auto translated_vec = tml::vec4{2, -2, 3, 1};
        vec = m * vec;
        EXPECT_EQ(translated_vec, vec);
    }

    TEST(Mat4x4Test, Translation)
    {
        auto m = tml::mat4::Identity().Translate(1.5, -2, 4);
        auto original = tml::vec4{1, 0, 0, 1};
        auto expected = tml::vec4{2.5, -2, 4, 1};

        EXPECT_EQ(expected, m * original);
    }

    TEST(Mat4x4Test, RotX)
    {
        auto m = tml::mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
        auto expected = tml::mat4(
            1, 0, 0, 0,
            0, 0, -1, 0,
            0, 1, 0, 0,
            0, 0, 0, 1);

        EXPECT_EQ(expected, m.RotX(tml::radians(90)));
    }

    TEST(Mat4x4Test, RotY)
    {
        auto m = tml::mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
        auto expected = tml::mat4(
            0, 0, 1, 0,
            0, 1, 0, 0,
            -1, 0, 0, 0,
            0, 0, 0, 1);

        EXPECT_EQ(expected, m.RotY(tml::radians(90)));
    }

    TEST(Mat4x4Test, RotZ)
    {
        auto m = tml::mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
        auto expected = tml::mat4(
            0, -1, 0, 0,
            1, 0, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);

        EXPECT_EQ(expected, m.RotZ(tml::radians(90)));
    }

    TEST(Mat4x4Test, Cofactor)
    {
        tml::mat4 m(
            -4, -4, -4, 4,
            -4, -4, 4, -4,
            -4, 4, -4, -4,
            4, -4, -4, -4);

        tml::mat4 e(
            -0.0625, -0.0625, -0.0625, 0.0625,
            -0.0625, -0.0625, 0.0625, -0.0625,
            -0.0625, 0.0625, -0.0625, -0.0625,
            0.0625, -0.0625, -0.0625, -0.0625);

        EXPECT_EQ(e, m.Inverse());
    }
}