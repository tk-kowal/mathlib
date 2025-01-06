/*
#include "matrix/mat4x4.h"

#include "gtest/gtest.h"

#include "helpers.h"

namespace testing
{
    TEST(Mat4x4Test, DefaultConstructor)
    {
        auto m = mat4();
        ASSERT_EQ(4, m.width);
        ASSERT_EQ(4, m.height);
        auto elems_count = 0;
        for (const auto r : m.rows)
        {
            for (const auto c : m.cols)
            {
                ASSERT_EQ(0f, m[r][c]);
            }
        }
    }

}
*/