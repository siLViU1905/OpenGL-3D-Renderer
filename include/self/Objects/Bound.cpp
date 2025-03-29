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

void Bound::render() const
{

    glBegin(GL_LINES);
    glColor3f(1.f,1.f,1.f);
    glLineWidth(2.f);

    glVertex3f(position.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z);
    glVertex3f(position.x, position.y - size.y, position.z);
    glVertex3f(position.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y, position.z);
    glVertex3f(position.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y, position.z);
    glVertex3f(position.x, position.y - size.y, position.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y, position.z);
    glVertex3f(position.x, position.y, position.z - size.z);
    glVertex3f(position.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x, position.y - size.y, position.z);
    glVertex3f(position.x + size.x, position.y, position.z);
    glVertex3f(position.x + size.x, position.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z - size.z);
    glVertex3f(position.x + size.x, position.y - size.y, position.z);

    glEnd();
}
