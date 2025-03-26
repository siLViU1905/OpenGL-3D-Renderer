#pragma once
#include "Color.h"
#include "Angle.h"
#include "../Shaders/Texture.h"

class Renderable
{
	protected:
	   virtual void render() const = 0;
	  
public:
	virtual ~Renderable();
	friend class Window;
};

class Object:public Renderable
{
	protected:
	vec3 origin;
	vec3 movement;
	Color color;
	vec3 rotation;
	Texture* texture;
	void render() const override;
public:
	Object();
  
	
	void move(vec3 offset);
	void move(float offset);
	
	void rotate(Angle phi);
	void rotate(Angle xPhi,Angle yPhi,Angle zPhi);
	vec3 getPosition() const;
	vec3 getOrigin() const;
	vec3 getRotation() const;
	Color getColor() const;

	void setOrigin(vec3 pos);
	void setColor(Color color);

	void setTexture(Texture* texture);

	friend class Window;
};

class Parallelepiped:public Object
{
	protected:
	vec3 size;
	void render() const override;
   public:
   Parallelepiped();
  

   using Object::getOrigin;
   using Object::getPosition;
   using Object::getColor;
   using Object::getRotation;
   using Object::rotate;
   using Object::move;
   using Object::setOrigin;
   using Object::setColor;
   using Object::setTexture;

   void setSize(vec3 size);
   vec3 getSize() const;
};

class Cube:public Object
{
	protected:
	void render() const override;
	float size;
public:
	Cube();


	using Object::getOrigin;
	using Object::getPosition;
	using Object::getColor;
	using Object::getRotation;
	using Object::rotate;
	using Object::move;
	using Object::setOrigin;
	using Object::setColor;
	using Object::setTexture;

	void setSize(float size);
   float getSize() const;
};

class Cone :public Object
{
	protected:
	float radius;
	float height;
	void render() const override;
public:
	Cone();
	

	using Object::getOrigin;
	using Object::getPosition;
	using Object::getColor;
	using Object::getRotation;
	using Object::rotate;
	using Object::move;
	using Object::setOrigin;
	using Object::setColor;
	using Object::setTexture;

	void setRadius(float radius);
	void setHeight(float height);

	float getRadius() const;
	float getHeight() const;
};

class Cylinder: public Object
{
	protected:
 void render() const override;
	float baseRadius;
 float topRadius;
 float height;
public:
 Cylinder();


 using Object::getOrigin;
 using Object::getPosition;
 using Object::getColor;
 using Object::getRotation;
 using Object::rotate;
 using Object::move;
 using Object::setOrigin;
 using Object::setColor;
 using Object::setTexture;

 void setBaseRadius(float radius);
 void setTopRadius(float radius);
 void setHeight(float height);

 float getBaseRadius() const;
 float getTopRadius() const;
 float getHeight() const;
};

class Sphere:public Object
{
   protected:
   void render() const override;
   float radius;
   int stacks;
   int slices;
   public:
   Sphere();

   using Object::getOrigin;
	using Object::getPosition;
	using Object::getColor;
	using Object::getRotation;
	using Object::rotate;
	using Object::move;
	using Object::setOrigin;
	using Object::setColor;
	using Object::setTexture;

	   void setRadius(float radius);
       float getRadius() const;

	   void setStacks(int stacks);
	   void setSlices(int slices);
};
