#ifndef __SHADER_H__
#define __SHADER_H__
#include <string>
#include "../Error/Error.h"

class Shader
{
    unsigned int ID;
   // std::string vertexFile,fragmentFile;
    std::string vertexShader,fragmentShader; 

    public:
    Shader(const std::string& vertexFilePath,const std::string& fragmentFilePath);

    void compileShader();

    void use();
    
    void setBool(const std::string &name, bool value) const;  

    void setInt(const std::string &name, int value) const;   

    void setFloat(const std::string &name, float value) const;

    void setMat4(const std::string& name, float* mat) const;
};

#endif // __SHADER_H__