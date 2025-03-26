#include <self/sgl.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <self/Shaders/stb_image.h>
void applyGravity(std::vector<Cube> &cubes, float gravity, float deltaTime, float y_limit)
{
    for (auto &object : cubes)
        if (object.getPosition().y + object.getPosition().y > y_limit)
            object.move({0.f, -gravity * deltaTime, 0.f});
}

std::string doubleToString(double value, int precision)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}

int main()
{
    Window window(1080, 720,"Scene");

    window.setClearColor({0.529f, 0.808f, 0.922f});

    window.setWindowIconImage("polo.png");

    Camera camera(&window);


    camera.setPosition({0.f, 0.f, 5.f});
    camera.setMouseSensivity(0.06f);

    constexpr float gravity = 9.81f * 1.5f;

    std::vector<Cube> cubes;


    srand(time(0));
    float gridSize = 10.f;
   
   Texture texture;
   texture.load("polo.png");

    Cube cube;
    cube.setOrigin({0.f, 5.f, 0.f});
    cube.setSize(3.f);
    cube.setTexture(&texture);
    cube.setColor(Color::White);


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
                else if(event.type == EventType::Mouse)
                {
                    if(event.mouse.button == GLFW_MOUSE_BUTTON_LEFT && event.mouse.action)
                       window.inputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                    else if(event.mouse.button == GLFW_MOUSE_BUTTON_RIGHT && event.mouse.action)
                    window.inputMode(GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                }
        }

 
        cube.rotate({70.f},{0.f},{70.f});

        camera.update();
          
        window.clear();
  
        window.render(camera);

        glBegin(GL_QUADS);

        glColor3f(0.8f, 0.8f, 0.8f);

        glVertex3f(-gridSize, -1.f, gridSize);
        glVertex3f(-gridSize, -1.f, -gridSize);
        glVertex3f(gridSize, -1.f, -gridSize);
        glVertex3f(gridSize, -1.f, gridSize);

        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        for (float i = -gridSize; i <= gridSize; i += 1.0f)
        {
            glVertex3f(i, -1.0f, -gridSize);
            glVertex3f(i, -1.0f, gridSize);
        }

        for (float i = -gridSize; i <= gridSize; i += 1.0f)
        {
            glVertex3f(-gridSize, -1.0f, i);
            glVertex3f(gridSize, -1.0f, i);
        }

        glEnd();

        window.render(cube);
      
        window.display();

    
    }
    return 0;
}
