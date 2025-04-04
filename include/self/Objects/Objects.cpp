#include "Objects.h"

#include <cmath>
#include "../../GL/glad.h"
#include "../../GLFW/glfw3.h"

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
    rotation += phi.asDegrees();

    if (rotation.x > 360.f)
        rotation.x -= 360.f;
    if (rotation.y > 360.f)
        rotation.y -= 360.f;
    if (rotation.z > 360.f)
        rotation.z -= 360.f;
}

void Object::rotate(Angle xPhi, Angle yPhi, Angle zPhi)
{
    rotation.x += xPhi.asDegrees();
    rotation.y += yPhi.asDegrees();
    rotation.z += zPhi.asDegrees();

    if (rotation.x > 360.f)
        rotation.x -= 360.f;
    if (rotation.y > 360.f)
        rotation.y -= 360.f;
    if (rotation.z > 360.f)
        rotation.z -= 360.f;
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

Bound Parallelepiped::getBound() const
{
    Bound bound;
    bound.position = getPosition();
    bound.size = size;
    bound.rotation = getRotation();
    return bound;
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
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z);

    // Back face
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z - size.z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z - size.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);

    // Top face
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y, origin.z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z - size.z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z);

    // Bottom face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z - size.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);

    // Left face
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x, origin.y, origin.z - size.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z - size.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x, origin.y - size.y, origin.z);

    // Right face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(origin.x + size.x, origin.y, origin.z - size.z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z - size.z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(origin.x + size.x, origin.y - size.y, origin.z);

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

Bound Cube::getBound() const
{
    Bound bound;
    bound.position = getPosition();
    bound.size = vec3(size, size, size);
    bound.rotation = getRotation();
    return bound;
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

Bound Cone::getBound() const
{
    Bound bound;
    bound.size = {radius, height, radius};
    bound.position = getPosition() + vec3(-radius * 0.5f, 0.f, radius * 0.5f);
    return bound;
}

void Cone::render() const
{
    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    glTranslatef(origin.x, origin.y - height / 2.f, origin.z);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-origin.x, -(origin.y - height / 2.f), -origin.z);

    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(origin.x, origin.y - height, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float angle = (float)i * DEG_TO_RAD;
        float xoff = std::cos(angle);
        float zoff = std::sin(angle);

        float u = (xoff + 1.0f) * 0.5f;
        float v = (zoff + 1.0f) * 0.5f;
        glTexCoord2f(u, v);
        glVertex3f(origin.x + xoff, origin.y - height, origin.z + zoff);
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(origin.x, origin.y, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float angle = (float)i * DEG_TO_RAD;
        float xoff = std::cos(angle);
        float zoff = std::sin(angle);
        float u = (xoff + 1.0f) * 0.5f;
        float v = (zoff + 1.0f) * 0.5f;
        glTexCoord2f(u, v);
        glVertex3f(origin.x + xoff, origin.y - height, origin.z + zoff);
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

Bound Cylinder::getBound() const
{
    Bound bound;
    float maxRadius = std::max(baseRadius, topRadius);
    bound.position = getPosition() + vec3(-maxRadius, 0.f, maxRadius);
    bound.size = vec3(maxRadius + maxRadius, height, maxRadius + maxRadius);
    return bound;
}

void Cylinder::render() const
{
    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    float centerX = origin.x;
    float centerY = origin.y - height / 2.f;
    float centerZ = origin.z;

    glTranslatef(centerX, centerY, centerZ);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-centerX, -centerY, -centerZ);

    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }

    glBegin(GL_TRIANGLE_FAN);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

    glTexCoord2f(0.5f, 0.5f);

    glVertex3f(origin.x, origin.y - height, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float angle = (float)i * DEG_TO_RAD;
        float xoff = std::cos(angle) * baseRadius;
        float zoff = std::sin(angle) * baseRadius;
        glVertex3f(origin.x + xoff, origin.y - height, origin.z + zoff);

        if (texture)
        {
            float u = 0.5f + 0.5f * std::cos(angle);
            float v = 0.5f + 0.5f * std::sin(angle);
            glTexCoord2f(u, v);
        }
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

    glTexCoord2f(0.5f, 0.5f);

    glVertex3f(origin.x, origin.y, origin.z);

    for (int i = 0; i <= 360; i += 12)
    {
        float angle = (float)i * DEG_TO_RAD;
        float xoff = cosf(angle) * topRadius;
        float zoff = sinf(angle) * topRadius;
        glVertex3f(origin.x + xoff, origin.y, origin.z + zoff);

        if (texture)
        {
            float u = 0.5f + 0.5f * std::cos(angle);
            float v = 0.5f + 0.5f * std::sin(angle);
            glTexCoord2f(u, v);
        }
    }

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);

    for (int i = 0; i <= 360; i += 12)
    {
        float angle = (float)i * DEG_TO_RAD;
        float cosA = std::cos(angle);
        float sinA = std::sin(angle);

        if (texture)
            glTexCoord2f((float)i / 360.f, 0.f);

        float baseX = origin.x + cosA * baseRadius;
        float baseZ = origin.z + sinA * baseRadius;
        glVertex3f(baseX, origin.y - height, baseZ);

        if (texture)
            glTexCoord2f((float)i / 360.f, 1.f);

        float topX = origin.x + cosA * topRadius;
        float topZ = origin.z + sinA * topRadius;
        glVertex3f(topX, origin.y, topZ);
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

Sphere::Sphere() : radius(0.f), stacks(30), slices(30)
{
}

void Sphere::setRadius(float radius)
{
    this->radius = radius;
}

float Sphere::getRadius() const
{
    return radius;
}

Bound Sphere::getBound() const
{
    Bound bound;
    float doubleRadius = radius * 2.f;
    bound.size = {doubleRadius, doubleRadius, doubleRadius};
    bound.position = getPosition() + vec3(-radius, radius, radius);
    return bound;
}

void Sphere::setStacks(int stacks)
{
    this->stacks = stacks;
}

void Sphere::setSlices(int slices)
{
    this->slices = slices;
}

void Sphere::render() const
{

    glPushMatrix();

    glTranslatef(movement.x, movement.y, movement.z);

    glTranslatef(origin.x, origin.y, origin.z);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-origin.x, -origin.y, -origin.z);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    if (texture)
    {
        texture->bind(0);
        glEnable(GL_TEXTURE_2D);
    }

    for (int i = 0; i < stacks; ++i)
    {
        float lat0 = 3.14f * (-0.5 + (float)(i) / stacks);
        float z0 = std::sin(lat0);
        float zr0 = std::cos(lat0);

        float lat1 = 3.14f * (-0.5 + (float)(i + 1) / stacks);
        float z1 = std::sin(lat1);
        float zr1 = std::cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j)
        {
            float lng = 2 * 3.14f * (float)j / slices;
            float x = std::cos(lng);
            float y = std::sin(lng);

            float u = (float)j / slices;
            float v0 = (float)i / stacks;
            float v1 = (float)(i + 1) / stacks;

            glTexCoord2f(u, v0);

            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(origin.x + radius * x * zr0, origin.y + radius * y * zr0, origin.z + radius * z0);

            glTexCoord2f(u, v1);

            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(origin.x + radius * x * zr1, origin.y + radius * y * zr1, origin.z + radius * z1);
        }
        glEnd();
    }

    if (texture)
    {
        glDisable(GL_TEXTURE_2D);
        Texture::unbind();
    }

    glPopMatrix();
}
