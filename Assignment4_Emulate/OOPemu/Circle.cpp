// Circle.cpp
// Assignment 4 example
// I've included the definition of the Circle_new function, since you haven't
// seen any examples of it.  Other than that, you'll need to fill in the bodies
// of the remaining functions.

#include "Circle.h"
#include <iostream>

void** vmtCircle;

// You shouldn't need to modify this function at all.  It creates a new
// Circle "object," calls the Circle constructor on it, then initializes
// the vmt field of the newly-created Circle.  You may be wondering why
// the vmt field is being initialized here and not in the Circle
// constructor.  The reason is because it should only be initialized
// once, but multiple constructors may be called (e.g. Square's constructor
// will call Rectangle's, which will call Shape's) during the initialization
// of an object.
Circle* Circle_new(double positionX, double positionY, double radius)
{
	Circle* c = new Circle;
	Circle_Circle(c, positionX, positionY, radius);
	c->vmt = vmtCircle;
	return c;
}

void Circle_Circle(Circle* _this, double positionX, double positionY, double radius)
{
	_this->positionX = positionX;
	_this->positionY = positionY;
	_this->radius = radius;
}

double Circle_area(Shape* _this)
{
	const double PI = 3.1415927;
	return PI * ((Circle*)_this)->radius * ((Circle*)_this)->radius;
}

double Circle_getRadius(Circle* _this)
{
	return _this->radius;
}

void Circle_resize(Circle* _this, double radius)
{
	_this->radius = radius;
}

void Circle_emulated_destructor(Circle* _this)
{
	std::cout << "Circle Destructor Invoked" << std::endl;
	Shape_emulated_destructor((Shape *)_this);
}

void Circle_createVMT()
{
	vmtCircle = new void*[7];
	vmtCircle[0] = (void*) Shape_getPositionX;
	vmtCircle[1] = (void*) Shape_getPositionY;
	vmtCircle[2] = (void*) Shape_move;
	vmtCircle[3] = (void*) Circle_area;
	vmtCircle[4] = (void*) Circle_resize;
	vmtCircle[5] = (void*) Circle_getRadius;
	vmtCircle[6] = (void*) Circle_emulated_destructor;
}
