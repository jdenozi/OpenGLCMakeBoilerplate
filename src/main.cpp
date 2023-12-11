#include <iostream>
#include <GL/glew.h>

#include <glfw3.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    glewInit();
    glfwInit();
    return 0;
}
