#include "Logger.h"
Logger::Logger(const char* log, std::ostream& outputStream)
{
    outputStream << log<<'\n';
}

Logger::Logger(const unsigned char* log, std::ostream& outputStream)
{
    outputStream << log<<'\n';
}
