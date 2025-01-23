#include "matrix/mat.h"

#include "gtest/gtest.h"

#include "helpers/helpers.h"

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

    TEST(Mat4x4Test, InitializerList)
    {
        auto m = tml::mat4{
            tml::vec4{1, 0, 0, 0},
            tml::vec4{0, 1, 0, 0},
            tml::vec4{0, 0, 1, 0},
            tml::vec4{0, 0, 0, 1},
        };
        EXPECT_EQ(1.0, m[0][0]);
        EXPECT_EQ(1.0, m[1][1]);
        EXPECT_EQ(1.0, m[2][2]);
        EXPECT_EQ(1.0, m[3][3]);
    }

    TEST(Mat4x4Test, IdentityFactory)
    {
        auto m = tml::mat4::Identity();
        auto n = tml::mat4{
            tml::vec4{1, 0, 0, 0},
            tml::vec4{0, 1, 0, 0},
            tml::vec4{0, 0, 1, 0},
            tml::vec4{0, 0, 0, 1},
        };
        EXPECT_EQ(m, n);
    }

    TEST(Mat4x4Test, MultiplyMatrices)
    {
        auto m = tml::mat4{
            tml::vec4{1, 2, 3, 4},
            tml::vec4{4, 3, 2, 1},
            tml::vec4{9, 8, 7, 6},
            tml::vec4{6, 7, 8, 9},
        };
        auto n = tml::mat4{
            tml::vec4{1, 2, 3, 4},
            tml::vec4{4, 3, 2, 1},
            tml::vec4{9, 8, 7, 6},
            tml::vec4{6, 7, 8, 9},
        };
        auto e = tml::mat4{
            tml::vec4(60),
            tml::vec4(40),
            tml::vec4(140),
            tml::vec4(160),
        };
        EXPECT_EQ(e, m * n);
    }

    TEST(Mat4x4Test, Transpose)
    {
        auto m = tml::mat4{
            tml::vec4{1, 2, 3, 4},
            tml::vec4{4, 3, 2, 1},
            tml::vec4{9, 8, 7, 6},
            tml::vec4{6, 7, 8, 9},
        };
        auto e = tml::mat4{
            tml::vec4{1, 4, 9, 6},
            tml::vec4{2, 3, 8, 7},
            tml::vec4{3, 2, 7, 8},
            tml::vec4{4, 1, 6, 9},
        };
        EXPECT_EQ(e, m.Transpose());
    }

    TEST(Mat4x4Test, Translate)
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
}