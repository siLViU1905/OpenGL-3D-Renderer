#include "Shader.h"
#include <fstream>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


Shader::Shader(const std::string &vertexFilePath, const std::string &fragmentFilePath)
{
    std::ifstream vertexIn(vertexFilePath);
    if (!vertexIn.is_open())
        throw std::runtime_error("File not found");
     vertexShader=std::string((std::istreambuf_iterator<char>(vertexIn)),(std::istreambuf_iterator<char>()));

    std::ifstream fragmentIn(fragmentFilePath);
    if (!fragmentIn.is_open())
        throw std::runtime_error("File not found");
        fragmentShader=std::string((std::istreambuf_iterator<char>(fragmentIn)),(std::istreambuf_iterator<char>()));
}

void Shader::compileShader()
{
    unsigned int vertex, fragment;
    int succes;
    char infoLog[512];
    vertex = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexCode = vertexShader.c_str();
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex,GL_COMPILE_STATUS,&succes);
    if(!succes)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        throw std::runtime_error(infoLog);
    }

    fragment=glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentCode = fragmentShader.c_str();
    glShaderSource(fragment,1,&fragmentCode,NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment,GL_COMPILE_STATUS,&succes);
    if(!succes)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        throw std::runtime_error(infoLog);
    }

    ID = glCreateProgram();

    glAttachShader(ID,vertex);
    glAttachShader(ID,fragment);

    glLinkProgram(ID);

    glGetProgramiv(ID,GL_LINK_STATUS,&succes);
    if(!succes)
    {
        glGetProgramInfoLog(ID,512,NULL,infoLog);
        throw std::runtime_error(infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 

void Shader::setMat4(const std::string& name, float* mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, mat);
}


