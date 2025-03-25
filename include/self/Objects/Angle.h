#pragma once

static constexpr float DEG_TO_RAD = 0.017453292f;
static constexpr float RAD_TO_DEG = 57.2957795f;

class Angle
{
  float value;
  public:
  Angle();
  Angle(float val);

  float asRadians() const;

  float asDegrees() const;

  Angle operator+(const Angle& angle) const;

  Angle& operator+=(const Angle& angle);

  Angle operator-(const Angle& angle) const;

  Angle& operator-=(const Angle& angle);
};