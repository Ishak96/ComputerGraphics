#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Triangle
{
public:
    Triangle(float* vertices, glm::vec4 color);
    void setup()
    void draw();

private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, const std::string& type);
};

#endif // TRIANGLE_H