// RightTriangle.h
// Assignment 4 example
// Contains the declaration (but not the definition!) of the RightTriangle
// class, which inherits from Shape.

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"

// RightTriangle overrides area(), then adds four new methods: getWidth(),
// getHeight(), getHypotenuseLength(), and resize().

class RightTriangle : public Shape
{
public:
	RightTriangle(double positionX, double positionY, double width, double height);
	virtual double area();
	virtual double getWidth();
	virtual double getHeight();
	virtual double getHypotenuseLength();
	virtual void resize(double width, double height);

private:
	double width;
	double height;
};

#endif // RIGHTTRIANGLE_H
