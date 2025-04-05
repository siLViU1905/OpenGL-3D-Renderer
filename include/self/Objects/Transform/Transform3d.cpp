#include "Transform3d.h"
#include <cmath>

mat3 Transform3D::rotatex(Angle angle)
{
    float _sin = std::sin(angle.asRadians());
    float _cos = std::cos(angle.asRadians());

    return mat3({1.f, 0.f, 0.f},
                {0.f, _cos, -_sin},
                {0.f, _sin, _cos});
}

mat3 Transform3D::rotatey(Angle angle)
{
    float _sin = std::sin(angle.asRadians());
    float _cos = std::cos(angle.asRadians());

    return mat3({_cos, 0.f, _sin},
                {0.f, 1.f, 0.f},
                {-_sin, 0.f, _cos});
}

mat3 Transform3D::rotatez(Angle angle)
{
    float _sin = std::sin(angle.asRadians());
    float _cos = std::cos(angle.asRadians());

    return mat3({_cos, -_sin, 0.f},
                {_sin, _cos, 0.f},
                {0.f, 0.f, 1.f});
}

vec3 &Transform3D::translate(vec3 &point, vec3 offset)
{
    return point+=offset;
}
