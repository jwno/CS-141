// Square.h
// Assignment 4 example

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

struct Square
{
	// virtual method table pointer
	void** vmt;

	// Shape part
	double positionX;
	double positionY;
};


void Square_createVMT();

// Square_new simulate the behavior for the new operator
Square* Square_new(double positionX, double positionY, double sideLength);
// Square_Square simulate the bahavior for Square constructor
double Square_getSideLength(Square* _this);
void Square_resize(Square* _this, double width, double height);
void Square_resize(Square* _this, double sideLength);
void Square_emulated_destructor(Square* _this);

typedef double(*fp_Square_getSideLength)(Square*);
typedef void(*fp_Square_resize1)(Square*, double, double);
typedef void(*fp_Square_resize2)(Square*, double);
typedef void(*fp_Square_destructor)(Square*);

#endif // SQUARE_H
