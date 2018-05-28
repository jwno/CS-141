// Shape.cpp
// Assignment 4 example
// Contains the definitions of Shape's methods.

// We first include "Shape.h" so that the compiler, when it compiles
// "Shape.cpp," will be aware of the existence of the Shape class.  This
// is important, because this file defines Shape's methods, so the compiler
// will first need to be convinced that there is such a thing as a Shape.
#include "Shape.h"

Shape::Shape(double positionX, double positionY)
{
	// The use of the "this->" notation is exactly the same as the notation
	// "this." in a Java method.  Since the parameters to this constructor
	// have the same name as fields of the class, there needs to be a way
	// to differentiate them.  C++ considers "positionX" to be the parameter,
	// so "this->positionX" is the way you specify that you want the field
	// instead.  Note that this technique is not necessary in the absence
	// of a naming conflict.  (Some will say that you shouldn't ever allow
	// a naming conflict like this; my own view is that it's worthwhile to
	// purposefully introduce this conflict in the case when the constructor
	// will be using the parameters to initialize the coresponding fields.
	// Feel free to disagree with my view.)

	this->positionX = positionX;
	this->positionY = positionY;
}

double Shape::getPositionX()
{
	return positionX;
}

double Shape::getPositionY()
{
	return positionY;
}

void Shape::move(double positionX, double positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}
