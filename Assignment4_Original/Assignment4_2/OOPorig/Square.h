// Square.h
// Assignment 4 example
// Contains the declaration (but not the definition) of the Square class.
// Square inherits from Rectangle; what sets Squares apart from Rectangles
// is that their width and height must be equal at all times.  (This doesn't
// turn out to be a very good use of inheritance; it's generally a bad idea
// for a subclass to be more restricted than its superclass.  I included this
// class primarily because I wanted to have a simple example of an inheritance
// hierarchy with three levels.)

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
	Square(double positionX, double positionY, double sideLength);

	// Firstly, I've added a getSideLength() method, though the
	// getWidth() and getHeight() methods from Rectangle will also
	// return the same value.  Still, there's sometimes usefulness in
	// adding new, more suitable nomenclature to derived classes.
	virtual double getSideLength();

	// To ensure that the version of resize() in Rectangle cannot be
	// called directly (and thus allow the violation of the property
	// that the width and height of a Rectangle must be equal), I've
	// overridden the resize() method in Rectangle.
	virtual void resize(double width, double height);

	// I've additionally overloaded the resize method with a new version
	// that's specific to Square.
	virtual void resize(double sideLength);
};

#endif // SQUARE_H
