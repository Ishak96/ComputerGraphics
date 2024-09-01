#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Triangle
{
public:
    Triangle
    void use();
    unsigned int getID() const;
    void setColor(const glm::vec4& color);
    void setWindowSizeUniforms(GLFWwindow* window);

private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, const std::string& type);
};

#endif // TRIANGLE_H