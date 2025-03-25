cmake_minimum_required(VERSION 3.10)
project(OpenGL)

set(CMAKE_CXX_STANDARD 26)
find_package(OpenGL REQUIRED)



include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/self/Objects/*.cpp" "include/self/Shaders/*.cpp" "include/self/Sounds/*.cpp"
"include/self/Time/*.cpp" "include/self/Window/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} OpenGL::GL)