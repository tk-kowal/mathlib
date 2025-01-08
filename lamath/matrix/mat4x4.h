#pragma once
#include <initializer_list>
#include <array>
#include <exception>

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

        col_type cols[4];

        constexpr mat() = default;
        constexpr mat(T scalar);
        constexpr mat(std::initializer_list<col_type> r);
        constexpr col_type &operator[](const int i);
        constexpr const col_type &operator[](const int i) const;
        static constexpr mat<4, 4, T> identity();
        constexpr mat<4, 4, T> translate(const T x, const T y, const T z);
        constexpr mat<4, 4, T> rotX(const float radians);
    };

    template <typename T>
    constexpr bool operator==(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    template <typename T>
    constexpr mat<4, 4, T> operator*(const mat<4, 4, T> &a, const mat<4, 4, T> &b);
}

#include "matrix/mat4x4.inl"