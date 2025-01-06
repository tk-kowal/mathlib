/*
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

        vec<4, col_type> cols;
        vec<4, row_type> rows;

        constexpr mat<4, 4, T>() : cols(vec<4, T>()), rows(vec<4, T>()){};
    };
}
*/