#ifndef POINT_H
#define POINT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Point
{
public:
    Point();
    Point(glm::vec3 position, glm::vec4 color);
    void setup();
    void draw();
    void cleanup();
    glm::vec4 getColor();
    void setColor(glm::vec4 color);
    glm::vec3 getPosition();
    void setPosition(glm::vec3 position);

private:
    unsigned int VBO, VAO;
    glm::vec3 position;
    glm::vec4 color;
};

#endif // !POINT_H