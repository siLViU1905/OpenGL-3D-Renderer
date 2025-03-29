#ifndef __RENDERABLE_H__
#define __RENDERABLE_H__

class Renderable
{
protected:
	virtual void render() const = 0;

public:
	virtual ~Renderable();
	friend class Window;
};

#endif // __RENDERABLE_H__