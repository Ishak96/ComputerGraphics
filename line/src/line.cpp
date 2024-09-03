#include "line.h"
#include <iostream>
#include <glm/glm.hpp>

Line::Line() : VAO(0), VBO(0), start(), end(), algorithm("Naive"), color(glm::vec4(0.0f)) { }

Line::Line(Point start, Point end, std::string algorithm, glm::vec4 color) : VAO(0), VBO(0), start(start), end(end), algorithm(algorithm), color(color) { }

void Line::naive() {
    float x1 = start.getPosition().x;
    float y1 = start.getPosition().y;
    float x2 = end.getPosition().x;
    float y2 = end.getPosition().y;

    float dx = x2 - x1;
    float dy = y2 - y1;

    // Stop divide by zero for vertical lines
    if (dx == 0) {
        dx = 1.0f;
    }

    float m = dy / dx;

    // Calculate the y-intercept (c) using the equation y = mx + c
    float c = y1 - m * x1;

    if (std::abs(m) <= 1.0) {
        // Line is more horizontal than vertical
        if (x1 > x2) {
            std::swap(x1, x2); // Ensure left-to-right drawing
            std::swap(y1, y2);
        }

        for (int x = x1; x <= x2; x++) {
            float y = m * x + c;
            set[numPoints++] = Point(glm::vec3(x, y, 0.0f), color);
        }
    } else {
        // Line is more vertical than horizontal
        if (y1 > y2) {
            std::swap(y1, y2); // Ensure top-to-bottom drawing
            std::swap(x1, x2);
        }

        for (int y = y1; y <= y2; y++) {
            float x = (y - c) / m;
            set[numPoints++] = Point(glm::vec3(x, y, 0.0f), color);
        }
    }
}

void Line::bresenham() {
    int x1 = start.getPosition().x;
    int y1 = start.getPosition().y;
    int x2 = end.getPosition().x;
    int y2 = end.getPosition().y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1; // step for x
    int sy = (y1 < y2) ? 1 : -1; // step for y

    bool steep = dy > dx;  // Determine if the line is steep (more vertical than horizontal)

    if (steep) {
        std::swap(dx, dy); // swap dx and dy if the line is steep
    }

    int slope_error = 2 * dy - dx; // Initialize the error term

    int x = x1, y = y1;

    for (int i = 0; i <= dx; i++) {
        set[numPoints++] = Point(glm::vec3(x, y, 0.0f), color);

        if (slope_error >= 0) {
            if (steep) {
                x += sx; // Adjust x when the line is steep
            } else {
                y += sy; // Adjust y when the line is not steep
            }
            slope_error -= 2 * dx;
        }

        if (steep) {
            y += sy; // Adjust y when the line is steep
        } else {
            x += sx; // Adjust x when the line is not steep
        }
        slope_error += 2 * dy;
    }
}

void Line::setup()
{
    // Selec the algorithm to draw the line
    if (algorithm == "Naive")
    {
        naive();
    }
    else if (algorithm == "Bresenham")
    {
        bresenham();
    }

    // Loop through the set of points and setup each one
    for (int i = 0; i < numPoints; i++)
    {
        set[i].setup();
    }
}

void Line::draw()
{
    // Loop through the set of points and draw each one
    for (int i = 0; i < numPoints; i++)
    {
        set[i].draw();
    }
}

void Line::cleanup()
{
    // Loop through the set of points and cleanup each one
    for (int i = 0; i < numPoints; i++)
    {
        set[i].cleanup();
    }
}

glm::vec4 Line::getColor()
{
    return color;
}

void Line::setColor(glm::vec4 color)
{
    this->color = color;
}

void Line::setStart(Point start)
{
    this->start = start;
}

void Line::setEnd(Point end)
{
    this->end = end;
}

void Line::setAlgorithm(std::string algorithm)
{
    this->algorithm = algorithm;
}