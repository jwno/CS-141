// Rectangle.cpp
// Assignment 4 example
// Contains definitions of Rectangle's methods.

#include "Rectangle.h"

Rectangle::Rectangle(double positionX, double positionY, double width, double height)
	: Shape(positionX, positionY)
{
	this->width = width;
	this->height = height;
}

double Rectangle::area()
{
	return width * height;
}

double Rectangle::getWidth()
{
	return width;
}

double Rectangle::getHeight()
{
	return height;
}

void Rectangle::resize(double width, double height)
{
	this->width = width;
	this->height = height;
}
