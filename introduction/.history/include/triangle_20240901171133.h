#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Triangle
{
public:
    Triangle();
    void setup();
    void draw();
    void cleanup();
    // glm::vec4 getColor();
    // void setColor(glm::vec4 color);
    // float* getVertices();
    // void setVertices(float* vertices);    

private:
    unsigned int VBO, VAO;
    // float* vertices;
    glm::vec4 color;
};

#endif // TRIANGLE_H