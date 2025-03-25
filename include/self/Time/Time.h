#pragma once
#include <chrono>

class Time
{
    long long time;
    friend class Clock;
    Time(long long microseconds);
public:
    Time();

    float asSeconds() const;

    long long asMilliseconds() const;

    long long asMicroseconds() const;

    Time operator+(const Time &time) const;

    Time &operator+=(const Time &time);

    Time operator-(const Time &time) const;

    Time &operator-=(const Time &time);
};