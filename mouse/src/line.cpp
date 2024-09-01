#include "line.h"
#include <iostream>
#include <glm/glm.hpp>

Line::Line() : VAO(0), VBO(0), start(glm::vec3(0.0f)), end(glm::vec3(0.0f)), color(glm::vec4(0.0f)) { }

Line::Line(glm::vec3 start, glm::vec3 end, glm::vec4 color) : VAO(0), VBO(0), start(start), end(end), color(color) { }

void Line::setup()
{
    // Define the vertices of the line
    float vertices[] = {
        start.x, start.y, start.z,
        end.x, end.y, end.z
    };

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

void Line::draw()
{
    // Bind the VAO and draw the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
}

void Line::cleanup()
{
    // Delete the VAO and VBO
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

glm::vec4 Line::getColor()
{
    return color;
}

void Line::setColor(glm::vec4 color)
{
    this->color = color;
}