#ifndef __CURVE_H__
#define __CURVE_H__

#include "VertexArray.h"

class Curve: public Renderable
{
    float low,high;

    Color color;

    float width;

    std::vector<float> ctrlPoints;

    int connections;

    void render() const override;


    public:
    Curve();

    Curve(vec3* controlPoints, int count, float u1 = 0.f, float u2 = 1.f);

    Curve(const VertexArray& vertices, float u1 = 0.f, float u2 = 1.f);

    void setColor(Color color);

    Color getColor() const;

    void setControlPoints(vec3* controlPoints, int count);

    void setControlPoints(const VertexArray& vertices);

    void addConstrolPoint(vec3 controlPoint);

    void setWidth(float width);

    float getWidth() const;

    void setLow(float low);

    float getLow() const;

    void setHigh(float high);

    float getHigh() const;

    void setConnections(int connections);
};

#endif // __CURVE_H__