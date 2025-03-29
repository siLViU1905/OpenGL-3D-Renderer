-- premake5.lua
workspace "s3D_Renderer"
    configurations { "Debug", "Release" }
    architecture "x64"

project "s3D_Renderer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20" 
    targetdir "src/output"
    targetname "main"

    includedirs { "include" }
    libdirs { "lib" }

    files {
        "include/GL/glad.c",
        "src/main.cpp",
        "include/self/Objects/Objects.cpp",
        "include/self/Objects/vec3.cpp",
        "include/self/Objects/Angle.cpp",
        "include/self/Objects/Color.cpp",
        "include/self/Objects/Bound.cpp",
        "include/self/Objects/Renderable.cpp",
        "include/self/Window/Window.cpp",
        "include/self/Window/Event.cpp",
        "include/self/Window/Keyboard.cpp",
        "include/self/Window/Mouse.cpp",
        "include/self/Sounds/Sound.cpp",
        "include/self/Shaders/Shader.cpp",
        "include/self/Shaders/Texture.cpp",
        "include/self/Error/Error.cpp",
        "include/self/GPU/GPUInfo.cpp",
        "include/self/Logger/Logger.cpp",
        "include/self/Camera/Camera.cpp",
        "include/self/Time/Time.cpp",
        --"include/self/Time/Clock.cpp" --problems with std::chrono, not important now
    }

    links {
        "glfw3",
        "opengl32",
        "alsoft.common",
        "alsoft.excommon",
        "OpenAL32",
        "sndfile"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        