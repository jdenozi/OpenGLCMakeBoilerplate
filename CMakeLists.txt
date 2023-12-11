cmake_minimum_required(VERSION 3.21)

project(
        OpenGLCMakeBoilerplate
        VERSION 0.0.1
        DESCRIPTION "OpenGLCMakeBoilerplate is a C++ project aimed at providing a boilerplate for OpenGL development using GLFW, GLEW, and GLM. This project is set up with CMake to facilitate easy building and dependency management."
        LANGUAGES CXX
)

include(FetchContent)

# Add GLFW
FetchContent_Declare(
        GLFW
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.8
)

FetchContent_GetProperties(GLFW)
if(NOT glfw_POPULATED)
    FetchContent_Populate(GLFW)

    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target" FORCE)

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

# Add GLEW
FetchContent_Declare(
        GLEW
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake
        GIT_TAG        master
)

FetchContent_GetProperties(GLEW)
if(NOT GLEW_POPULATED)
    FetchContent_Populate(GLEW)

    # Adjust GLEW options as needed
    set(BUILD_SHARED_LIBS ON CACHE BOOL "Build the GLEW shared library" FORCE)
    set(ONLY_LIBS ON CACHE BOOL "Build only the GLEW library" FORCE)
    add_subdirectory(${glew_SOURCE_DIR}/build/cmake ${glew_BINARY_DIR})
    include_directories(${glew_SOURCE_DIR}/include)

endif()

# Add GLM
FetchContent_Declare(
        GLM
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        master
)

FetchContent_GetProperties(GLM)
if(NOT GLM_POPULATED)
    FetchContent_Populate(GLM)

    # No need to adjust GLM options
    add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
endif()

# Add your include directories
include_directories(libs/glfw)
include_directories(include)

# Collect source files
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link OpenGL library
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_gl_LIBRARY})

# Link GLFW, GLEW, and GLM libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glew glm)

# Copy resources to the build directory
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})
