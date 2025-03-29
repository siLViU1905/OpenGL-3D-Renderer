#include "../include/self/sgl.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <thread>

float dDistance(vec3 pos1, vec3 pos2)
{
    float x = (pos2.x - pos1.x) * (pos2.x - pos1.x);
    float y = (pos2.y - pos1.y) * (pos2.x - pos1.y);
    float z = (pos2.z - pos1.z) * (pos2.z - pos1.z);

    return std::sqrt(x + y + z);
}


int main()
{
    Window window(1080, 720, "Scene");

    window.setClearColor(Color{0.529f, 0.808f, 0.922f});

    Camera camera(&window);

    camera.setPosition({0.f, 0.f, 5.f});
    camera.setMouseSensivity(0.06f);

    float gridSize = 10.f;

    if (!sGLErrors.good())
        return -1;


    Cube cube;
    cube.setOrigin({1.f,1.f,1.f});
    cube.setSize(1.f);
    cube.setColor(Color::Green);

    Parallelepiped para;
    para.setOrigin({7.f,5.f,6.f});
    para.setSize({3,2,4});
    para.setColor(Color::Black);

    Event event;
    while (window.isOpen())
    {
        while (window.pollEvents(event))
        {
            if (event.type == EventType::Keyboard && event.keyboard.key == GLFW_KEY_ESCAPE)
                window.close();
            else if (event.type == EventType::WindowResized)
            {
                int width, height;
                window.getWindowSize(width, height);
                window.resizeWindow(width, height);
            }
            else if (event.type == EventType::Mouse)
            {
                if (event.mouse.button == GLFW_MOUSE_BUTTON_LEFT && event.mouse.action)
                    window.inputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                else if (event.mouse.button == GLFW_MOUSE_BUTTON_RIGHT && event.mouse.action)
                    window.inputMode(GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }

        camera.update();

        window.clear();

        window.render(camera);

        window.render(cube);

        window.render(para);

        window.display();
    }
    return 0;
}
