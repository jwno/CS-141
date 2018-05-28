// RightTriangle.cpp
// Assignment 4 example

#include <cmath>
#include <iostream>
#include "RightTriangle.h"

void** vmtRightTriangle;

RightTriangle* RightTriangle_new(double positionX, double positionY, double width, double height)
{
	RightTriangle* c = new RightTriangle;
	RightTriangle_RightTriangle(c, positionX, positionY, width, height);
	c->vmt = vmtRightTriangle;
	return c;
}

void RightTriangle_RightTriangle(RightTriangle* _this, double positionX, double positionY, double width, double height)
{
	_this->positionX = positionX;
	_this->positionY = positionY;
	_this->width = width;
	_this->height = height;
}

double RightTriangle_area(Shape* _this)
{
	return (((RightTriangle*)_this)->width * ((RightTriangle*)_this)->height) / 2;
}

double RightTriangle_getWidth(RightTriangle* _this)
{
	return _this->width;
}

double RightTriangle_getHeight(RightTriangle* _this)
{
	return _this->height;
}


double RightTriangle_getHypotenuseLength(RightTriangle* _this)
{
	return sqrt(_this->width * _this->width + _this->height * _this->height);
}

void RightTriangle_resize(RightTriangle* _this, double width, double height)
{
	_this->width = width;
	_this->height = height;
}

void RightTriangle_emulated_destructor(RightTriangle *_this)
{
	std::cout << "RightTriangle Destructor Invoked" << std::endl;
	Shape_emulated_destructor((Shape *)_this);
}

void RightTriangle_createVMT()
{
	vmtRightTriangle = new void*[9];
	vmtRightTriangle[0] = (void*)Shape_getPositionX;
	vmtRightTriangle[1] = (void*)Shape_getPositionY;
	vmtRightTriangle[2] = (void*)Shape_move;
	vmtRightTriangle[3] = (void*)RightTriangle_area;
	vmtRightTriangle[4] = (void*)RightTriangle_resize;
	vmtRightTriangle[5] = (void*)RightTriangle_getWidth;
	vmtRightTriangle[6] = (void*)RightTriangle_getHeight;
	vmtRightTriangle[7] = (void*)RightTriangle_getHypotenuseLength;
	vmtRightTriangle[8] = (void*)RightTriangle_emulated_destructor;
}