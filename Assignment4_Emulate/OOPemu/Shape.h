// Shape.h
// Assignment 4 example
// Contains the declarations needed to emulate the Shape class.  Rather
// that declaring Shape as a class, Shape is instead a struct (with no
// methods) that stores a VMT and Shape's two fields (positionX and
// positionY).
//
// You should not need to make any modifications to this file.

#ifndef SHAPE_H
#define SHAPE_H

// The first member of the Shape struct is vmt. You may be wondering
// what a "void**" is. In this case, it's intended to be a pointer to
// an array of "void*"s. A "void*" is an untyped pointer; it's a memory
// address without any indication of what type of information it points
// to. This is the only non-object-oriented way for us to store pointers
// to functions, since all of the pointers are of different types.

struct Shape
{
	void** vmt;

	double positionX;
	double positionY;
};

// These are declarations of the functions written in Shape.cpp.  I'm using
// a particular naming convention here:
//
// Since all of these are related to the Shape "class", they all begin with
// "Shape_".  Beyond that...
//
//   * Shape_createVMT() is a function that creates and initializes the VMT
//     for Shape objects.
//   * If Shape were not an abstract class, I'd include a Shape_new() function
//     that allocates and initializes a Shape.  (I've included a Circle_new()
//     function in Circle.h and Circle.cpp for this purpose.)
//   * Shape_Shape() is analogous to a Shape constructor.
//   * All other Shape_XXX() functions are the methods of the Shape "class".
//
// The reason why I had to use the parameter name "_this" throughout is
// because "this" is a reserved word in C++.

void Shape_createVMT();
void Shape_Shape(Shape* _this, double positionX, double positionY);
double Shape_getPositionX(Shape* _this);
double Shape_getPositionY(Shape* _this);
void Shape_move(Shape* _this, double positionX, double positionY);
void Shape_emulated_destructor(Shape* _this);


// The typedef keyword in C++ allows you to give a new name to a type.  A
// simple use of the keyword might be something like this:
//
//    typedef int myIntegerType;
//
// which establishes that a myIntegerType is the same as an int.  We don't
// need a simple typedef like this, but we will be storing function pointers
// in the VMT for each "class" and, thus, will need types for each of these
// pointers.
//
// As an example, the first typedef below means the following: The type
// "fp_Shape_getPositionX" is a pointer to a function that takes a Shape
// pointer as a parameter and returns a double.  (The syntax is ugly, but
// that's what it means.)

typedef double (*fp_Shape_getPositionX)(Shape*);
typedef double (*fp_Shape_getPositionY)(Shape*);
typedef void (*fp_Shape_move)(Shape*, double, double);
typedef double (*fp_Shape_area)(Shape*);

#endif // SHAPE_H
