#include "mat3.h"
#include <cmath>
#include <stdexcept>
mat3::mat3()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] = 0.f;
}

mat3::mat3(vec3 x, vec3 y, vec3 z)
{
    mat[0][0] = x.x;
    mat[0][1] = x.y;
    mat[0][2] = x.z;

    mat[1][0] = y.x;
    mat[1][1] = y.y;
    mat[1][2] = y.z;

    mat[2][0] = z.x;
    mat[2][1] = z.y;
    mat[2][2] = z.z;
}

mat3::mat3(const float *data)
{
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat[i][j] = data[k++];
}

float &mat3::at(int x, int y)
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        throw std::out_of_range("Index out of range in mat3::at()");

    return mat[x][y];
}

const float &mat3::at(int x, int y) const
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        throw std::out_of_range("Index out of range in mat3::at()");

    return mat[x][y];
}

const float *mat3::getMatrix() const
{
    return &mat[0][0];
}

mat3 mat3::getTranspose() const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[j][i];
    return result;
}

mat3 mat3::getInverse() const
{
    float det = getDeterminant();
    if (det == 0)
        throw std::runtime_error("Matrix cannot be inverted.");

    mat3 result;

    result.mat[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) / det;
    result.mat[0][1] = (mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2]) / det;
    result.mat[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) / det;
    result.mat[1][0] = (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]) / det;
    result.mat[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) / det;
    result.mat[1][2] = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) / det;
    result.mat[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) / det;
    result.mat[2][1] = (mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1]) / det;
    result.mat[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) / det;

    return result;
}

float mat3::getDeterminant() const
{
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

mat3 mat3::operator+(const mat3 &other) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
    return result;
}

mat3 &mat3::operator+=(const mat3 &other)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] += other.mat[i][j];
    return *this;
}

mat3 mat3::operator-(const mat3 &other) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
    return result;
}

mat3 &mat3::operator-=(const mat3 &other)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] -= other.mat[i][j];
    return *this;
}

mat3 mat3::operator+(float scalar) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] + scalar;
    return result;
}

mat3 &mat3::operator+=(float scalar)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] += scalar;
    return *this;
}

mat3 mat3::operator-(float scalar) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] - scalar;
    return result;
}

mat3 &mat3::operator-=(float scalar)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] -= scalar;
    return *this;
}

mat3 mat3::operator*(const mat3 &other) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][0] * other.mat[0][j] + mat[i][1] * other.mat[1][j] + mat[i][2] * other.mat[2][j];
    return result;
}

mat3 &mat3::operator*=(const mat3 &other)
{
    *this = *this * other;
    return *this;
}

mat3 mat3::operator*(float scalar) const
{
    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] * scalar;
    return result;
}

mat3 &mat3::operator*=(float scalar)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] *= scalar;
    return *this;
}

vec3 mat3::operator*(const vec3 &vec) const
{
    vec3 result;
    result.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z;
    result.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z;
    result.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z;
    return result;
}

vec3 &mat3::operator*=(vec3 &vec)
{
    vec.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z;
    vec.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z;
    vec.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z;
    return vec;
}

mat3 mat3::operator/(float scalar) const
{
    if (scalar == 0)
        throw std::runtime_error("Division by zero in mat3::operator/()");

    mat3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.mat[i][j] = mat[i][j] / scalar;
    return result;
}

mat3 &mat3::operator/=(float scalar)
{
    if (scalar == 0)
        throw std::runtime_error("Division by zero in mat3::operator/()");

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] /= scalar;
    return *this;
}
