#include "matrix/mat.h"

#include "gtest/gtest.h"

#include "helpers/helpers.h"

namespace testing
{
    TEST(Mat4x4Test, DefaultConstructor)
    {
        auto m = lm::mat4();
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
        auto m = lm::mat4(2);
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
        auto m = lm::mat4{
            lm::vec4{1, 0, 0, 0},
            lm::vec4{0, 1, 0, 0},
            lm::vec4{0, 0, 1, 0},
            lm::vec4{0, 0, 0, 1},
        };
        EXPECT_EQ(1.0, m[0][0]);
        EXPECT_EQ(1.0, m[1][1]);
        EXPECT_EQ(1.0, m[2][2]);
        EXPECT_EQ(1.0, m[3][3]);
    }

    TEST(Mat4x4Test, IdentityFactory)
    {
        auto m = lm::mat4::identity();
        auto n = lm::mat4{
            lm::vec4{1, 0, 0, 0},
            lm::vec4{0, 1, 0, 0},
            lm::vec4{0, 0, 1, 0},
            lm::vec4{0, 0, 0, 1},
        };
        EXPECT_EQ(m, n);
    }

    TEST(Mat4x4Test, MultiplyMatrices)
    {
        auto m = lm::mat4{
            lm::vec4{1, 2, 3, 4},
            lm::vec4{4, 3, 2, 1},
            lm::vec4{9, 8, 7, 6},
            lm::vec4{6, 7, 8, 9},
        };
        auto n = lm::mat4{
            lm::vec4{1, 2, 3, 4},
            lm::vec4{4, 3, 2, 1},
            lm::vec4{9, 8, 7, 6},
            lm::vec4{6, 7, 8, 9},
        };
        auto e = lm::mat4{
            lm::vec4{1, 4, 9, 16},
            lm::vec4{16, 9, 4, 1},
            lm::vec4{81, 64, 49, 36},
            lm::vec4{36, 49, 64, 81},
        };
        // EXPECT_EQ(e, m * n);
    }

    TEST(Mat4x4Test, Transpose)
    {
        auto m = lm::mat4{
            lm::vec4{1, 2, 3, 4},
            lm::vec4{4, 3, 2, 1},
            lm::vec4{9, 8, 7, 6},
            lm::vec4{6, 7, 8, 9},
        };
        auto e = lm::mat4{
            lm::vec4{1, 4, 9, 6},
            lm::vec4{2, 3, 8, 7},
            lm::vec4{3, 2, 7, 8},
            lm::vec4{4, 1, 6, 9},
        };
        EXPECT_EQ(e, transpose(m));
    }

    TEST(Mat4x4Test, Translate)
    {
        const float x = 1;
        const float y = 2;
        const float z = 3;
        auto m = lm::mat4::identity().translate(x, y, z);
        auto e = lm::mat4{
            lm::vec4{1, 0, 0, x},
            lm::vec4{0, 1, 0, y},
            lm::vec4{0, 0, 1, z},
            lm::vec4{0, 0, 0, 1},
        };
        EXPECT_EQ(m, e);
    }
}