#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    unsigned int getID() const;
    void setColor(const glm::vec4& color);
    void setWindowSizeUniforms(GLFWwindow* window);

private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, const std::string& type);
};

#endif // SHADER_H