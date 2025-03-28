#include "GPUInfo.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const unsigned char* GPUInfo::getName()
{
    return glGetString(GL_RENDERER);
}

const unsigned char* GPUInfo::getVendor()
{
    return glGetString(GL_VENDOR);
}

const unsigned char* GPUInfo::getOpenGLVersion()
{
    return glGetString(GL_VERSION);
}

const unsigned char* GPUInfo::getGLSLVersion()
{
    return glGetString(GL_SHADING_LANGUAGE_VERSION);
}

const int GPUInfo::getMaxTextureSize()
{
    int maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE,&maxTextureSize);
    return maxTextureSize;
}
