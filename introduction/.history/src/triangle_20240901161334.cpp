#include "triangle.h"
#include <iostream>

Triangle::Triangle(float* vertices, glm::vec4 color)
    : vertices(vertices), color(color), VBO(0), VAO(0)
{

}

void Triangle::setup()
{
    // Generate the vertex array object
    glGenVertexArrays(1, &VAO);

    // Generate the vertex buffer object
    glGenBuffers(1, &VBO);

    // Bind the vertex array object
    glBindVertexArray(VAO);

    // Bind the vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Copy the vertices data to the GPU
    glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    // Set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind the vertex array object
    glBindVertexArray(0);
}