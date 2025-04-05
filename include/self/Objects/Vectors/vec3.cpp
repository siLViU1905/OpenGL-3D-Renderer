#include "vec3.h"
#include <cmath>

vec3::vec3() : x(0.f), y(0.f), z(0.f) {}

vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

vec3 vec3::getNormal() const
{
    float len = std::sqrt(x * x + y * y + z * z);
    if (len == 0.f) return {0.f, 0.f, 0.f};
    return {x / len, y / len, z / len};
}

vec3 operator+(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vec3 &operator+=(vec3 &v1, const vec3 &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

vec3 operator-(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

vec3 &operator-=(vec3 &v1, const vec3 &v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return v1;
}

vec3 operator+(const vec3 &v, float val)
{
    return vec3(v.x + val, v.y + val, v.z + val);
}

vec3 &operator+=(vec3 &v, float val)
{
    v.x += val;
    v.y += val;
    v.z += val;
    return v;
}

vec3 operator-(const vec3 &v, float val)
{
    return vec3(v.x - val, v.y - val, v.z - val);
}

vec3 &operator-=(vec3 &v, float val)
{
    v.x -= val;
    v.y -= val;
    v.z -= val;
    return v;
}

vec3 operator*(const vec3 &v, float val)
{
    return vec3(v.x * val, v.y * val, v.z * val);
}

vec3 &operator*=(vec3 &v, float val)
{
    v.x *= val;
    v.y *= val;
    v.z *= val;
    return v;
}

vec3 operator/(const vec3 &v, float val)
{
    return vec3(v.x / val, v.y / val, v.z / val);
}

vec3 &operator/=(vec3 &v, float val)
{
    v.x /= val;
    v.y /= val;
    v.z /= val;
    return v;
}