#include "point.h"
#include <iostream>
#include <glm/glm.hpp>

Point::Point() : VAO(0), VBO(0), position(glm::vec3(0.0f)), color(glm::vec4(0.0f)) { }

Point::Point(glm::vec3 position, glm::vec4 color) : VAO(0), VBO(0), position(position), color(color) { }

void Point::setup()
{
    // Define the vertices of the point
    float vertices[] = {
        position.x, position.y, position.z,
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

void Point::draw()
{
    // Bind the VAO and draw the point
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 1);
}

void Point::cleanup()
{
    // Delete the VAO and VBO
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

glm::vec4 Point::getColor()
{
    return color;
}

void Point::setColor(glm::vec4 color)
{
    this->color = color;
}

glm::vec3 Point::getPosition()
{
    return position;
}

void Point::setPosition(glm::vec3 position)
{
    this->position = position;
}