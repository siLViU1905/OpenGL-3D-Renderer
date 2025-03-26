#include "Error.h"

std::optional<sGLError> sGLErrors;

sGLError::sGLError()
{
    errorType = ErrorType::NaN;
}

bool sGLError::good() const
{
    return errorType == ErrorType::NaN;
}