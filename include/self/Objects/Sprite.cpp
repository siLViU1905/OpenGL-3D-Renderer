#include "Sprite.h"
#include "../../GL/glad.h"
void Sprite::setSize(vec3 size)
{
    this->size = size;
}

vec3 Sprite::getSize() const
{
    return size;
}

void Sprite::setTransparency(bool transparency)
{
    this->transparency = transparency;
}

void Sprite::render() const
{
    if(transparency)
    {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }


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
    glColor4f(1.f, 1.f, 1.f,1.f);

    glTexCoord2f(0.f, 0.f);
    glVertex3f(origin.x, origin.y, origin.z);

    glTexCoord2f(1.f, 0.f);
    glVertex3f(origin.x + size.x, origin.y, origin.z);

    glTexCoord2f(1.f, 1.f);
    glVertex3f(origin.x + size.x, origin.y + size.y, origin.z);

    glTexCoord2f(0.f, 1.f);
    glVertex3f(origin.x, origin.y + size.y, origin.z);

    glEnd();

    if (texture)
    {
        glDisable(GL_TEXTURE_2D);
        Texture::unbind();
    }

    glPopMatrix();

    if(transparency)
        glDisable(GL_BLEND);
}

Sprite::Sprite()
{
    transparency = false;
}
