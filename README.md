<!--
Tags: OpenGL, C++, Graphics Programming, Computer Graphics, Shader Programming, Line Drawing, Clipping Algorithms, 3D Graphics, Bezier Curves, Parametric Surfaces
-->

# OpenGL C++ Labs

![OpenGL](https://img.shields.io/badge/OpenGL-3.0-blue.svg)
![GLFW](https://img.shields.io/badge/GLFW-3.3-orange.svg)
![GLAD](https://img.shields.io/badge/GLAD-2.1-yellow.svg)
![GLM](https://img.shields.io/badge/GLM-0.9.9-green.svg)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
[![License: MIT](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://opensource.org/licenses/MIT)

Welcome to the **OpenGL C++ Labs** repository! This repository contains a series of labs designed to help you learn and experiment with OpenGL using C++. Each lab focuses on different aspects of computer graphics, starting from basic OpenGL setup to more advanced topics like 3D graphics and parametric surfaces.

## Table of Contents

1. [Lab 1: Setting Up OpenGL and Shaders](#lab-1-setting-up-opengl-and-shaders)
2. [Lab 2: Mouse Input for Drawing](#lab-2-mouse-input-for-drawing)
3. [Lab 3: Line Drawing Algorithms](#lab-3-line-drawing-algorithms)
4. [Lab 4: Line and Polygon Clipping](#lab-4-line-and-polygon-clipping)
5. [Lab 5: Scanline Filling Algorithm](#lab-5-scanline-filling-algorithm)
6. [Lab 6: Bezier Curves](#lab-6-bezier-curves)
7. [Lab 7: Introduction to 3D in OpenGL](#lab-7-introduction-to-3d-in-opengl)
8. [Lab 8: Parametric Surfaces](#lab-8-parametric-surfaces)

## Lab Descriptions

### Lab 1: Setting Up OpenGL and Shaders

**Objective**: Learn how to set up an OpenGL environment and create a basic application that uses shaders to draw geometric shapes.

- **Topics Covered**:
  - Initializing OpenGL and creating a window using GLFW.
  - Writing and compiling vertex and fragment shaders.
  - Drawing triangles with different colors using shaders.

### Lab 2: Mouse Input for Drawing

**Objective**: Implement basic mouse input handling to draw multiple lines.

- **Topics Covered**:
  - Handling mouse input using GLFW.
  - Drawing lines based on mouse clicks and movements.
  - Updating the OpenGL context in response to user input.

### Lab 3: Line Drawing Algorithms

**Objective**: Implement and compare basic line drawing algorithms.

- **Topics Covered**:
  - Naive incremental line drawing algorithm.
  - Bresenham's line drawing algorithm.
  - Bresenham's circle drawing algorithm.

### Lab 4: Line and Polygon Clipping

**Objective**: Implement and understand line and polygon clipping algorithms.

- **Topics Covered**:
  - Cohen–Sutherland line clipping algorithm.
  - Sutherland-Hodgeman polygon clipping algorithm.
  - Handling complex clipping scenarios in 2D space.

### Lab 5: Scanline Filling Algorithm

**Objective**: Learn and implement the scanline filling algorithm for polygons.

- **Topics Covered**:
  - Understanding scanline algorithm principles.
  - Implementing scanline polygon filling.
  - Dealing with edge cases in polygon filling.

### Lab 6: Bezier Curves

**Objective**: Understand and implement Bezier curves for smooth curves and paths.

- **Topics Covered**:
  - Introduction to Bezier curves.
  - Implementing quadratic and cubic Bezier curves.
  - Applications of Bezier curves in graphics.

### Lab 7: Introduction to 3D in OpenGL

**Objective**: Introduce the basics of 3D graphics in OpenGL.

- **Topics Covered**:
  - Drawing simple 3D shapes like cubes and spheres.
  - Handling perspective projection.
  - Applying basic transformations (translation, rotation, scaling) in 3D space.

### Lab 8: Parametric Surfaces

**Objective**: Learn about parametric surfaces and how to implement them using OpenGL.

- **Topics Covered**:
  - Understanding parametric surface definitions.
  - Implementing basic parametric surfaces (e.g., planes, cylinders).
  - Applications of parametric surfaces in graphics.

## Getting Started

To get started with these labs, clone the repository and follow the setup instructions provided in each lab's directory. Ensure you have the necessary tools and libraries installed, such as a C++ compiler, OpenGL, GLFW, GLAD, and GLM.

```bash
git clone https://github.com/ishak96/ComputerGraphics.git
cd ComputerGraphics
```

## Getting Started with VS Code

1. Open VS Code.
2. Navigate to the specific lab folder that you want to work on within the VS Code file explorer.
3. Update the compiler location with your `g++` compiler path in the following files:
  - `.vscode/launch.json`
  - `.vscode/tasks.json`
4. Run the Lab:
  - Go to the VS Code menu.
  - Select `Run`.
  - Choose `Run Without Debugging`.

## Contributing
Contributions are welcome! If you have ideas for new labs, improvements, or bug fixes, please fork the repository, create a new branch, and submit a pull request.
