#pragma once
#include "detail/base_types.h"
#include "vectors/vec4.h"

namespace lm
{
    typedef mat<4, 4, float> mat4;

    template <typename T>
    struct mat<4, 4, T>
    {
        using col_type = vec<4, T>;
        using row_type = vec<4, T>;

        const int height = 4;
        const int width = 4;

        row_type rows[4];

        constexpr mat() = default;
        constexpr mat(T scalar);
    };
}

#include "matrix/mat4x4.inl"