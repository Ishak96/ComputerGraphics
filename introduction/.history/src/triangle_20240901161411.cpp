#include "triangle.h"
#include <iostream>

Triangle::Triangle(float* vertices, glm::vec4 color)
    : vertices(vertices), color(color), VBO(0), VAO(0)
{

}

void Triangle::setup()
{
    // Generate and bind the Vertex Array Object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind the Vertex Buffer Object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}