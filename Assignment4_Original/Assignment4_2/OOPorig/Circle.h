// Circle.h
// Assignment 4 example
// Contains the declaration (but not the definition!) of the Circle class,
// which inherits from Shape.

#ifndef CIRCLE_H
#define CIRCLE_H

// Because Circle will be inheriting Shape, we first need to be sure that
// Shape has been declared, so we include "Shape.h" here.
#include "Shape.h"

// Saying ": public Shape" is the C++ way of saying that the Circle class
// inherits from the Shape class.  Additionally, it says that code throughout
// the program will be aware of the inheritance relationship and can make
// use of it.
//
// Inheritance has basically the same effect as it does in Java; a Circle
// "is-a" Shape, meaning that it automatically has all the same fields and
// methods that a Shape does.  Just as you can in Java, you can add methods
// or override methods.
//
// Now that we have a concrete kind of shape, it makes sense to make the
// area() method non-abstract, since we can now write a sensible implementation
// of it.

class Circle : public Shape
{
public:
	// The constructor will accept enough parameters to initialize all of
	// Shape's fields (positionX and positionY) and all of the fields
	// specific to Circle (radius).
	Circle(double positionX, double positionY, double radius);

	// This overrides the (abstract) area() method in Shape.
	virtual double area();

	// I've added a couple of methods that are specific to Circles...
	virtual double getRadius();
	virtual void resize(double radius);

private:
	// ...and a new field.
	double radius;
};

#endif // CIRCLE_H
