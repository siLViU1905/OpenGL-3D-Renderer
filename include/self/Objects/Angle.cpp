#include "Angle.h"

Angle::Angle():value(0.f) {}

Angle::Angle(float val):value(val) {}

float Angle::asRadians() const
{
  return value*DEG_TO_RAD;
}

float Angle::asDegrees() const
{
  return value * RAD_TO_DEG;
}

Angle Angle::operator+(const Angle& angle) const
{
    return Angle(value + angle.value);
}

Angle& Angle::operator+=(const Angle& angle)
{
   value+=angle.value;
   return *this;
}

Angle Angle::operator-(const Angle& angle) const
{
    return Angle(value - angle.value);
}

Angle& Angle::operator-=(const Angle& angle)
{
   value-=angle.value;
   return *this;
}