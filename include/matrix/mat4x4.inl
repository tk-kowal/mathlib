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
        // calculate matrix of minors
        //
    }

    // Transforms

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotX(const float rads)
    {
        return *this * mat4(
                           1, 0, 0, 0,
                           0, std::cosf(rads), -1 * std::sinf(rads), 0,
                           0, std::sinf(rads), std::cosf(rads), 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotY(const float rads)
    {
        return *this * mat4(
                           std::cosf(rads), 0, std::sinf(rads), 0,
                           0, 1, 0, 0,
                           -1 * std::sinf(rads), 0, std::cosf(rads), 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotZ(const float rads)
    {
        return *this * mat4(
                           std::cos(rads), -1 * std::sinf(rads), 0, 0,
                           std::sin(rads), std::cos(rads), 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1);
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Translate(const T x, const T y, const T z)
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