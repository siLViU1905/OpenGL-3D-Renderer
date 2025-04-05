#include "Transform2d.h"
#include <cmath>

mat2 Transform2d::rotate(Angle angle)
{
    float _sin = std::sin(angle.asRadians());
    float _cos = std::cos(angle.asRadians());

    return mat2({_cos, -_sin}, {_sin, _cos});
}

mat2 Transform2d::scale(float scale)
{
    return mat2({scale,0.f}, {0.f,scale});
}

vec2& Transform2d::translate(vec2& point, vec2 offset)
{
    return point+=offset;
}
