// Vertex Shader Source Code (GLSL)
#version 330 core
layout (location = 0) in vec3 aPos;

uniform float windowWidth;
uniform float windowHeight;

void main()
{
    // Normalize the coordinates based on the window size
    gl_Position = vec4(aPos.x / (windowWidth / 2.0), aPos.y / (windowHeight / 2.0) - 1.0, aPos.z, 1.0);
}