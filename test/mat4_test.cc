#include "matrix/mat4x4.h"

#include "gtest/gtest.h"

#include "helpers.h"

namespace testing
{
    TEST(Mat4x4Test, DefaultConstructor)
    {
        auto m = lm::mat4();
        ASSERT_EQ(4, m.width);
        ASSERT_EQ(4, m.height);
        for (const auto &r : m.rows)
        {
            EXPECT_EQ(0, r.x);
            EXPECT_EQ(0, r.y);
            EXPECT_EQ(0, r.z);
            EXPECT_EQ(0, r.w);
        }
    }

    TEST(Mat4x4Test, ScalarConstructor)
    {
        auto m = lm::mat4(2);
        for (const auto &r : m.rows)
        {
            EXPECT_EQ(2, r.x);
            EXPECT_EQ(2, r.y);
            EXPECT_EQ(2, r.z);
            EXPECT_EQ(2, r.w);
        }
    }

    TEST(Mat4x4Test, InitializerList)
    {
        auto m = lm::mat4{
            lm::vec4{1.0, 0, 0, 0},
            lm::vec4{0, 1.0, 0, 0},
            lm::vec4{0, 0, 1.0, 0},
            lm::vec4{0, 0, 0, 1.0},
        };
        EXPECT_EQ(1.0, m[0][0]);
        EXPECT_EQ(1.0, m[1][1]);
        EXPECT_EQ(1.0, m[2][2]);
        EXPECT_EQ(1.0, m[3][3]);
    }
}