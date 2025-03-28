#include "Time.h"

Time::Time(long long microseconds):time(microseconds) {}

Time::Time():time(0) {}

float Time::asSeconds() const
{
    return time / 1e+6F;
}

long long Time::asMilliseconds() const
{
    return time / 1000;
}

long long Time::asMicroseconds() const
{
    return time;
}

Time Time::operator+(const Time& _time) const
{
    return Time(time+_time.time);
}

Time& Time::operator+=(const Time& _time)
{
    time+=_time.time;
    return *this;
}

Time Time::operator-(const Time& _time) const
{
    return Time(time-_time.time);
}

Time& Time::operator-=(const Time& _time)
{
    time-=_time.time;
    return *this;
}
