#include "vec4.h"
#include <cmath>

vec4::vec4() : x(0.f), y(0.f), z(0.f), w(0.f)
{
}

vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

vec4 vec4::getNormal() const
{
    float len = std::sqrt(x * x + y * y + z * z + w * w);
    if (len == 0.f)
        return vec4(0.f, 0.f, 0.f, 0.f);

    return vec4(x / len, y / len, z / len, w / len);
}

vec4 operator+(const vec4 &v1, const vec4 &v2)
{
    return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

vec4& operator+=(vec4 &v1, const vec4 &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    v1.w += v2.w;
    return v1;
}

vec4 operator-(const vec4 &v1, const vec4 &v2)
{
    return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

vec4& operator-=(vec4 &v1, const vec4 &v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    v1.w -= v2.w;
    return v1;
}

vec4 operator+(const vec4 &v, float scalar)
{
    return vec4(v.x + scalar, v.y + scalar, v.z + scalar, v.w + scalar);
}

vec4& operator+=(vec4 &v, float scalar)
{
    v.x += scalar;
    v.y += scalar;
    v.z += scalar;
    v.w += scalar;
    return v;
}

vec4 operator-(const vec4 &v, float scalar)
{
    return vec4(v.x - scalar, v.y - scalar, v.z - scalar, v.w - scalar);
}

vec4& operator-=(vec4 &v, float scalar)
{
    v.x -= scalar;
    v.y -= scalar;
    v.z -= scalar;
    v.w -= scalar;
    return v;
}

vec4 operator*(const vec4 &v, float scalar)
{
    return vec4(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
}

vec4& operator*=(vec4 &v, float scalar)
{
    v.x *= scalar;
    v.y *= scalar;
    v.z *= scalar;
    v.w *= scalar;
    return v;
}


vec4 operator/(const vec4 &v, float scalar)
{
    if (scalar == 0.f)
        return vec4(0.f, 0.f, 0.f, 0.f); // Handle division by zero

    return vec4(v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar);
}


vec4& operator/=(vec4 &v, float scalar)
{
    if (scalar == 0.f)
        return v; // Handle division by zero

    v.x /= scalar;
    v.y /= scalar;
    v.z /= scalar;
    v.w /= scalar;
    return v;
}
