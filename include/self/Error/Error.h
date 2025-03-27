#ifndef __SGLERROR_H__
#define __SGLERROR_H__
#include <string>
#include <optional>
#include <vector>

enum class ErrorType
{
    NaN,
    WindowError,
    ShaderError,
    TextureError
};

class sGLError
{
protected:
    std::string windowError, shaderError, textureError;
    ErrorType errorType;

public:
    sGLError();

    template <ErrorType errTy>
    const char *getIF() const
    {
        if (errorType == errTy)
        {
            if (errorType == ErrorType::WindowError)
                return windowError.c_str();
            else if (errorType == ErrorType::ShaderError)
                return shaderError.c_str();
            else if (errorType == ErrorType::TextureError)
                return textureError.c_str();
        }
        return nullptr;
    }

    template <ErrorType errTY>
    bool is() const
    {
        return errorType == errTY;
    }

    bool good() const;

    std::vector<std::pair<ErrorType,const char*>> getErrors() const;

    friend class Window;
    friend class Shader;
    friend class Texture;
};

extern std::optional<sGLError> sGLErrors;

#endif // __SGLERROR_H__