#include <iostream>
#include <cmath>

namespace tml
{
    // Constructors

    template <typename T>
    constexpr mat<4, 4, T>::mat(T scalar)
    {
        cols[0] = vec<4, T>(scalar);
        cols[1] = vec<4, T>(scalar);
        cols[2] = vec<4, T>(scalar);
        cols[3] = vec<4, T>(scalar);
    };

    template <typename T>
    constexpr mat<4, 4, T>::mat(col_type u, col_type v, col_type w, col_type x)
    {
        cols[0] = u;
        cols[1] = v;
        cols[2] = w;
        cols[3] = x;
    };

    template <typename T>
    constexpr mat<4, 4, T>::mat(T x0, T x1, T x2, T x3, T y0, T y1, T y2, T y3, T z0, T z1, T z2, T z3, T w0, T w1, T w2, T w3)
    {
        cols[0] = tml::vec4{x0, y0, z0, w0};
        cols[1] = tml::vec4{x1, y1, z1, w1};
        cols[2] = tml::vec4{x2, y2, z2, w2};
        cols[3] = tml::vec4{x3, y3, z3, w3};
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Identity()
    {
        return mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Inverse()
    {
        // FIX: Optimization and SIMD for another time
        // I lifted this 100% from GLM for the time being. I was spending too much time on this.
        const mat<4, 4, T> &m = *this;

        T coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
        T coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
        T coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

        T coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
        T coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
        T coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

        T coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
        T coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
        T coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

        T coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
        T coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
        T coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

        T coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
        T coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
        T coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

        T coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
        T coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
        T coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

        vec4 fac0 = {coef00, coef00, coef02, coef03};
        vec4 fac1 = {coef04, coef04, coef06, coef07};
        vec4 fac2 = {coef08, coef08, coef10, coef11};
        vec4 fac3 = {coef12, coef12, coef14, coef15};
        vec4 fac4 = {coef16, coef16, coef18, coef19};
        vec4 fac5 = {coef20, coef20, coef22, coef23};

        vec4 vec0 = {m[1][0], m[0][0], m[0][0], m[0][0]};
        vec4 vec1 = {m[1][1], m[0][1], m[0][1], m[0][1]};
        vec4 vec2 = {m[1][2], m[0][2], m[0][2], m[0][2]};
        vec4 vec3 = {m[1][3], m[0][3], m[0][3], m[0][3]};

        vec4 inv0 = {vec1 * fac0 - vec2 * fac1 + vec3 * fac2};
        vec4 inv1 = {vec0 * fac0 - vec2 * fac3 + vec3 * fac4};
        vec4 inv2 = {vec0 * fac1 - vec1 * fac3 + vec3 * fac5};
        vec4 inv3 = {vec0 * fac2 - vec1 * fac4 + vec2 * fac5};

        vec4 signA = {+1, -1, +1, -1};
        vec4 signB = {-1, +1, -1, +1};
        mat4 inverse = {
            inv0 * signA,
            inv1 * signB,
            inv2 * signA,
            inv3 * signB};

        vec4 Row0(inverse[0][0], inverse[1][0], inverse[2][0], inverse[3][0]);

        vec4 Dot0(m[0] * Row0);
        T Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

        T OneOverDeterminant = static_cast<T>(1) / Dot1;

        return inverse * OneOverDeterminant;
    }

    // Transforms

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotX(const float rads) const
    {
        return *this * mat4(
                           1, 0, 0, 0,
                           0, std::cosf(rads), -1 * std::sinf(rads), 0,
                           0, std::sinf(rads), std::cosf(rads), 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotY(const float rads) const
    {
        return *this * mat4(
                           std::cosf(rads), 0, std::sinf(rads), 0,
                           0, 1, 0, 0,
                           -1 * std::sinf(rads), 0, std::cosf(rads), 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotZ(const float rads) const
    {
        return *this * mat4(
                           std::cos(rads), -1 * std::sinf(rads), 0, 0,
                           std::sin(rads), std::cos(rads), 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Translate(const T x, const T y, const T z) const
    {
        return mat<4, 4, T>(
            cols[0],
            cols[1],
            cols[2],
            {x, y, z, cols[3].w});
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Transpose() const
    {
        return mat<4, 4, T>(
            cols[0][0], cols[0][1], cols[0][2], cols[0][3],
            cols[1][0], cols[1][1], cols[1][2], cols[1][3],
            cols[2][0], cols[2][1], cols[2][2], cols[2][3],
            cols[3][0], cols[3][1], cols[3][2], cols[3][3]);
    }

    // Operators

    template <typename T>
    constexpr mat<4, 4, T>::col_type &mat<4, 4, T>::operator[](const int i)
    {
        return cols[i];
    }

    template <typename T>
    constexpr const mat<4, 4, T>::col_type &mat<4, 4, T>::operator[](const int i) const
    {
        return cols[i];
    }

    template <typename T>
    constexpr bool operator==(const mat<4, 4, T> &a, const mat<4, 4, T> &b)
    {
        return a[0] == b[0] &&
               a[1] == b[1] &&
               a[2] == b[2] &&
               a[3] == b[3];
    }

    template <typename T>
    constexpr mat<4, 4, T> operator*(const mat<4, 4, T> &a, const mat<4, 4, T> &b)
    {
        auto result = tml::mat4();

        for (auto i = 0; i < 4; i++)
        {
            for (auto j = 0; j < 4; j++)
            {
                result[j][i] = a.cols[0][i] * b.cols[j][0] +
                               a.cols[1][i] * b.cols[j][1] +
                               a.cols[2][i] * b.cols[j][2] +
                               a.cols[3][i] * b.cols[j][3];
            }
        }

        return result;
    }

    template <typename T>
    constexpr vec<4, T> operator*(const mat<4, 4, T> &a, const vec<4, T> &v)
    {
        auto result = tml::vec4();
        for (auto i = 0; i < a.height; i++)
        {
            result[i] = dot(tml::vec4{a[0][i], a[1][i], a[2][i], a[3][i]}, v);
        }
        return result;
    }

    template <typename T>
    constexpr mat<4, 4, T> operator*(const mat<4, 4, T> &a, const T s)
    {
        auto result = tml::mat4();
        for (auto i = 0; i < a.height; i++)
        {
            for (auto j = 0; j < a.width; j++)
            {
                result[i][j] = a[i][j] * s;
            }
        }
        return result;
    }

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<4, 4, T> &m)
    {
        out << std::endl;
        for (auto row = 0; row < 4; row++)
        {
            for (auto col = 0; col < 4; col++)
            {
                out << m.cols[col][row] << ", ";
            }
            out << std::endl;
        }
        return out;
    }
}