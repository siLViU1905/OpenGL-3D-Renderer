#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <iostream>

class Logger
{
   public:
   Logger(const char* log, std::ostream& outputStream = std::cout);
};

#endif // __LOGGER_H__