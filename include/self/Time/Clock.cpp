
#include "Clock.h"

Clock::Clock() : startingTime(std::chrono::steady_clock::now()) 
{
}

Time Clock::elapsedTime() const
{
    auto endTime = std::chrono::steady_clock::now() - startingTime;
    return Time(std::chrono::duration_cast<std::chrono::microseconds>(endTime).count());
}

Time Clock::restart()
{
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startingTime).count();
    startingTime = endTime;
    return Time(duration);
}
