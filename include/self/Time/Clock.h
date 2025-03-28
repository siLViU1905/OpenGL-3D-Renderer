
#pragma once
#include "Time.h"

class Clock
{
   std::chrono::system_clock::time_point startingTime;
public:

  Clock();

  Time elapsedTime() const;

  Time restart();
  
};
