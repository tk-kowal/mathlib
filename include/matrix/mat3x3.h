#pragma once
#include <initializer_list>
#include <array>
#include <exception>

#include "../detail/base_types.h"
#include "../vectors/vec3.h"

namespace tml
{
    typedef mat<3, 3, float> mat3;

    template <typename T>
    struct mat<3, 3, T>
    {
        using col_type = vec<3, T>;
        using row_type = vec<3, T>;

        const int height = 3;
        const int width = 3;

        col_type cols[3];

        mat() = default;
        constexpr mat(T scalar);
        constexpr mat(col_type u, col_type v, col_type w);
        constexpr mat(T x0, T x1, T x2, T y0, T y1, T y2, T z0, T z1, T z2);

        constexpr T Det() const;
        static constexpr mat<3, 3, T> Identity();
        constexpr mat<3, 3, T> Inverse();
        constexpr const col_type &operator[](const int i) const;
        constexpr col_type &operator[](const int i);
        constexpr mat<3, 3, T> Transpose() const;
    };

    template <typename T>
    constexpr bool operator==(const mat<3, 3, T> &a, const mat<3, 3, T> &b);

    template <typename T>
    constexpr mat<3, 3, T> operator*(const mat<3, 3, T> &a, const mat<3, 3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator*(const mat<3, 3, T> &a, const vec<3, T> &v);

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<3, 3, T> &m);
}

#include "mat3x3.inl"