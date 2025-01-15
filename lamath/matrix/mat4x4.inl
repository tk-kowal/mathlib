#include <iostream>
namespace lm
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
    constexpr mat<4, 4, T>::mat(std::initializer_list<mat<4, 4, T>::col_type> r)
    {
        if (r.size() != 4)
        {
            throw std::invalid_argument("Attempted to construct mat4 with incompatible initializer list size.");
        }
        std::copy(r.begin(), r.end(), cols);
    };

    template <typename T>
    constexpr mat<4, 4, T>::mat(T a0, T a1, T a2, T a3, T b0, T b1, T b2, T b3, T c0, T c1, T c2, T c3, T d0, T d1, T d2, T d3)
    {
        cols[0] = lm::vec4{a0, b0, c0, d0};
        cols[1] = lm::vec4{a1, b1, c1, d1};
        cols[2] = lm::vec4{a2, b2, c2, d2};
        cols[3] = lm::vec4{a3, b3, c3, d3};
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Identity()
    {
        return mat4{
            lm::vec4{1, 0, 0, 0},
            lm::vec4{0, 1, 0, 0},
            lm::vec4{0, 0, 1, 0},
            lm::vec4{0, 0, 0, 1},
        };
    }

    // Transforms

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Translate(const T x, const T y, const T z)
    {
        return mat<4, 4, T>{
            cols[0],
            cols[1],
            cols[2],
            {x, y, z, cols[3].w}};
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::RotX(const float radians)
    {
        return this * mat<4, 4, T>{
                          lm::vec4{1, 0, 0, 0},
                          lm::vec4{0, 1, 0, 0},
                          lm::vec4{0, 0, 1, 0},
                          lm::vec4{0, 0, 0, 1},
                      };
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::Transpose()
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
        auto result = lm::mat4();

        for (auto i = 0; i < 4; i++)
        {
            for (auto j = 0; j < 4; j++)
            {
                result[i][j] = dot(a.cols[i], lm::vec4{b.cols[0][j], b.cols[1][j], b.cols[2][j], b.cols[3][j]});
            }
        }

        return result;
    }

    template <typename T>
    constexpr vec<4, T> operator*(const mat<4, 4, T> &a, const vec<4, T> &v)
    {
        auto result = lm::vec4();
        for (auto i = 0; i < a.height; i++)
        {
            result[i] = dot(lm::vec4{a[0][i], a[1][i], a[2][i], a[3][i]}, v);
        }
        return result;
    }

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &out, const mat<4, 4, T> &m)
    {
        out << std::endl;
        for (auto &col : m.cols)
        {
            out << col << std::endl;
        }
        return out;
    }
}