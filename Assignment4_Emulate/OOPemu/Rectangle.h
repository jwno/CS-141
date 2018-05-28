// Rectangle.h
// Assignment 4 example

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

struct Rectangle
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


void Rectangle_createVMT();

// Rectangle_new simulate the behavior for the new operator
Rectangle* Rectangle_new(double positionX, double positionY, double width, double height);
// Rectangle_Rectangle simulate the bahavior for Rectangle constructor
void Rectangle_Rectangle(Rectangle* _this, double positionX, double positionY, double width, double height);
double Rectangle_area(Shape* _this);
double Rectangle_getWidth(Rectangle* _this);
double Rectangle_getHeight(Rectangle* _this);
void Rectangle_resize(Rectangle* _this, double width, double height);
void Rectangle_emulated_destructor(Rectangle *_this);

typedef double(*fp_Rectangle_getWidth)(Rectangle*);
typedef double(*fp_Rectangle_getHeight)(Rectangle*);
typedef void(*fp_Rectangle_resize)(Rectangle*, double, double);
typedef void(*fp_Rectangle_destructor)(Rectangle*);

#endif // RECTANGLE_H
