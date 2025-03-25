#ifndef __COLOR_H__
#define __COLOR_H__
#include "vec3.h"

class Color
{
public:
   vec3 rgb;
   float alpha;
   Color();

   Color(float r,float g,float b,float alpha = 1.f);

   Color(vec3 rgb ,float alpha = 1.f);

   static const Color White;
   static const Color Black;
   static const Color Red;
   static const Color Green;
   static const Color Blue;
};

#endif // __COLOR_H__