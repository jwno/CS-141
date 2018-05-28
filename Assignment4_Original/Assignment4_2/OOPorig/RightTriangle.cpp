// RightTriangle.cpp
// Assignment 4 example
// Contains the definition of the methods in RightTriangle.

// This includes the declarations of the functions in the Standard C math
// library, which we'll need because we'll be calling sqrt() below.
#include <cmath>

#include "RightTriangle.h"

RightTriangle::RightTriangle(double positionX, double positionY, double width, double height)
	: Shape(positionX, positionY)
{
	this->width = width;
	this->height = height;
}

double RightTriangle::area()
{
	return width * height / 2;
}

double RightTriangle::getWidth()
{
	return width;
}

double RightTriangle::getHeight()
{
	return height;
}

double RightTriangle::getHypotenuseLength()
{
	return sqrt(width * width + height * height);
}

void RightTriangle::resize(double width, double height)
{
	this->width = width;
	this->height = height;
}
