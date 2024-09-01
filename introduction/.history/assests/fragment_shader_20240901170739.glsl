// Fragment Shader Source Code (GLSL)
#version 330 core

out vec4 FragColor;
uniform vec4 ourColor; // Declare a uniform variable

void main()
{
    FragColor = ourColor; // Use the uniform color
}