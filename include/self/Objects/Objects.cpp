#include "Objects.h"

#include <cmath>
#include <GLFW/glfw3.h>

Renderable::~Renderable()
{
}

Object::Object()
{
    texture = nullptr;
}

void Object::move(vec3 offset)
{
    movement += offset;
}

void Object::move(float offset)
{
    movement += offset;
}

void Object::rotate(Angle phi)
{
    rotation += phi.asRadians();
}

void Object::rotate(Angle xPhi, Angle yPhi, Angle zPhi)
{
    rotation.x += xPhi.asRadians();
    rotation.y += yPhi.asRadians();
    rotation.z += zPhi.asRadians();
}

void Object::render() const
{
    return;
}

vec3 Object::getPosition() const
{
    return origin + movement;
}

vec3 Object::getOrigin() const
{
    return origin;
}

vec3 Object::getRotation() const
{
    return rotation;
}

Color Object::getColor() const
{
    return color;
}

void Object::setOrigin(vec3 pos)
{
    origin = pos;
}

void Object::setColor(Color color)
{
    this->color = color;
}

void Object::setTexture(Texture *texture)
{
    this->texture = texture;
}

Parallelepiped::Parallelepiped() : Object()
{
}

void Parallelepiped::render() const
{
    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    glTranslatef(origin.x + size.x / 2, origin.y - size.y / 2, origin.z - size.z / 2);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-(origin.x + size.x / 2), -(origin.y - size.y / 2), -(origin.z - size.z / 2));

    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }
    glBegin(GL_QUADS);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

     // Front face
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x, origin.y, origin.z);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y, origin.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x, origin.y - size.y, origin.z);
 
     // Back face
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x, origin.y, origin.z - size.z);
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y - size.z, origin.z - size.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);
 
     // Top face
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x, origin.y, origin.z);
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x, origin.y, origin.z - size.z);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y, origin.z);
 
     // Bottom face
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x, origin.y - size.y, origin.z);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y - size.y, origin.z - size.z);
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);
 
     // Left face
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x, origin.y, origin.z);
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x, origin.y, origin.z - size.z);
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x, origin.y - size.y, origin.z);
 
     // Right face
     glTexCoord2f(0.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y, origin.z);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
     glTexCoord2f(1.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y - size.y, origin.z - size.z);
     glTexCoord2f(0.0f, 1.0f); glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);
 

    glEnd();

    if (texture)
    {
        glDisable(GL_TEXTURE_2D);
        Texture::unbind();
    }


    glPopMatrix();
}

void Parallelepiped::setSize(vec3 size)
{
    this->size = size;
}

vec3 Parallelepiped::getSize() const
{
    return size;
}

Cube::Cube() : Object()
{
    size = 0.f;
}

void Cube::render() const
{
    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    glTranslatef(origin.x + size / 2, origin.y - size / 2, origin.z - size / 2);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-(origin.x + size / 2), -(origin.y - size / 2), -(origin.z - size / 2));

    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }
    glBegin(GL_QUADS);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    // Front face

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size, origin.z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z);

    // Back face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y, origin.z - size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z - size);

    // Top face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z - size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y, origin.z - size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z);

    // Bottom face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size, origin.z);

    // Left face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size, origin.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z - size);

    // Right face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z - size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size, origin.y - size, origin.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x + size, origin.y, origin.z - size);

    glEnd();
    if (texture)
    {
        glDisable(GL_TEXTURE_2D);
        Texture::unbind();
    }
    glPopMatrix();
}

void Cube::setSize(float size)
{
    this->size = size;
}

float Cube::getSize() const
{
    return size;
}

Cone::Cone() : Object()
{
    radius = 0.f;
    height = 0.f;
}

void Cone::render() const
{
    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    glTranslatef(origin.x + radius / 2, origin.y - radius / 2, origin.z - radius / 2);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-(origin.x + radius / 2), -(origin.y - radius / 2), -(origin.z - radius / 2));

    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glTexCoord2f(0.5f, 0.5f); // Center of the texture for the origin
    glVertex3f(origin.x, origin.y, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float xoff = cosf((float)i * DEG_TO_RAD);
        float zoff = sinf((float)i * DEG_TO_RAD);
        float u = (xoff + 1.0f) * 0.5f; // Mapping x [-1, 1] to u [0, 1]
        float v = (zoff + 1.0f) * 0.5f; // Mapping z [-1, 1] to v [0, 1]
        glTexCoord2f(u, v);
        glVertex3f(origin.x + xoff, origin.y, origin.z + zoff);
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glTexCoord2f(0.5f, 0.5f); // Center of the texture for the top
    glVertex3f(origin.x, origin.y + height, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float xoff = cosf((float)i * DEG_TO_RAD);
        float zoff = sinf((float)i * DEG_TO_RAD);
        float u = (xoff + 1.0f) * 0.5f;
        float v = (zoff + 1.0f) * 0.5f;
        glTexCoord2f(u, v);
        glVertex3f(origin.x + xoff, origin.y, origin.z + zoff);
    }

    glEnd();

    if (texture)
    {
        glDisable(GL_TEXTURE_2D);
        Texture::unbind();
    }
    glPopMatrix();
}

void Cone::setRadius(float radius)
{
    this->radius = radius;
}

void Cone::setHeight(float height)
{
    this->height = height;
}

float Cone::getRadius() const
{
    return radius;
}

float Cone::getHeight() const
{
    return height;
}

Cylinder::Cylinder() : Object()
{
    height = baseRadius = topRadius = 0.f;
}

void Cylinder::render() const
{
    glPushMatrix();

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(movement.x, movement.y, movement.z);

    // base circle
    glBegin(GL_TRIANGLE_FAN);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glVertex3f(origin.x, origin.y, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float xoff = cosf((float)i * DEG_TO_RAD);
        float zoff = sinf((float)i * DEG_TO_RAD);
        glVertex3f(origin.x + xoff, origin.y, origin.z + zoff);
    }

    glEnd();

    // top circle
    glBegin(GL_TRIANGLE_FAN);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

    glVertex3f(origin.x, origin.y + height, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float xoff = cosf((float)i * DEG_TO_RAD);
        float zoff = sinf((float)i * DEG_TO_RAD);
        glVertex3f(origin.x + xoff, origin.y + height, origin.z + zoff);
    }

    glEnd();

    // side
    glBegin(GL_QUAD_STRIP);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

    for (int i = 0; i <= 360; i += 12)
    {
        float xoff = cosf((float)i * DEG_TO_RAD);
        float zoff = sinf((float)i * DEG_TO_RAD);
        glVertex3f(origin.x + xoff, origin.y, origin.z + zoff);
        glVertex3f(origin.x + xoff, origin.y + height, origin.z + zoff);
    }

    glEnd();

    glPopMatrix();
}

void Cylinder::setBaseRadius(float radius)
{
    baseRadius = radius;
}

void Cylinder::setTopRadius(float radius)
{
    topRadius = radius;
}

void Cylinder::setHeight(float height)
{
    this->height = height;
}

float Cylinder::getBaseRadius() const
{
    return baseRadius;
}

float Cylinder::getTopRadius() const
{
    return topRadius;
}

float Cylinder::getHeight() const
{
    return height;
}
