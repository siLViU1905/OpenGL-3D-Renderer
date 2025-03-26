#include "Window.h"
#include <algorithm>
#include <stdexcept>
#include "../Shaders/stb_image.h"

WindowHints::WindowHints() : hints(nullptr), values(nullptr), size(0) {}

WindowHints::WindowHints(int *hints, int *values, int size)
{
    this->size = size;
    this->hints = new int[size];
    this->values = new int[size];
    std::copy(hints, hints + size, this->hints);
    std::copy(values, values + size, this->values);
}

WindowHints::WindowHints(int hint, int value)
{
    size = 1;
    hints = new int;
    values = new int;
    *hints = hint;
    *values = value;
}

WindowHints::~WindowHints()
{
    if (size == 1)
    {
        delete hints;
        delete values;
    }
    else if (size > 1)
    {
        delete[] hints;
        delete[] values;
    }
}

const WindowHints WindowHints::defaultSettings = WindowHints();

Window::Window(int width, int height, const char *title, const WindowHints &settings)
{
    if (!glfwInit())
    {
        sGLErrors->errorType = ErrorType::WindowError;
        sGLErrors->windowError += "GLFW failed\n";
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
    {
        sGLErrors->errorType = ErrorType::WindowError;
        sGLErrors->windowError += "Window creation failed\n";
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        sGLErrors->errorType = ErrorType::WindowError;
        sGLErrors->windowError += "GLEW failed\n";
    }

    glEnable(GL_DEPTH_TEST);

    for (int i = 0; i < settings.size; ++i)
        glfwWindowHint(settings.hints[i], settings.values[i]);

    glfwSetKeyCallback(window, keyboardCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetFramebufferSizeCallback(window, windowResizeCallback);
    glfwSetWindowPosCallback(window, windowMoveCallback);
    glfwSetWindowFocusCallback(window, windowFocusCallback);
    glfwSetWindowMaximizeCallback(window, windowMaximizeCallback);
    glfwSetWindowCloseCallback(window, windowCloseCallback);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.f, 0.f, 0.f, 1.f);
    icon.pixels = nullptr;
}

bool Window::isOpen() const
{
    return !glfwWindowShouldClose(window);
}

void Window::close()
{
    glfwSetWindowShouldClose(window, true);
}

GLFWwindow *Window::getWindow()
{
    return window;
}

void Window::setClearColor(vec3 color)
{
    glClearColor(color.x, color.y, color.z, 1.f);
}

void Window::inputMode(int mode, int value)
{
    glfwSetInputMode(window, mode, value);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void Window::render(const Renderable &renderable)
{
    renderable.render();
}

void Window::display()
{
    glFlush();
    glfwSwapBuffers(window);
}

Event Window::events;

void Window::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    events.type = EventType::Keyboard;
    events.keyboard.key = key;
    events.keyboard.scancode = scancode;
    events.keyboard.action = action;
    events.keyboard.mode = mode;
}

void Window::mouseButtonCallback(GLFWwindow *window, int button, int action, int mode)
{
    events.type = EventType::Mouse;
    events.mouse.button = button;
    events.mouse.action = action;
    events.mouse.mode = mode;
}

void Window::windowResizeCallback(GLFWwindow *window, int width, int height)
{
    events.type = EventType::WindowResized;
}

void Window::windowMoveCallback(GLFWwindow *window, int x, int y)
{
    events.type = EventType::WindowMoved;
}

void Window::windowFocusCallback(GLFWwindow *window, int focus)
{
    events.focused = focus;
    events.type = events.focused ? EventType::WindowGainedFocus : EventType::WindowLostFocus;
}

void Window::windowMaximizeCallback(GLFWwindow *window, int maximized)
{
    if (maximized)
        events.type = EventType::WindowMaximized;
    else
        events.type = EventType::WindowResized;
}

void Window::windowCloseCallback(GLFWwindow *window)
{
    events.type = EventType::WindowClosed;
}

bool Window::pollEvents(Event &event)
{
    events = Event();
    glfwPollEvents();
    event = events;
    if (event.type != EventType::NaN)
        return true;
    return false;
}

void Window::getWindowSize(int &width, int &height) const
{
    glfwGetWindowSize(window, &width, &height);
}

void Window::resizeWindow(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)newWidth / (float)newHeight, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Window::getRelativeCursorPosition(double &x, double &y) const
{
    glfwGetCursorPos(window, &x, &y);
}

void Window::getAbsoluteCursorPosition(double &x, double &y) const
{
    double xpos, ypos;
    int windowX, windowY;

    glfwGetCursorPos(window, &xpos, &ypos);

    glfwGetWindowPos(window, &windowX, &windowY);

    x = windowX + xpos;
    y = windowY + ypos;
}

void Window::setWindowIconImage(const char *filepath)
{
    icon.pixels = stbi_load(filepath, &icon.width, &icon.height, 0, 4);
    glfwSetWindowIcon(window, 1, &icon);
}

bool Window::isKeyPressed(int key) const
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool Window::isMouseButtonPressed(int button) const
{
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

Window::~Window()
{
    if (icon.pixels)
        stbi_image_free(icon.pixels);
    glfwDestroyWindow(window);
    glfwTerminate();
}
