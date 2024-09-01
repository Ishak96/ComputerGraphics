#include "triangle.h"
#include <iostream>

Triangle::Triangle() : VBO(0), VAO(0){ }

void Triangle::setup()
{
    // Triangle vertices
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // bottom left
         0.0f, 0.5f, 0.0f, // bottom right
         0.5f,  -0.5f, 0.0f  // top
    };   
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
}

void Triangle::draw()
{
    // Bind the VAO and draw the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::cleanup()
{
    // Delete the VAO and VBO
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

// glm::vec4 Triangle::getColor()
// {
//     return color;
// }

// void Triangle::setColor(glm::vec4 color)
// {
//     this->color = color;
// }

// float* Triangle::getVertices()
// {
//     return vertices;
// }

// void Triangle::setVertices(float* vertices)
// {
//     this->vertices = vertices;
// }