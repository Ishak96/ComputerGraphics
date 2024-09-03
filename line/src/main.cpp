#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"
#include "point.h"
#include "line.h"
#include <glm/glm.hpp>

// Constants --------------------------------------------------------------------
const int MAX_LINES = 100;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
// Colors
const glm::vec4 lightGreen = glm::vec4(0.45f, 0.96f, 0.4f, 1.0f);
const glm::vec4 lightRed = glm::vec4(0.96f, 0.45f, 0.4f, 1.0f);
const glm::vec4 softWhite = glm::vec4(0.9f, 0.9f, 0.9f, 1.0f);
//------------------------------------------------------------------------------

// Data structures --------------------------------------------------------------
typedef struct {
    Line lines[MAX_LINES];
    int size;
} LineCollection;
//------------------------------------------------------------------------------

// Global variables -------------------------------------------------------------
LineCollection lineSet;
bool isFirstClick = true;    // To track whether it's the first or second click
Point startPoint;        // To store the start point of a line
//------------------------------------------------------------------------------

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Line drawing", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Shader program
    Shader shader("assests/vertex_shader.glsl", "assests/fragment_shader.glsl");

    // Lines
    lineSet.size = 0;

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.f, 0.f, 0.f, 1.0f); // RGBA
        glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer

        shader.use();
        shader.setWindowSizeUniforms(window);

        // draw
        for (int i = 0; i < lineSet.size; i++)
        {
            shader.setColor(lineSet.lines[i].getColor());
            lineSet.lines[i].draw();
        }

        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleanup
    for (int i = 0; i < lineSet.size; i++)
    {
        lineSet.lines[i].cleanup();
    }

    glfwTerminate();
    return 0;
}

// process all input
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse button is clicked
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // Adjust the y-coordinate to match the OpenGL coordinate system
        ypos = SCR_HEIGHT - ypos;
        
        if (isFirstClick)
        {
            startPoint = Point(glm::vec3(xpos, ypos, 0.0f), lightRed);
            isFirstClick = false;
        }
        else
        {
            Point endPoint = Point(glm::vec3(xpos, ypos, 0.0f), lightRed);
            if (lineSet.size < MAX_LINES)
            {
                Line line(startPoint, endPoint, "Bresenham", lightRed);
                line.setup();
                lineSet.lines[lineSet.size] = line;
                lineSet.size++;
            }
            else
            {
                std::cout << "Max number of lines reached" << std::endl;
            }
            isFirstClick = true;
        }
    }
}