#include "mat2.h"
#include <stdexcept>
#include <cmath>
mat2::mat2()
{
    mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0.f;
}

mat2::mat2(vec2 x, vec2 y)
{
    mat[0][0] = x.x;
    mat[0][1] = x.y;

    mat[1][0] = y.x;
    mat[1][1] = y.y;
}

mat2::mat2(const float *data)
{
    int k = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            mat[i][j] = data[k++];
}

float &mat2::at(int x, int y)
{
    if (x < 0 || x > 1 || y < 0 || y > 1)
        throw std::out_of_range("mat2::at: index out of range");

    return mat[x][y];
}

const float &mat2::at(int x, int y) const
{
    if (x < 0 || x > 1 || y < 0 || y > 1)
        throw std::out_of_range("mat2::at: index out of range");

    return mat[x][y];
}

const float *mat2::getMatrix() const
{
    return &mat[0][0];
}

mat2 mat2::getTranspose() const
{
    return mat2(vec2(mat[0][0], mat[1][0]), vec2(mat[0][1], mat[1][1]));
}

mat2 mat2::getInverse() const
{
    float det = getDeterminant();
    if (det == 0.f)
        throw std::runtime_error("mat2::getInverse: determinant is zero");

   return  mat2(vec2(mat[1][1], -mat[0][1]), vec2(-mat[1][0], mat[0][0])) * 1.f/det;
}

float mat2::getDeterminant() const
{
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

mat2 mat2::operator+(const mat2 &m) const
{
    return mat2(vec2(mat[0][0] + m.mat[0][0], mat[0][1] + m.mat[0][1]),
                vec2(mat[1][0] + m.mat[1][0], mat[1][1] + m.mat[1][1]));
}

mat2 &mat2::operator+=(const mat2 &m)
{
    mat[0][0] += m.mat[0][0];
    mat[0][1] += m.mat[0][1];

    mat[1][0] += m.mat[1][0];
    mat[1][1] += m.mat[1][1];

    return *this;
}

mat2 mat2::operator-(const mat2 &m) const
{
    return mat2(vec2(mat[0][0] - m.mat[0][0], mat[0][1] - m.mat[0][1]),
                vec2(mat[1][0] - m.mat[1][0], mat[1][1] - m.mat[1][1]));
}

mat2 &mat2::operator-=(const mat2 &m)
{
    mat[0][0] -= m.mat[0][0];
    mat[0][1] -= m.mat[0][1];

    mat[1][0] -= m.mat[1][0];
    mat[1][1] -= m.mat[1][1];

    return *this;
}

mat2 mat2::operator+(float scalar) const
{
    return mat2(vec2(mat[0][0] + scalar, mat[0][1] + scalar),
                vec2(mat[1][0] + scalar, mat[1][1] + scalar));
}

mat2 &mat2::operator+=(float scalar)
{
    mat[0][0] += scalar;
    mat[0][1] += scalar;

    mat[1][0] += scalar;
    mat[1][1] += scalar;

    return *this;
}

mat2 mat2::operator-(float scalar) const
{
    return mat2(vec2(mat[0][0] - scalar, mat[0][1] - scalar),
                vec2(mat[1][0] - scalar, mat[1][1] - scalar));
}

mat2 &mat2::operator-=(float scalar)
{
    mat[0][0] -= scalar;
    mat[0][1] -= scalar;

    mat[1][0] -= scalar;
    mat[1][1] -= scalar;

    return *this;
}

mat2 mat2::operator*(const mat2 &m) const
{
    return mat2(vec2(mat[0][0] * m.mat[0][0] + mat[0][1] * m.mat[1][0],
                     mat[0][0] * m.mat[0][1] + mat[0][1] * m.mat[1][1]),
                vec2(mat[1][0] * m.mat[0][0] + mat[1][1] * m.mat[1][0],
                     mat[1][0] * m.mat[0][1] + mat[1][1] * m.mat[1][1]));
}

mat2 &mat2::operator*=(const mat2 &m)
{
    float a = mat[0][0] * m.mat[0][0] + mat[0][1] * m.mat[1][0];
    float b = mat[0][0] * m.mat[0][1] + mat[0][1] * m.mat[1][1];
    float c = mat[1][0] * m.mat[0][0] + mat[1][1] * m.mat[1][0];
    float d = mat[1][0] * m.mat[0][1] + mat[1][1] * m.mat[1][1];

    mat[0][0] = a;
    mat[0][1] = b;
    mat[1][0] = c;
    mat[1][1] = d;

    return *this;
}

vec2 mat2::operator*(const vec2 &v) const
{
    return vec2(mat[0][0] * v.x + mat[0][1] * v.y,
                mat[1][0] * v.x + mat[1][1] * v.y);
}

vec2 &mat2::operator*=(vec2 &v)
{
    v.x = mat[0][0] * v.x + mat[0][1] * v.y;
    v.y = mat[1][0] * v.x + mat[1][1] * v.y;

    return v;
}

mat2 mat2::operator*(float scalar) const
{
    return mat2(vec2(mat[0][0] * scalar, mat[0][1] * scalar),
                vec2(mat[1][0] * scalar, mat[1][1] * scalar));
}

mat2 &mat2::operator*=(float scalar)
{
    mat[0][0] *= scalar;
    mat[0][1] *= scalar;

    mat[1][0] *= scalar;
    mat[1][1] *= scalar;

    return *this;
}

mat2 mat2::operator/(float scalar) const
{
    if (scalar == 0.f)
        throw std::runtime_error("mat2::operator/: division by zero");

    return mat2(vec2(mat[0][0] / scalar, mat[0][1] / scalar),
                vec2(mat[1][0] / scalar, mat[1][1] / scalar));
}

mat2 &mat2::operator/=(float scalar)
{
    if (scalar == 0.f)
        throw std::runtime_error("mat2::operator/: division by zero");

    mat[0][0] /= scalar;
    mat[0][1] /= scalar;

    mat[1][0] /= scalar;
    mat[1][1] /= scalar;

    return *this;
}

bool mat2::operator==(const mat2 &m) const
{
    return mat[0][0] == m.mat[0][0] && mat[0][1] == m.mat[0][1] &&
           mat[1][0] == m.mat[1][0] && mat[1][1] == m.mat[1][1];
}

bool mat2::operator!=(const mat2 &m) const
{
    return !(*this == m);
}