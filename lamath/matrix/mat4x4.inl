namespace lm
{
    // Constructors

    template <typename T>
    constexpr mat<4, 4, T>::mat(T scalar)
    {
        rows[0] = vec<4, T>(scalar);
        rows[1] = vec<4, T>(scalar);
        rows[2] = vec<4, T>(scalar);
        rows[3] = vec<4, T>(scalar);
    };

    template <typename T>
    constexpr mat<4, 4, T>::mat(std::initializer_list<mat<4, 4, T>::row_type> r)
    {
        if (r.size() != 4)
        {
            throw std::invalid_argument("Attempted to construct mat4 with incompatible initializer list size.");
        }
        std::copy(r.begin(), r.end(), rows);
    };

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::identity()
    {
        return mat4{
            lm::vec4{1.0, 0, 0, 0},
            lm::vec4{0, 1.0, 0, 0},
            lm::vec4{0, 0, 1.0, 0},
            lm::vec4{0, 0, 0, 1.0},
        };
    }

    // Operators

    template <typename T>
    constexpr mat<4, 4, T>::row_type &mat<4, 4, T>::operator[](const int i)
    {
        return rows[i];
    }

    template <typename T>
    constexpr const mat<4, 4, T>::row_type &mat<4, 4, T>::operator[](const int i) const
    {
        return rows[i];
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
        return mat<4, 4, T>{
            {a[0][0] * b[0][0], a[0][1] * b[0][1], a[0][2] * b[0][2], a[0][3] * b[0][3]},
            {a[1][0] * b[1][0], a[1][1] * b[1][1], a[1][2] * b[1][2], a[1][3] * b[1][3]},
            {a[2][0] * b[2][0], a[2][1] * b[2][1], a[2][2] * b[2][2], a[2][3] * b[2][3]},
            {a[3][0] * b[3][0], a[3][1] * b[3][1], a[3][2] * b[3][2], a[3][3] * b[3][3]},
        };
    }
}