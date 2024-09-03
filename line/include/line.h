#ifndef LINE_H
#define LINE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include "point.h"

#define MAX_POINTS 500

class Line
{
public:
    Line();
    Line(Point start, Point end, std::string algorithm, glm::vec4 color);
    void naive();
    void bresenham();
    void setup();
    void draw();
    void cleanup();
    glm::vec4 getColor();
    void setColor(glm::vec4 color);
    void setStart(Point start);
    void setEnd(Point end);
    void setAlgorithm(std::string algorithm);

private:
    unsigned int VBO, VAO;
    Point start, end, set[MAX_POINTS];
    int numPoints = 0;
    glm::vec4 color;
    // A string to control the line drawing algorithm "Naive" or "Bresenham"
    std::string algorithm;
};

#endif // !LINE_H