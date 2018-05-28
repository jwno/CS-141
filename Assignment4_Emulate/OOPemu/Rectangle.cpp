// Rectangle.cpp
// Assignment 4 example

#include "Rectangle.h"
#include <iostream>

void** vmtRectangle;

Rectangle* Rectangle_new(double positionX, double positionY, double width, double height)
{
	Rectangle* c = new Rectangle;
	Rectangle_Rectangle(c, positionX, positionY, width, height);
	c->vmt = vmtRectangle;
	return c;
}

void Rectangle_Rectangle(Rectangle* _this, double positionX, double positionY, double width, double height)
{
	_this->positionX = positionX;
	_this->positionY = positionY;
	_this->width = width;
	_this->height = height;
}

double Rectangle_area(Shape* _this)
{
	return ((Rectangle*)_this)->width * ((Rectangle*)_this)->height;
}

double Rectangle_getWidth(Rectangle* _this)
{
	return _this->width;
}

double Rectangle_getHeight(Rectangle* _this)
{
	return _this->height;
}

void Rectangle_resize(Rectangle* _this, double width, double height)
{
	_this->width = width;
	_this->height = height;
}

void Rectangle_emulated_destructor(Rectangle *_this)
{
	std::cout << "Rectangle Destructor Invoked" << std::endl;
	Shape_emulated_destructor((Shape *)_this);
}

void Rectangle_createVMT()
{
	vmtRectangle = new void*[8];
	vmtRectangle[0] = (void*)Shape_getPositionX;
	vmtRectangle[1] = (void*)Shape_getPositionY;
	vmtRectangle[2] = (void*)Shape_move;
	vmtRectangle[3] = (void*)Rectangle_area;
	vmtRectangle[4] = (void*)Rectangle_resize;
	vmtRectangle[5] = (void*)Rectangle_getWidth;
	vmtRectangle[6] = (void*)Rectangle_getHeight;
	vmtRectangle[7] = (void*)Rectangle_emulated_destructor;
}