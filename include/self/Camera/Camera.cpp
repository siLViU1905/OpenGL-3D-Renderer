#include "Camera.h"
#include "../../GL/glad.h"
#include "../../GLFW/glfw3.h"
#include <cmath>

Camera::Camera(const Window *window) : yaw(0.f), pitch(0.f), speed(0.2f), window(window)
{
    window->getRelativeCursorPosition(cx, cy);
}

void Camera::setPosition(vec3 pos)
{
    position = pos;
}

vec3 Camera::getPosition() const
{
    return forward + right + position;
}

void Camera::setSpeed(float speed)
{
    this->speed = speed;
}

float Camera::getSpeed() const
{
    return speed;
}

vec3 Camera::looksAt() const
{
    return forward.getNormal();
}

void Camera::setMouseSensivity(float mouseSensivity)
{
    this->mouseSensivity = mouseSensivity;
}

float Camera::getMouseSensivity() const
{
    return mouseSensivity;
}

float Camera::getYaw() const
{
    return yaw;
}

float Camera::getPitch() const
{
    return pitch;
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

    forward.x = std::sin(yaw * 3.14159f / 180.0f) * std::cos(pitch * 3.14159f / 180.0f);
    forward.y = std::sin(pitch * 3.14159f / 180.0f);
    forward.z = -std::cos(yaw * 3.14159f / 180.0f) * std::cos(pitch * 3.14159f / 180.0f);

    right.x = std::sin((yaw + 90.f) * 3.14159f / 180.f);
    right.z = -std::cos((yaw + 90.f) * 3.14159f / 180.f);

    if (window->isKeyPressed(GLFW_KEY_W))
        move(forward * speed);
    else if (window->isKeyPressed(GLFW_KEY_S))
        move(forward * -speed);
    if (window->isKeyPressed(GLFW_KEY_A))
        move(right * -speed);
    else if (window->isKeyPressed(GLFW_KEY_D))
        move(right * speed);
    if (window->isKeyPressed(GLFW_KEY_SPACE))
        move({0.f, speed, 0.f});
    else if (window->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
        move({0.f, -speed, 0.f});
}