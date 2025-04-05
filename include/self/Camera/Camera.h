#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "../Window/Window.h"

class Camera : public Renderable
{
protected:
    void render() const override;

    float yaw;

    float pitch;

    float speed;

    float mouseSensivity;

    vec3 position;

    vec3 forward;

    vec3 right;

    double cx, cy;

    const Window *window;

public:
    Camera(const Window *window);

    void setPosition(vec3 pos);
    vec3 getPosition() const;

    void setSpeed(float speed);
    float getSpeed() const;

    vec3 looksAt() const;

    void setMouseSensivity(float mouseSensivity);
    float getMouseSensivity() const;

    float getYaw() const;

    float getPitch() const;

    void move(vec3 offset);

    void update();
};
#endif // __CAMERA_H__