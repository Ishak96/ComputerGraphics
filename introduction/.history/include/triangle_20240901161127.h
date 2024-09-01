#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Triangle
{
public:
    Triangle(float* vertices, glm::vec4 color);
    void setup();
    void draw();

private:
    unsigned int VBO, VAO;
    float* vertices;
    glm::vec4 color;
};

#endif // TRIANGLE_H