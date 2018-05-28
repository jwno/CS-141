// Square.cpp
// Assignment 4 example

#include "Square.h"
#include <iostream>

void** vmtSquare;

Square* Square_new(double positionX, double positionY, double sideLength)
{
	Square* c = new Square;
	Rectangle_Rectangle((Rectangle*)c, positionX, positionY, sideLength, sideLength);
	c->vmt = vmtSquare;
	return c;
}

double Square_getSideLength(Square* _this)
{
	return Rectangle_getWidth((Rectangle*)_this);
}

void Square_resize(Square* _this, double width, double height)
{
	if (width == height) {
		Rectangle_resize((Rectangle*)_this, width, height);
	}
}

void Square_resize(Square* _this, double width)
{
	Square_resize(_this, width, width);
}

void Square_emulated_destructor(Square *_this)
{
	std::cout << "Square Destructor Invoked" << std::endl;
	Rectangle_emulated_destructor((Rectangle *)_this);
}

void Square_createVMT()
{
	vmtSquare = new void*[8];
	vmtSquare[0] = (void*)Shape_getPositionX;
	vmtSquare[1] = (void*)Shape_getPositionY;
	vmtSquare[2] = (void*)Shape_move;
	vmtSquare[3] = (void*)Rectangle_area;
	vmtSquare[4] = (void*)static_cast<void(*) (Square*, double, double)>(&Square_resize);
	vmtSquare[5] = (void*)static_cast<void(*) (Square*, double)>(&Square_resize);
	vmtSquare[6] = (void*)Square_getSideLength;
	vmtSquare[7] = (void*)Square_emulated_destructor;
}