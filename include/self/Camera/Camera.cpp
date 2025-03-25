#include "Camera.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

Camera::Camera(const Window *window) : yaw(0.f), pitch(0.f), speed(0.2f), window(window)
{
    window->getRelativeCursorPosition(cx, cy);
    forwardX = 0.f;
    forwardY = 0.f;
    forwardZ = 0.f;
    rightX = 0.f;
    rightZ = 0.f;
}

void Camera::setPosition(vec3 pos)
{
    position = pos;
}

vec3 Camera::getPosition() const
{
    return position;
}

void Camera::setSpeed(float speed)
{
    this->speed = speed;
}

float Camera::getSpeed() const
{
    return speed;
}

void Camera::setMouseSensivity(float mouseSensivity)
{
    this->mouseSensivity = mouseSensivity;
}

float Camera::getMouseSensivity() const
{
    return mouseSensivity;
}

void Camera::render() const
{
    glRotatef(pitch, 1.f, 0.f, 0.f);
    glRotatef(yaw, 0.f, 1.f, 0.f);

    glTranslatef(-position.x, -position.y, -position.z);
}

void Camera::move(vec3 offset)
{
    position += offset;
}

void Camera::update()
{
    double xpos, ypos;
    window->getRelativeCursorPosition(xpos, ypos);

    float xoffset = (float)xpos - (float)cx;
    float yoffset = (float)cy - (float)ypos;

    cx = xpos;
    cy = ypos;

    xoffset *= mouseSensivity;
    yoffset *= mouseSensivity;

    yaw += xoffset;
    pitch -= yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.f;
    if (yaw > 360.0f)
        yaw -= 360.0f;
    if (yaw < 0.0f)
        yaw += 360.0f;

    forwardX = std::sin(yaw * 3.14159f / 180.0f) * std::cos(pitch * 3.14159f / 180.0f);
    forwardY = std::sin(pitch * 3.14159f / 180.0f);
    forwardZ = -std::cos(yaw * 3.14159f / 180.0f) * std::cos(pitch * 3.14159f / 180.0f);

    rightX = std::sin((yaw + 90.f) * 3.14159f / 180.f);
    rightZ = -std::cos((yaw + 90.f) * 3.14159f / 180.f);

    if (window->isKeyPressed(GLFW_KEY_W))
        move({forwardX * speed, 0.f, forwardZ * speed});
    else if (window->isKeyPressed(GLFW_KEY_S))
        move({-forwardX * speed, 0.f, -forwardZ * speed});
    if (window->isKeyPressed(GLFW_KEY_A))
        move({-rightX * speed, 0.f, -rightZ * speed});
    else if (window->isKeyPressed(GLFW_KEY_D))
        move({rightX * speed, 0.f, rightZ * speed});
    if (window->isKeyPressed(GLFW_KEY_SPACE))
        move({0.f, speed, 0.f});
    else if (window->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
        move({0.f, -speed, 0.f});
}
