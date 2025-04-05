#include "../Matrices/mat2.h"

#ifndef __TRANSFORM2D_H__
#define __TRANSFORM2D_H__

class Transform2d
{
   public:
   static mat2 rotate(Angle angle);

   static mat2 scale(float scale);

   static vec2& translate(vec2& point, vec2 offset);

};

#endif // __TRANSFORM2D_H__