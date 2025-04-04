#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__

#include "Renderable.h"
#include "Color.h"
#include <vector>

enum class Primitives
{
  POINT,
  LINE,
  LINES,
  LINE_STRIP,
  LINE_LOOP,
  TRIANGLE,
  TRIANGLE_FAN,
  TRIANGLE_STRIP,
  QUAD,
  QUAD_STRIP
};

class VertexArray : public Renderable
{
    std::vector<vec3> vertices;

    unsigned int primitiveType;

    Color color;

    float width;
    void render() const override;

public:
    VertexArray();

    VertexArray(vec3 *vertices, int count, Primitives primitive);

    void setPointCount(int count);

    void setPoint(int index, vec3 pos);

    vec3& getPoint(int index);

    const vec3& getPoint(int index) const;

    void setWidth(float lineWidth);

    float getWidth() const;

    void setPrimitiveType(Primitives primitive);

    Primitives getPrimitiveType() const;
    
    void setColor(Color color);

    Color getColor() const;
};

#endif // __VERTEXARRAY_H__