#ifndef __VEC4_H__
#define __VEC4_H__

class vec4
{
public:
    float x, y, z, w;

    vec4();

    vec4(float x, float y, float z, float w);

    vec4 getNormal() const;
};

vec4 operator+(const vec4 &v1, const vec4 &v2);

vec4& operator+=(vec4 &v1, const vec4 &v2);

vec4 operator-(const vec4 &v1, const vec4 &v2);

vec4& operator-=(vec4 &v1, const vec4 &v2);

vec4 operator+(const vec4 &v, float scalar);

vec4& operator+=(vec4 &v, float scalar);

vec4 operator-(const vec4 &v, float scalar);

vec4& operator-=(vec4 &v, float scalar);

vec4 operator*(const vec4 &v, float scalar);

vec4& operator*=(vec4 &v, float scalar);

vec4 operator/(const vec4 &v, float scalar);

vec4& operator/=(vec4 &v, float scalar);

#endif // __VEC4_H__