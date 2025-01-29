#include <iostream>
#include <cmath>

namespace tml
{
    // Constructors

    template <typename T>
    constexpr mat<3, 3, T>::mat(T scalar)
    {
        cols[0] = vec<3, T>(scalar);
        cols[1] = vec<3, T>(scalar);
        cols[2] = vec<3, T>(scalar);
    };

    template <typename T>
    constexpr mat<3, 3, T>::mat(col_type u, col_type v, col_type w)
    {
        cols[0] = u;
        cols[1] = v;
        cols[2] = w;
    };

    template <typename T>
    constexpr mat<3, 3, T>::mat(T x0, T x1, T x2, T y0, T y1, T y2, T z0, T z1, T z2)
    {
        cols[0] = tml::vec3{x0, y0, z0};
        cols[1] = tml::vec3{x1, y1, z1};
        cols[2] = tml::vec3{x2, y2, z2};
    }

    template <typename T>
    constexpr T mat<3, 3, T>::Det() const
    {
        const mat<3, 3, T> &m = *this;
        return m[0][0] * m[1][1] * m[2][2] +
               m[1][0] * m[2][1] * m[0][2] +
               m[2][0] * m[0][1] * m[1][2] -
               m[0][0] * m[2][1] * m[1][2] -
               m[1][0] * m[0][1] * m[2][2] -
               m[2][0] * m[1][1] * m[0][2];
    }

    template <typename T>
    constexpr mat<3, 3, T> mat<3, 3, T>::Identity()
    {
        return mat3(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1);
    }

    template <typename T>
    constexpr mat<3, 3, T> mat<3, 3, T>::Inverse()
    {
        const mat<3, 3, T> &m = *this;

        auto cofac00 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
        auto cofac10 = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
        auto cofac20 = m[0][1] * m[1][2] - m[1][1] * m[0][2];

        auto cofac01 = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
        auto cofac11 = m[0][0] * m[2][2] - m[2][0] * m[0][2];
        auto cofac21 = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);

        auto cofac02 = m[1][0] * m[2][1] - m[2][0] * m[1][1];
        auto cofac12 = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
        auto cofac22 = m[0][0] * m[1][1] - m[1][0] * m[0][1];

        T det = m[0][0] * cofac00 + m[1][0] * cofac10 + m[2][0] * cofac20;
        T invDet = T(1) / det;

        return mat<3, 3, T>(
            cofac00 * invDet, cofac01 * invDet, cofac02 * invDet,
            cofac10 * invDet, cofac11 * invDet, cofac12 * invDet,
            cofac20 * invDet, cofac21 * invDet, cofac22 * invDet);
    }

    template <typename T>
    constexpr mat<3, 3, T> mat<3, 3, T>::Transpose() const
    {
        return mat<3, 3, T>(
            cols[0][0], cols[0][1], cols[0][2],
            cols[1][0], cols[1][1], cols[1][2],
            cols[2][0], cols[2][1], cols[2][2]);
    }

    // Operators

    template <typename T>
    constexpr mat<3, 3, T>::col_type &mat<3, 3, T>::operator[](const int i)
    {
        return cols[i];
    }

    template <typename T>
    constexpr const mat<3, 3, T>::col_type &mat<3, 3, T>::operator[](const int i) const
    {
        return cols[i];
    }

    template <typename T>
    constexpr bool operator==(const mat<3, 3, T> &a, const mat<3, 3, T> &b)
    {
        return a[0] == b[0] &&
               a[1] == b[1] &&
               a[2] == b[2];
    }

    template <typename T>
    constexpr mat<3, 3, T> operator*(const mat<3, 3, T> &a, const mat<3, 3, T> &b)
    {
        auto result = tml::mat3();

        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 0; j < 3; j++)
            {
                result[j][i] = a.cols[0][i] * b.cols[j][0] +
                               a.cols[1][i] * b.cols[j][1] +
                               a.cols[2][i] * b.cols[j][2];
            }
        }

        return result;
    }

    template <typename T>
    constexpr vec<3, T> operator*(const mat<3, 3, T> &a, const vec<3, T> &v)
    {
        auto result = tml::vec3();
        for (auto i = 0; i < a.height; i++)
        {
            result[i] = dot(tml::vec3{a[0][i], a[1][i], a[2][i]}, v);
        }
        return result;
    }

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<3, 3, T> &m)
    {
        out << std::endl;
        for (auto row = 0; row < 3; row++)
        {
            for (auto col = 0; col < 3; col++)
            {
                out << m.cols[col][row] << ", ";
            }
            out << std::endl;
        }
        return out;
    }
}