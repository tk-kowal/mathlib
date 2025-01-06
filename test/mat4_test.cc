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
            ASSERT_EQ(0, r.x);
            ASSERT_EQ(0, r.y);
            ASSERT_EQ(0, r.z);
            ASSERT_EQ(0, r.w);
        }
    }

    TEST(Mat4x4Test, ScalarConstructor)
    {
        auto m = lm::mat4(2);
        auto elems_count = 0;
        for (const auto &r : m.rows)
        {
            ASSERT_EQ(2, r.x);
            ASSERT_EQ(2, r.y);
            ASSERT_EQ(2, r.z);
            ASSERT_EQ(2, r.w);
        }
    }
}