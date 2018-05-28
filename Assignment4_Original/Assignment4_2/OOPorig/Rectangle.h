// Rectangle.h
// Assignment 4 example
// Contains the declaration (but not the definition!) of the Rectangle class,
// which inherits from the Shape class.

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double positionX, double positionY, double width, double height);

	// I've overridden the area() method here, just like I did in Circle...
	virtual double area();

	// I've also added three new methods...
	virtual double getWidth();
	virtual double getHeight();
	virtual void resize(double width, double height);

private:
	// ...and two new fields.
	double width;
	double height;
};

#endif // RECTANGLE_H
