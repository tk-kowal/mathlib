#pragma once
#include <initializer_list>
#include <array>
#include <exception>

#include "../detail/base_types.h"
#include "../vectors/vec4.h"

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
        constexpr mat(col_type u, col_type v, col_type w, col_type x);
        constexpr mat(T x0, T x1, T x2, T x3, T y0, T y1, T y2, T y3, T z0, T z1, T z2, T z3, T w0, T w1, T w2, T w3);

        static constexpr mat<4, 4, T> Identity();
        constexpr mat<4, 4, T> Inverse();
        constexpr const col_type &operator[](const int i) const;
        constexpr col_type &operator[](const int i);
        constexpr mat<4, 4, T> RotX(const float rads);
        constexpr mat<4, 4, T> RotY(const float rads);
        constexpr mat<4, 4, T> RotZ(const float rads);
        constexpr mat<4, 4, T> Translate(const T x, const T y, const T z);
        constexpr mat<4, 4, T> Transpose() const;
    };

    template <typename T>
    constexpr bool operator==(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    template <typename T>
    constexpr mat<4, 4, T> operator*(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    // matrix + matrix
    // template <typename T>
    // constexpr mat<4, 4, T> operator+(const mat<4, 4, T> &a, const mat<4, 4, T> &b);

    template <typename T>
    constexpr vec<4, T> operator*(const mat<4, 4, T> &a, const vec<4, T> &v);

    // matrix x scalar
    // template <typename T>
    // constexpr vec<4, T> operator*(const mat<4, 4, T> &a, const T x);

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<4, 4, T> &m);
}

#include "mat4x4.inl"