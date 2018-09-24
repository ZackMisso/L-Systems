#pragma once

template <typename T>
struct Vec2
{
    Vec2()
    {
        xy[0] = 0x0;
        xy[1] = 0x0;
    }

    Vec2(const Vec2<T>& other)
    {
        xy[0] = other(0);
        xy[1] = other(1);
    }

    Vec2(T c)
    {
        xy[0] = c;
        xy[1] = c;
    }

    Vec2(T x, T y)
    {
        xy[0] = x;
        xy[1] = y;
    }

    Vec2<T> rotCW(T ang) const
    {
        Vec2<T> vec;
        vec[0] = xy[0] * cos(ang) - xy[1] * sin(ang);
        vec[1] = xy[1] * cos(ang) + xy[0] * sin(ang);
        return vec;
    }

    Vec2<T> rotCCW(T ang) const
    {
        return rotCW(-ang);
    }

    Vec2<T> operator+(const Vec2<T>& other) const
    {
        Vec2<T> vec;
        vec[0] = xy[0] + other(0);
        vec[1] = xy[1] + other(1);
        return vec;
    }

    Vec2<T> operator-(const Vec2<T>& other) const
    {
        Vec2<T> vec;
        vec[0] = xy[0] - other(0);
        vec[1] = xy[1] - other(1);
        return vec;
    }

    Vec2<T> operator*(T c) const
    {
        Vec2<T> vec;
        vec[0] = xy[0] * c;
        vec[1] = xy[1] * c;
        return vec;
    }

    Vec2<T> operator/(T c) const
    {
        Vec2<T> vec;
        vec[0] = xy[0] / c;
        vec[1] = xy[1] / c;
        return vec;
    }

    void operator+=(const Vec2<T>& other)
    {
        xy[0] += other(0);
        xy[1] += other(1);
    }

    void operator-=(const Vec2<T>& other)
    {
        xy[0] -= other(0);
        xy[1] -= other(1);
    }

    // component wise multiplication
    void operator*=(const Vec2<T>& other)
    {
        xy[0] *= other(0);
        xy[1] *= other(1);
    }

    void operator/=(const Vec2<T>& other)
    {
        xy[0] /= other(0);
        xy[1] /= other(1);
    }

    // dot product
    T operator%(Vec2<T>& other)
    {
        return other(0) * xy[0] +
               other(1) * xy[1];
    }

    // cross product
    T operator^(const Vec2<T>& other)
    {
        return xy[0] * other(1) - xy[1] * other(0);
    }

    // returns a reference
    T& operator[](int index)
    {
        return xy[index];
    }

    // returns a copy
    T operator()(int index) const
    {
        return xy[index];
    }

    T sqrNorm() const
    {
        return xy[0] * xy[0] + xy[1] * xy[1];
    }

    T norm() const
    {
        return sqrt(xy[0] * xy[0] + xy[1] * xy[1]);
    }

    Vec2<T> normalized() const
    {
        T n = norm();
        Vec2<T> vec;
        vec[0] = xy[0] / n;
        vec[1] = xy[1] / n;
        return vec;
    }

    Vec2<T> operator~()
    {
        Vec2<T> vec;
        vec[0] = -xy[0];
        vec[1] = -xy[1];
        return vec;
    }

    T xy[2];
};
