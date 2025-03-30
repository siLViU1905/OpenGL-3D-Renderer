#ifndef __CLOCK_H__
#define __CLOCK_H__
#include <chrono>
#include "Time.h"

class Clock
{
   std::chrono::steady_clock::time_point startingTime;
public:

  Clock();

  Time elapsedTime() const;

  Time restart();
  
};

#endif // __CLOCK_H__