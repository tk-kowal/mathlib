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
    constexpr mat<4, 4, T> mat<4, 4, T>::identity()
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
    constexpr mat<4, 4, T> mat<4, 4, T>::translate(const T x, const T y, const T z)
    {
        return mat<4, 4, T>{
            {cols[0].x, cols[0].y, cols[0].z, x},
            {cols[1].x, cols[1].y, cols[1].z, y},
            {cols[2].x, cols[2].y, cols[2].z, z},
            {cols[3].x, cols[3].y, cols[3].z, cols[3].w},
        };
    }

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::rotX(const float radians)
    {
        return this * mat<4, 4, T>{
                          lm::vec4{1, 0, 0, 0},
                          lm::vec4{0, 1, 0, 0},
                          lm::vec4{0, 0, 1, 0},
                          lm::vec4{0, 0, 0, 1},
                      };
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
        return mat4();
        // for (auto i = 0; i < 4; i++)
        // {
        //     for (auto j = 0; j < 4; j++)
        //     {
        //         result[i][j] = dot(rows[i], )
        //     }
        // }
    }
}