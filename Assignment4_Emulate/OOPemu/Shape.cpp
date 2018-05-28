// Shape.cpp
// Assignment 4 example
// Contains the definitions needed to emulate the Shape "class".

#include "Shape.h"
#include <iostream>

// This global variable is a pointer to the VMT for the Shape "class".
// Since there will only be one such table for all instances of a
// particular class, it makes sense to use a global variable for it.
void** vmtShape;

// Here are the methods of the Shape class.  Notice that they're
// basically the same as the methods defined in the original C++
// example (OOPorig), except that they have an additional parameter
// called _this, which represents the object that they're being
// called on.


// This is the same constructor.  Note that it's not the constructor's
// job to allocate memory for an object; the constructor's job is to
// take an object that's already been allocated and initialize it,
// which is why you don't see the use of the "new" operator or a call
// to malloc() here.
//
// Remember that, since Shape is abstract, there's no way to create
// Shape objects.  But you still need a Shape constructor, since the
// constructor's of Shape's derived classes (e.g. Circle) will need
// to call it.
void Shape_Shape(Shape* _this, double positionX, double positionY)
{
	_this->positionX = positionX;
	_this->positionY = positionY;
}

double Shape_getPositionX(Shape* _this)
{
	return _this->positionX;
}

double Shape_getPositionY(Shape* _this)
{
	return _this->positionY;
}

void Shape_move(Shape* _this, double positionX, double positionY)
{
	_this->positionX = positionX;
	_this->positionY = positionY;
}

void Shape_emulated_destructor(Shape* _this)
{
	std::cout << "Shape Destructor Invoked" << std::endl;
}

// This function creates and initializes the VMT for the Shape class.
// It needs to be called before the program runs.  (Note that the main()
// method in main.cpp first calls a function called createVMTs(), which
// does just that.)

void Shape_createVMT()
{
	vmtShape = new void*[4];
	vmtShape[0] = (void*) Shape_getPositionX;
	vmtShape[1] = (void*) Shape_getPositionY;
	vmtShape[2] = (void*) Shape_move;

	// area() is abstract, so its entry in the VMT should be 0 (NULL).
	vmtShape[3] = (void*) 0;
}
