#include "Logger.h"
Logger::Logger(const char* log, std::ostream& outputStream)
{
    outputStream << log<<'\n';
}
