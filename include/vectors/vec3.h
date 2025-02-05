#pragma once
#include <iostream>
#include <cmath>
#include <exception>

#include "../detail/base_types.h"
#include "../scalars/scalar.h"

namespace tml
{
    typedef vec<3, float> vec3;

    template <typename T>
    struct vec<3, T>
    {
        typedef float value_type;
        typedef vec<3, T> type;

        union
        {
            T x, r;
        };
        union
        {
            T y, g;
        };
        union
        {
            T z, b;
        };

        constexpr vec() = default;
        constexpr vec(T scalar) : x(scalar), y(scalar), z(scalar) {}
        constexpr vec(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
        constexpr vec(const vec<3, T> &other) : x(other.x), y(other.y), z(other.z) {}
        constexpr T operator[](const int i);
        constexpr T operator[](const int i) const;
    };

    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a);

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr bool operator==(const vec<3, T> &a, const vec<3, T> &b);

    // Presentation
    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &stream, const vec<3, T> &v);

    template <typename T>
    constexpr T dot(const vec<3, T> &a, const vec<3, T> &b);

    // Unary Ops
    template <typename T>
    constexpr T mag(const vec<3, T> &a);
}

#include "vec3.inl"