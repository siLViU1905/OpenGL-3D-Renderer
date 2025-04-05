#ifndef __TRANSFORM3D_H__
#define __TRANSFORM3D_H__
#include "../Matrices/mat3.h"
#include "../Angle.h"

class Transform3D
{
   public:
   static mat3 rotatex(Angle angle);

   static mat3 rotatey(Angle angle);

   static mat3 rotatez(Angle angle);

   static vec3& translate(vec3& point, vec3 offset);
};

#endif // __TRANSFORM3D_H__