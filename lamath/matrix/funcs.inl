namespace lm
{
    template <typename T>
    constexpr mat<4, 4, T> transpose(const mat<4, 4, T> &a)
    {
        return mat<4, 4, T>{
            {a[0][0], a[1][0], a[2][0], a[3][0]},
            {a[0][1], a[1][1], a[2][1], a[3][1]},
            {a[0][2], a[1][2], a[2][2], a[3][2]},
            {a[0][3], a[1][3], a[2][3], a[3][3]},
        };
    }
}