// Vertex Shader Source Code (GLSL)
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    // Normalize the coordinates based on the window size
    gl_Position = vec4(aPos, 1.0);
}