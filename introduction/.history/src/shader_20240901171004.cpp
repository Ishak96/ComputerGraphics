#include "shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    // 1. Retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile(vertexPath);
    std::ifstream fShaderFile(fragmentPath);
    
    if (!vShaderFile.is_open() || !fShaderFile.is_open())
    {
        std::cerr << "Failed to open shader files!" << std::endl;
        return;
    }

    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    vShaderFile.close();
    fShaderFile.close();
    
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // 2. Compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    // Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    // Shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    // Delete shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    // Use the shader program
    glUseProgram(ID);
}

unsigned int Shader::getID() const
{
    return ID;
}

void Shader::setColor(const glm::vec4& color)
{
    // Get the location of the uniform variable in the shader
    int vertexColorLocation = glGetUniformLocation(ID, "ourColor");
    
    // Pass the color values to the shader
    glUniform4f(vertexColorLocation, 1, glm::value_ptr(color));
}

// void Shader::setWindowSizeUniforms(GLFWwindow* window) {
//     // Query the current window size
//     int width, height;
//     glfwGetWindowSize(window, &width, &height);

//     // Get the location of the uniform variables in the shader
//     GLint windowWidthLoc = glGetUniformLocation(ID, "windowWidth");
//     GLint windowHeightLoc = glGetUniformLocation(ID, "windowHeight");

//     // Pass the window size values to the shader
//     glUniform1f(windowWidthLoc, (float)width);
//     glUniform1f(windowHeightLoc, (float)height);
// }

void Shader::checkCompileErrors(unsigned int shader, const std::string& type)
{
    int success;
    char infoLog[512];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n";
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 512, NULL, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n";
        }
    }
}