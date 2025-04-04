cmake_minimum_required(VERSION 3.26.0)
project(s3D_Renderer)

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/cmake/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/cmake/bin/Release)

set(CMAKE_SOLUTION_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/cmake)

include_directories(include)

link_directories(${CMAKE_SOURCE_DIR}/lib)


add_executable(s3D_Renderer
    include/GL/glad.c
    src/main.cpp
    include/self/Objects/Objects.cpp
    include/self/Objects/vec3.cpp
    include/self/Objects/Angle.cpp
    include/self/Objects/Color.cpp
    include/self/Objects/Bound.cpp
    include/self/Objects/Renderable.cpp
    include/self/Objects/Sprite.cpp
    include/self/Window/Window.cpp
    include/self/Window/Event.cpp
    include/self/Window/Keyboard.cpp
    include/self/Window/Mouse.cpp
    include/self/Sounds/Sound.cpp
    include/self/Shaders/Shader.cpp
    include/self/Shaders/Texture.cpp
    include/self/Error/Error.cpp
    include/self/GPU/GPUInfo.cpp
    include/self/Logger/Logger.cpp
    include/self/Camera/Camera.cpp
    include/self/Time/Time.cpp
    include/self/Time/Clock.cpp
    include/self/Objects/VertexArray.cpp
)

set_target_properties(s3D_Renderer PROPERTIES OUTPUT_NAME "main")

target_link_libraries(s3D_Renderer
    glfw3
    opengl32
    winmm
    psapi
    alsoft.common
    alsoft.excommon
    OpenAL32
    sndfile
)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")