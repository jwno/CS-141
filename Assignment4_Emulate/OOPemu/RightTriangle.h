// RightTriangle.h
// Assignment 4 example

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"

struct RightTriangle
{
	// virtual method table pointer
	void** vmt;

	// Shape part
	double positionX;
	double positionY;

	// Rectangle part
	double width;
	double height;
};


void RightTriangle_createVMT();

// Rectangle_new simulate the behavior for the new operator
RightTriangle* RightTriangle_new(double positionX, double positionY, double width, double height);
// Rectangle_Rectangle simulate the bahavior for Rectangle constructor
void RightTriangle_RightTriangle(RightTriangle* _this, double positionX, double positionY, double width, double height);
double RightTriangle_area(Shape* _this);
double RightTriangle_getWidth(RightTriangle* _this);
double RightTriangle_getHeight(RightTriangle* _this);
double RightTriangle_getHypotenuseLength(RightTriangle* _this);
void RightTriangle_resize(RightTriangle* _this, double width, double height);
void RightTriangle_emulated_destructor(RightTriangle *_this);

typedef double(*fp_RightTriangle_getWidth)(RightTriangle*);
typedef double(*fp_RightTriangle_getHeight)(RightTriangle*);
typedef void(*fp_RightTriangle_resize)(RightTriangle*, double, double);
typedef double(*fp_RightTriangle_getHypotenuseLength)(RightTriangle*);
typedef void(*fp_RightTriangle_destructor)(RightTriangle*);

#endif // RIGHTTRIANGLE_H
