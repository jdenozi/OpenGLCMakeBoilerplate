# OpenGLTraining
![OpenGL Logo](https://www.opengl.org/img/opengl_logo.png)
## Description
OpenGLCMakeBoilerplate is a C++ project aimed at providing a boilerplate for OpenGL development using GLFW, GLEW, and GLM. This project is set up with CMake to facilitate easy building and dependency management.

## Dependencies
- [GLFW](https://github.com/glfw/glfw) (Version 3.3.8)
- [GLEW](https://github.com/Perlmint/glew-cmake) (Latest)
- [GLM](https://github.com/g-truc/glm) (Latest)

## Build Instructions
1. Make sure you have CMake (version 3.21 or higher) installed.
2. Clone this repository:

    ```bash
    git clone https://github.com/jdenozi/OpenGLCMakeBoilerplate.git
    ```

3. Navigate to the project directory:

    ```bash
    cd OpenGLTraining
    ```

4. Create a build directory and move into it:

    ```bash
    mkdir build
    cd build
    ```

5. Run CMake to generate build files:

    ```bash
    cmake ..
    ```

6. Build the project:

    ```bash
    cmake --build .
    ```

## Running the Application
After building the project, you can find the executable in the build directory. Run the executable to launch the OpenGL application:

```bash
./OpenGLCMakeBoilerplate
