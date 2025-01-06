#pragma once
#include "detail/base_types.h"

namespace lm
{
    template <typename T>
    constexpr mat<4, 4, T> transpose(const mat<4, 4, T> &a);
}

#include "matrix/funcs.inl"