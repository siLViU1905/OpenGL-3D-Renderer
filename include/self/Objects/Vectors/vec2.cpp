#include "vec2.h"
#include <cmath>

vec2::vec2() : x(0.f), y(0.f)
{
}

vec2::vec2(float x, float y) : x(x), y(y)
{
}

vec2 vec2::getNormal() const
{
    float len = std::sqrt(x * x + y * y);
    if (len == 0.f)
        return {0.f, 0.f};
    return {x / len, y / len};
}

vec2 operator+(const vec2 &v1, const vec2 &v2)
{
    return {v1.x + v2.x, v1.y + v2.y};
}

vec2 &operator+=(vec2 &v1, const vec2 &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

vec2 operator-(const vec2 &v1, const vec2 &v2)
{
    return {v1.x - v2.x, v1.y - v2.y};
}

vec2 &operator-=(vec2 &v1, const vec2 &v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

vec2 operator+(const vec2 &v, float val)
{
    return {v.x + val, v.y + val};
}

vec2 &operator+=(vec2 &v, float val)
{
    v.x += val;
    v.y += val;
    return v;
}

vec2 operator-(const vec2 &v, float val)
{
    return {v.x - val, v.y - val};
}

vec2 &operator-=(vec2 &v, float val)
{
    v.x -= val;
    v.y -= val;
    return v;
}

vec2 operator*(const vec2 &v, float val)
{
    return {v.x * val, v.y * val};
}

vec2 &operator*=(vec2 &v, float val)
{
    v.x *= val;
    v.y *= val;
    return v;
}

vec2 operator/(const vec2 &v, float val)
{
    if (val == 0.f)
        return {0.f, 0.f};
    return {v.x / val, v.y / val};
}

vec2 &operator/=(vec2 &v, float val)
{
    if (val == 0.f)
        return v;
    v.x /= val;
    v.y /= val;
    return v;
}
