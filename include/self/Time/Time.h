#ifndef __TIME_H__
#define __TIME_H__

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
#endif // __TIME_H__