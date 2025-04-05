#include "VertexArray.h"
#include "../../GL/glad.h"

VertexArray::VertexArray():width(1.f),pSize(1.f)
{
}

VertexArray::VertexArray(vec3 *vertices, int count, Primitives primitive) : vertices(count),primitiveType(0),width(1.f), pSize(1.f)
{
    for(int i = 0; i<count;++i)
     this->vertices[i] = vertices[i];

     switch(primitive)
     {
        case Primitives::POINT:
        primitiveType = GL_POINT;
        break;

        case Primitives::POINTS:
        primitiveType = GL_POINTS;
        break;

        case Primitives::LINE:
        primitiveType = GL_LINE;
        break;

        case Primitives::LINES:
        primitiveType = GL_LINES;
        break;

        case Primitives::LINE_STRIP:
        primitiveType = GL_LINE_STRIP;
        break;

        case Primitives::LINE_LOOP:
        primitiveType = GL_LINE_LOOP;
        break;  

        case Primitives::TRIANGLE:
        primitiveType = GL_TRIANGLES;       
        break;

        case Primitives::TRIANGLE_FAN:
        primitiveType = GL_TRIANGLE_FAN;
        break;  

        case Primitives::TRIANGLE_STRIP:
        primitiveType = GL_TRIANGLE_STRIP;
        break;

        case Primitives::QUAD:
        primitiveType = GL_QUADS;
        break;

        case Primitives::QUAD_STRIP:
        primitiveType = GL_QUAD_STRIP;
        break;
     }
}

void VertexArray::setPointCount(int count)
{
    vertices.assign(count,vec3());
}

void VertexArray::setPoint(int index, vec3 pos)
{
    vertices[index] = pos;
}

vec3& VertexArray::getPoint(int index)
{
    return vertices[index];
}

const vec3& VertexArray::getPoint(int index) const
{
    return vertices[index];
}

void VertexArray::setWidth(float lineWidth)
{
    width = lineWidth;
}

float VertexArray::getWidth() const
{
    return width;
}

void VertexArray::setPointSize(float size)
{
    pSize = size;
}

float VertexArray::getPointSize() const
{
    return pSize;
}

void VertexArray::setPrimitiveType(Primitives primitive)
{
    switch(primitive)
    {
       case Primitives::POINT:
       primitiveType = GL_POINT;
       break;

       case Primitives::LINE:
       primitiveType = GL_LINE;
       break;

       case Primitives::LINES:
       primitiveType = GL_LINES;
       break;

       case Primitives::LINE_STRIP:
       primitiveType = GL_LINE_STRIP;
       break;

       case Primitives::LINE_LOOP:
       primitiveType = GL_LINE_LOOP;
       break;  

       case Primitives::TRIANGLE:
       primitiveType = GL_TRIANGLES;       
       break;

       case Primitives::TRIANGLE_FAN:
       primitiveType = GL_TRIANGLE_FAN;
       break;  

       case Primitives::TRIANGLE_STRIP:
       primitiveType = GL_TRIANGLE_STRIP;
       break;

       case Primitives::QUAD:
       primitiveType = GL_QUADS;
       break;

       case Primitives::QUAD_STRIP:
       primitiveType = GL_QUAD_STRIP;
       break;
    }
}

Primitives VertexArray::getPrimitiveType() const
{
    switch(primitiveType)
    {
        case GL_POINT:
        return Primitives::POINT;

        case GL_LINE:
        return Primitives::LINE;

        case GL_LINES:
        return Primitives::LINES;

        case GL_LINE_STRIP:
        return Primitives::LINE_STRIP;

        case GL_LINE_LOOP:
        return Primitives::LINE_LOOP;  

        case GL_TRIANGLES:
        return Primitives::TRIANGLE;       

        case GL_TRIANGLE_FAN:
        return Primitives::TRIANGLE_FAN;  

        case GL_TRIANGLE_STRIP:
        return Primitives::TRIANGLE_STRIP;

        case GL_QUADS:
        return Primitives::QUAD;

        case GL_QUAD_STRIP:
        return Primitives::QUAD_STRIP;
    }
}

void VertexArray::setColor(Color color)
{
    this->color = color;
}

Color VertexArray::getColor() const
{
    return color;
}


void VertexArray::render() const 
{
    glLineWidth(width);
    glPointSize(pSize);
    glBegin(primitiveType);
    
   glColor4f(color.rgb.x,color.rgb.y,color.rgb.z,color.alpha);
    for(const vec3& vertex: vertices)
    glVertex3f(vertex.x,vertex.y,vertex.z);

    glEnd();
}
