#ifndef LINE_H
#define LINE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#define TRIANGLE_DIMENSIONS 9

class Line
{
public:
    Line();
    Line(glm::vec3 start, glm::vec3 end, glm::vec4 color); 
    void setup();
    void draw();
    void cleanup();
    glm::vec4 getColor();
    void setColor(glm::vec4 color);

private:
    unsigned int VBO, VAO;
    glm::vec3 start, end;
    glm::vec4 color;
};

#endif // !LINE_H