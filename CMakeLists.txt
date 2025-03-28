cmake_minimum_required(VERSION 3.26.0)
project(s3D_Renderer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_GENERATOR_PLATFORM x64)

cmake_policy(SET CMP0072 NEW)

# Explicitly set library paths
set(GLFW3_LIBRARY "${CMAKE_SOURCE_DIR}/lib/libglfw3dll.a")
set(GLFW3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# GLEW library configuration
set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glew32.lib")
set(GLEW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(OPENAL_LIBRARY "${CMAKE_SOURCE_DIR}/lib/OpenAL32.lib")
set(OPENAL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(SNDFILE_LIBRARY "${CMAKE_SOURCE_DIR}/lib/sndfile.lib")
set(SNDFILE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(ALSOFTCOMMON_LIBRARY "${CMAKE_SOURCE_DIR}/lib/alsoft.common.lib")
set(ALSOFTCOMMON_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(ALSOFTEXCOMMON_LIBRARY "${CMAKE_SOURCE_DIR}/lib/alsoft.excommon.lib")
set(ALSOFTEXCOMMON_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Ensure libraries exist
if(NOT EXISTS "${GLFW3_LIBRARY}")
    message(FATAL_ERROR "GLFW library not found at ${GLFW3_LIBRARY}")
endif()

if(NOT EXISTS "${GLEW_LIBRARY}")
    message(FATAL_ERROR "GLEW library not found at ${GLEW_LIBRARY}")
endif()

find_package(OpenGL REQUIRED)

add_executable(s3D_Renderer
    src/main.cpp
    include/self/Error/Error.cpp
    include/self/GPU/GPUInfo.cpp
    include/self/Logger/Logger.cpp
    include/self/Objects/Angle.cpp
    include/self/Objects/Color.cpp
    include/self/Objects/Objects.cpp
    include/self/Objects/vec3.cpp
    include/self/Shaders/Shader.cpp
    include/self/Shaders/Texture.cpp
    include/self/Sounds/Sound.cpp
    include/self/Window/Event.cpp
    include/self/Window/Keyboard.cpp
    include/self/Window/Mouse.cpp
    include/self/Window/Window.cpp
    include/self/Camera/Camera.cpp
    include/self/Time/Clock.cpp
    include/self/Time/Time.cpp
)

target_include_directories(s3D_Renderer 
    PRIVATE 
    dependencies
    ${GLFW3_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
)

link_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(s3D_Renderer
    OpenGL::GL       
    ${GLFW3_LIBRARY} 
    ${GLEW_LIBRARY} 
    ${OPENAL_LIBRARY}         
    ${SNDFILE_LIBRARY}          
    ${ALSOFTCOMMON_LIBRARY}
    ${ALSOFTEXCOMMON_LIBRARY}
)