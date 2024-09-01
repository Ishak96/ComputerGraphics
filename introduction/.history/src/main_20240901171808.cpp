#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"
#include "triangle.h"
#include <glm/glm.hpp>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// define consants colors
glm::vec4 lightGreen = glm::vec4(0.45f, 0.96f, 0.4f, 1.0f);
glm::vec4 lightRed = glm::vec4(0.96f, 0.45f, 0.4f, 1.0f);
glm::vec4 softWhite = glm::vec4(0.9f, 0.9f, 0.9f, 1.0f);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Shader program
    Shader shader("assests/vertex_shader.glsl", "assests/fragment_shader.glsl");
    Triangle triangle(lightGreen);

    // // Triangles
    // float vertices1[] = {
    //     300.0f, 400.0f, 0.0f, // top
    //     100.0f, 200.0f, 0.0f, // bottom left
    //     300.0f, 200.0f, 0.0f  // bottom right
    // };
    // float vertices2[] = {
    //     600.0f, 400.0f, 0.0f, // top
    //     500.0f, 200.0f, 0.0f, // bottom left
    //     700.0f, 200.0f, 0.0f  // bottom right
    // };
    // float vertices3[] = {
    //     400.0f, 250.0f, 0.0f, // bottom
    //     300.0f, 350.0f, 0.0f, // top left
    //     500.0f, 350.0f, 0.0f  // top right
    // };

    // // Set up the triangles
    // Triangle triangles[] = {
    //     Triangle(vertices1, lightGreen),
    //     Triangle(vertices2, softWhite),
    //     Triangle(vertices3, lightRed)
    // };
    // for (size_t i = 0; i < sizeof(triangles) / sizeof(triangles[0]); i++)
    // {
    //     triangles[i].setup();
    // }
    triangle.setup();

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.f, 0.f, 0.f, 1.0f); // RGBA
        glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer

        shader.use();
        // shader.setWindowSizeUniforms(window);

        // for (size_t i = 0; i < sizeof(triangles) / sizeof(triangles[0]); i++)
        // {
        //     shader.setColor(triangles[i].getColor());
        //     triangles[i].draw();
        // }
        shader.setColor(triangle.getColor());
        triangle.draw();

        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleanup
    // for (size_t i = 0; i < sizeof(triangles) / sizeof(triangles[0]); i++)
    // {
    //     triangles[i].cleanup();
    // }
    triangle.cleanup();
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
