// Square.cpp
// Assignment 4 example
// Contains the definitions of the methods in Square.

#include "Square.h"

Square::Square(double positionX, double positionY, double sideLength)
	: Rectangle(positionX, positionY, sideLength, sideLength)
{

}

double Square::getSideLength()
{
	// Since the side length will always be equal to both the width and
	// height of the square, we can call either getWidth() or getHeight()
	// to get the answer we need.  Notice that I didn't use the width field
	// here; that's because I marked the width and height fields private in
	// the Rectangle class, meaning that even Square can't get to them
	// directly.
	return getWidth();
}

void Square::resize(double width, double height)
{
	if (width == height)
	{
		// This is analogous to the following line of Java:
		//
		//     super.resize(width, height);
		//
		// It calls Rectangle's resize() method.

		Rectangle::resize(width, height);
	}

	// It would be best to throw an exception in this case, but that's a
	// topic for another day.
}

void Square::resize(double sideLength)
{
	resize(sideLength, sideLength);
}
