#ifndef __BOUND_H__
#define __BOUND_H__
#include "Vectors/vec3.h"
#include "Renderable.h"

class Bound:public Renderable
{
  vec3 position;
  vec3 size;
  vec3 rotation;
  void render() const override;

  public:
  Bound();

  bool intersects(const Bound& bound) const;

  bool contains(const Bound& bound) const;

  friend class Parallelepiped;
  friend class Cube;
  friend class Cone;
  friend class Cylinder;
  friend class Sphere;
};

#endif // __BOUND_H__