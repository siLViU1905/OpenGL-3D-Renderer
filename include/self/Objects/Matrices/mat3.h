#ifndef __MAT3_H__
#define __MAT3_H__
#include "../Vectors/vec3.h"

class mat3
{
    float mat[3][3];

public:
    mat3();

    mat3(vec3 x, vec3 y, vec3 z);

    mat3(const float *data);

    float &at(int x, int y);

    const float &at(int x, int y) const;

    const float *getMatrix() const;

    mat3 getTranspose() const;

    mat3 getInverse() const;

    float getDeterminant() const;

    mat3 operator+(const mat3& other) const;

    mat3& operator+=(const mat3& other);

    mat3 operator-(const mat3& other) const;

    mat3& operator-=(const mat3& other);

    mat3 operator+(float scalar) const;

    mat3& operator+=(float scalar);

    mat3 operator-(float scalar) const;

    mat3& operator-=(float scalar);

    mat3 operator*(const mat3& other) const;

    mat3& operator*=(const mat3& other);

    mat3 operator*(float scalar) const;

    mat3& operator*=(float scalar);

    vec3 operator*(const vec3& vec) const;

    vec3& operator*=(vec3& vec);

    mat3 operator/(float scalar) const;

    mat3& operator/=(float scalar);
};

#endif // __MAT3_H__