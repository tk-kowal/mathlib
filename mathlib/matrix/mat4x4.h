#pragma once
#include <initializer_list>
#include <array>
#include <exception>

#include "detail/base_types.h"
#include "vectors/vec4.h"

namespace tml
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

        mat() = default;
        constexpr mat(T scalar);
        constexpr mat(std::initializer_list<col_type> r);
        constexpr mat(T a0, T a1, T a2, T a3, T b0, T b1, T b2, T b3, T c0, T c1, T c2, T c3, T d0, T d1, T d2, T d3);
        static constexpr mat<4, 4, T> Identity();

        constexpr const col_type &operator[](const int i) const;
        constexpr col_type &operator[](const int i);

        constexpr mat<4, 4, T> Translate(const T x, const T y, const T z);
        constexpr mat<4, 4, T> RotX(const float radians);
        // constexpr mat<4, 4, T> RotY(const float radians);
        // constexpr mat<4, 4, T> RotZ(const float radians);
        constexpr mat<4, 4, T> Transpose();

        // constexpr bool IsInvertible();
    };

    template <typename T>
    constexpr bool operator==(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    template <typename T>
    constexpr mat<4, 4, T> operator*(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    template <typename T>
    constexpr vec<4, T> operator*(const mat<4, 4, T> &a, const vec<4, T> &v);

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<4, 4, T> &m);
}

#include "matrix/mat4x4.inl"