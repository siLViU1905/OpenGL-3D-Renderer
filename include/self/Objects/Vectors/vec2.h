#ifndef __VEC2_H__
#define __VEC2_H__

class vec2
{
public:
    float x, y;

    vec2();
    vec2(float x, float y);

    vec2 getNormal() const;
};

vec2 operator+(const vec2 &v1, const vec2 &v2);

vec2 &operator+=(vec2 &v1, const vec2 &v2);

vec2 operator-(const vec2 &v1, const vec2 &v2);

vec2 &operator-=(vec2 &v1, const vec2 &v2);

vec2 operator+(const vec2 &v, float val);

vec2 &operator+=(vec2 &v, float val);

vec2 operator-(const vec2 &v, float val);

vec2 &operator-=(vec2 &v, float val);

vec2 operator*(const vec2 &v, float val);

vec2 &operator*=(vec2 &v, float val);

vec2 operator/(const vec2 &v, float val);

vec2 &operator/=(vec2 &v, float val);

#endif // __VEC2_H__