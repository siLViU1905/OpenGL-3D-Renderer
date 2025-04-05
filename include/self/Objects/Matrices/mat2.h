#ifndef __MAT2_H__
#define __MAT2_H__
#include "../Vectors/vec2.h"
#include "../Angle.h"

class mat2
{
    float mat[2][2];

public:
    mat2();

    mat2(vec2 x, vec2 y);

    mat2(const float *data);

    float &at(int x, int y);

    const float &at(int x, int y) const;

    const float *getMatrix() const;

    mat2 getTranspose() const;

    mat2 getInverse() const;

    float getDeterminant() const;

    mat2 operator+(const mat2 &m) const;

    mat2 &operator+=(const mat2 &m);

    mat2 operator-(const mat2 &m) const;

    mat2 &operator-=(const mat2 &m);

    mat2 operator+(float scalar) const;

    mat2 &operator+=(float scalar);

    mat2 operator-(float scalar) const;

    mat2 &operator-=(float scalar);

    mat2 operator*(const mat2 &m) const;

    mat2 &operator*=(const mat2 &m);

    vec2 operator*(const vec2 &v) const;

    vec2 &operator*=(vec2 &v);

    mat2 operator*(float scalar) const;

    mat2 &operator*=(float scalar);

    mat2 operator/(float scalar) const;

    mat2 &operator/=(float scalar);

    bool operator==(const mat2 &m) const;

    bool operator!=(const mat2 &m) const;
};

#endif // __MAT2_H__