#include "triangle.h"
#include <iostream>
#include <glm/glm.hpp>

Triangle::Triangle(float* vertices, glm::vec4 color) : VAO(0), VBO(0), vertices(vertices), color(color)
{

}

void Triangle::setup()
{
    // Generate the VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the VAO and VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Copy the vertices data to the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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

glm::vec4 Triangle::getColor()
{
    return color;
}

void Triangle::setColor(glm::vec4 color)
{
    this->color = color;
}

float* Triangle::getVertices()
{
    return vertices;
}

void Triangle::setVertices(float* vertices)
{
    this->vertices = vertices;
}