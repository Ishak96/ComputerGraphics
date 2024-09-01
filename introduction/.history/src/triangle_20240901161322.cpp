#include "triangle.h"
#include <iostream>

Triangle::Triangle(float* vertices, glm::vec4 color)
    : vertices(vertices), color(color), VBO(0), VAO(0)
{

}