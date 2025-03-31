#include "Bound.h"
#include <cmath>
#include "../../GL/glad.h"
#include "../../GLFW/glfw3.h"

Bound::Bound()
{
}

bool Bound::intersects(const Bound &bound) const
{
    vec3 thisHalfSize = size * 0.5f;
    vec3 otherHalfSize = bound.size * 0.5f;

    vec3 thisCenter = position + thisHalfSize;
    vec3 otherCenter = bound.position + otherHalfSize;

    float dx = std::abs(thisCenter.x - otherCenter.x);
    float dy = std::abs(thisCenter.y - otherCenter.y);
    float dz = std::abs(thisCenter.z - otherCenter.z);

    float touchDistanceX = thisHalfSize.x + otherHalfSize.x;
    float touchDistanceY = thisHalfSize.y + otherHalfSize.y;
    float touchDistanceZ = thisHalfSize.z + otherHalfSize.z;

    bool intersectsX = dx <= touchDistanceX;
    bool intersectsY = dy <= touchDistanceY;
    bool intersectsZ = dz <= touchDistanceZ;

    return intersectsX && intersectsY && intersectsZ;
}

bool Bound::contains(const Bound &bound) const
{
    if (size.x < bound.size.x || size.y < bound.size.y || size.z < bound.size.z)
        return false;
    
    vec3 thisMin = position;
    vec3 thisMax = position + size;
    
    vec3 otherMin = bound.position;
    vec3 otherMax = bound.position + bound.size;
    
    if (otherMin.x >= thisMin.x && otherMin.y >= thisMin.y && otherMin.z >= thisMin.z &&
        otherMax.x <= thisMax.x && otherMax.y <= thisMax.y && otherMax.z <= thisMax.z) 
        return true;
    
    return false;
}

void Bound::render() const
{
    glPushMatrix();

    vec3 halfPos = position + size * 0.5f;

    glTranslatef(halfPos.x, halfPos.y, halfPos.z);

    glRotatef(rotation.x, 1.f, 0.f, 0.f);
    glRotatef(rotation.y, 0.f, 1.f, 0.f);
    glRotatef(rotation.z, 0.f, 0.f, 1.f);

    glTranslatef(-halfPos.x, -halfPos.y, -halfPos.z);

    glLineWidth(2.f);
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_LINES);

    glVertex3f(position.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y, position.z);

    glVertex3f(position.x + size.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z);

    glVertex3f(position.x + size.x, position.y - size.y, position.z);
    glVertex3f(position.x, position.y - size.y, position.z);

    glVertex3f(position.x, position.y - size.y, position.z);
    glVertex3f(position.x, position.y, position.z);

    glVertex3f(position.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y, position.z - size.z);

    glVertex3f(position.x + size.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);

    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y - size.y, position.z - size.z);

    glVertex3f(position.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y, position.z - size.z);

    glVertex3f(position.x, position.y, position.z);
    glVertex3f(position.x, position.y, position.z - size.z);

    glVertex3f(position.x + size.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y, position.z - size.z);

    glVertex3f(position.x + size.x, position.y - size.y, position.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);

    glVertex3f(position.x, position.y - size.y, position.z);
    glVertex3f(position.x, position.y - size.y, position.z - size.z);

    glEnd();

    glPopMatrix();
}
