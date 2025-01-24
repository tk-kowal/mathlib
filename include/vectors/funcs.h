#pragma once
#include "../detail/base_types.h"

namespace tml
{
    template <int S, typename T>
    constexpr vec<S, T> normalize(const vec<S, T> &v);
}

#include "../vectors/funcs.inl"