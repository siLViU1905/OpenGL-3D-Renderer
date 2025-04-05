#ifndef __SPRITE_H__
#define __SPRITE_H__
#include "Objects.h"

class Sprite:public Object
{
    protected:
    void render() const override;

    bool transparency;

    vec3 size;
   public:
   Sprite();

	using Object::getOrigin;
	using Object::getPosition;
	using Object::getRotation;
	using Object::move;
	using Object::rotate;
	using Object::setOrigin;
	using Object::setTexture;

    //z is not used
    void setSize(vec3 size);

    vec3 getSize() const;

    void setTransparency(bool transparency);
};

#endif // __SPRITE_H__