// Circle.cpp
// Assignment 4 example
// Contains the definitions of the methods of the Circle class.

#include "Circle.h"

// Just like in Java, the first thing a constructor of a derived class
// does is call the constructor of its base class.  This syntax:
//
//     : Shape(positionX, positionY)
//
// ...is how you write that in C++.  This says that the first thing
// that the Circle constructor should do is call the Shape constructor,
// passing positionX and positionY as parameters.

Circle::Circle(double positionX, double positionY, double radius)
	: Shape(positionX, positionY)
{
	this->radius = radius;
}

double Circle::area()
{
	// This declares a named constant.  Since it's only being used in this
	// function, I've declared it local to the function.  Alternatively, you
	// could declare it globally, or as a field of the Circle class.
	const double PI = 3.1415927;
	return PI * radius * radius;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::resize(double radius)
{
	this->radius = radius;
}
