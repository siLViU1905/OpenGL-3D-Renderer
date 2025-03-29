#include "Error.h"

sGLError sGLErrors;

sGLError::sGLError()
{
    errorType = ErrorType::NaN;
}

bool sGLError::good() const
{
    return errorType == ErrorType::NaN;
}

std::vector<std::pair<ErrorType, const char *>> sGLError::getErrors() const
{
    std::vector<std::pair<ErrorType, const char *>> errors;

    if (errorType == ErrorType::WindowError)
        errors.emplace_back(errorType, windowError.c_str());
    else if (errorType == ErrorType::ShaderError)
        errors.emplace_back(errorType, shaderError.c_str());
    else if (errorType == ErrorType::TextureError)
        errors.emplace_back(errorType, textureError.c_str());

    return errors;
}