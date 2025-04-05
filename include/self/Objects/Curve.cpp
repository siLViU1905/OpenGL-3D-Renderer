#include "Curve.h"
#include "../../GL/glad.h"
#include <iostream>

Curve::Curve() : low(0.f), high(1.f), connections(30)
{
}

Curve::Curve(vec3 *controlPoints, int count, float u1, float u2) : low(u1), high(u2), connections(30), ctrlPoints(count * 3)
{
    int j = 0;
    for (int i = 0; i < count; ++i)
    {
        ctrlPoints[j] = controlPoints[i].x;
        ctrlPoints[j + 1] = controlPoints[i].y;
        ctrlPoints[j + 2] = controlPoints[i].z;
        j += 3;
    }
}

Curve::Curve(const VertexArray &vertices, float u1, float u2) : low(u1), high(u2), connections(30), ctrlPoints(vertices.vertices.size() * 3)
{
    int j = 0;
    for (int i = 0; i < vertices.vertices.size(); ++i)
    {
        ctrlPoints[j] = vertices.vertices[i].x;
        ctrlPoints[j + 1] = vertices.vertices[i].y;
        ctrlPoints[j + 2] = vertices.vertices[i].z;
        j += 3;
    }
}

void Curve::setColor(Color color)
{
    this->color = color;
}

Color Curve::getColor() const
{
    return color;
}

void Curve::setControlPoints(vec3 *controlPoints, int count)
{
    ctrlPoints.assign(count * 3, 0.f);
    int j = 0;
    for (int i = 0; i < count; ++i)
    {
        ctrlPoints[j] = controlPoints[i].x;
        ctrlPoints[j + 1] = controlPoints[i].y;
        ctrlPoints[j + 2] = controlPoints[i].z;
        j += 3;
    }
}

void Curve::setControlPoints(const VertexArray &vertices)
{
    ctrlPoints.assign(vertices.vertices.size() * 3, 0.f);
    int j = 0;
    for (int i = 0; i < vertices.vertices.size(); ++i)
    {
        ctrlPoints[j] = vertices.vertices[i].x;
        ctrlPoints[j + 1] = vertices.vertices[i].y;
        ctrlPoints[j + 2] = vertices.vertices[i].z;
        j += 3;
    }
}

void Curve::addConstrolPoint(vec3 controlPoint)
{
    ctrlPoints.push_back(controlPoint.x);
    ctrlPoints.push_back(controlPoint.y);
    ctrlPoints.push_back(controlPoint.z);
}

void Curve::setWidth(float width)
{
    this->width = width;
}

float Curve::getWidth() const
{
    return width;
}

void Curve::setLow(float low)
{
    this->low = low;
}

float Curve::getLow() const
{
    return low;
}

void Curve::setHigh(float high)
{
    this->high = high;
}

float Curve::getHigh() const
{
    return high;
}

void Curve::setConnections(int connections)
{
    this->connections = connections;
}


void Curve::render() const
{
    glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, low, high, 3, ctrlPoints.size() / 3, ctrlPoints.data());
    glEnable(GL_MAP1_VERTEX_3);

    glColor4f(color.rgb.x, color.rgb.y, color.rgb.z, color.alpha);
    glLineWidth(width);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= connections; ++i)
        glEvalCoord1f((float)i / (float)connections);
    glEnd();

    glDisable(GL_MAP1_VERTEX_3);

    glPopMatrix();
}
