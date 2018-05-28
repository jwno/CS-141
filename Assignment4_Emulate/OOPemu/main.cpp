// main.cpp
// Assignment 4 example
// In this file, you'll need to do two things:
//
// (1) Finish the createVirtualMethodTables() function, making sure to
//     create VMT's for all of the "classes" you're emulating.
// (2) Add code to the main() function that creates at least one object
//     of each type and demonstrates your emulation of polymorphism by
//     calling all of the methods on it.
//
// (Note: The program will not run succesfully until you fill in the missing parts
// of Circle.cpp.)

#include <iostream>
using namespace std;

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "RightTriangle.h"

void createVMTs()
{
	Shape_createVMT();
	Circle_createVMT();
	Rectangle_createVMT();
	Square_createVMT();
	RightTriangle_createVMT();

	// TO DO: Create the rest of the VMT's.
}

int main()
{
	createVMTs();

	// Here is an example of creating a Circle object and calling its
	// area() method.  Notice that we must be aware that the area()
	// method is at position 3 in the VMT.  (Of course, it must be in
	// that position in the VMT's in *all* kinds of Shapes, otherwise
	// dynamic binding will choose the wrong method.)
	//
	// The toughest part of the code to understand is the call to the
	// area() method...
	//
	//    ((fp_Shape_area)(s->vmt[3]))(s)
	//
	// Here's what it means...
	//
	// We start with s->vmt[3], which is a pointer to a function;
	// specifically, we know that it's a pointer to an area() function.
	// So, in order to use it that way, we need to first cast it:
	//
	//    (fp_Shape_area)(s->vmt[3])
	//
	// According to a declaration in Shape.h, here's what an fp_Shape_area
	// is...
	//
	//     typedef double (*fp_Shape_area)(Shape* s);
	//
	// That's just a fancy way of saying "fp_Shape_area is a pointer to a
	// function that takes a Shape pointer as a parameter and returns a
	// double."
	//
	// In order to call it, we simply follow it with a parameter list:
	//
	//    ((fp_Shape_area)(s->vmt[3]))(s)
    //
	// ...and we've got ourselves a call to the appropriate function.

	// START Circle
	cout << "TEST Circle" << endl;
	Shape* s = (Shape*) Circle_new(4.0, 5.0, 3.0);
	
	//vmt[0]
	cout << "PositionX of circle is " << ((fp_Shape_getPositionX)(s->vmt[0]))((Shape*)s) << endl;
	
	//vmt[1]
	cout << "PositionY of circle is " << ((fp_Shape_getPositionY)(s->vmt[1]))((Shape*)s) << endl;
	
	//vmt[2]
	((fp_Shape_move)(s->vmt[2]))((Shape*)s, 6.0, 7.0);
	cout << "New PositionX of circle is " << ((fp_Shape_getPositionX)(s->vmt[0]))((Shape*)s) << endl;
	cout << "New PositionY of circle is " << ((fp_Shape_getPositionY)(s->vmt[1]))((Shape*)s) << endl;

	//vmt[3]
	double circleArea = ((fp_Shape_area)(s->vmt[3]))(s);
	cout << "Area of circle w/ radius 3 is " << circleArea << endl;

	//vmt[4]
	((fp_Circle_resize)(s->vmt[4]))((Circle*)s, 100);
	circleArea = ((fp_Shape_area)(s->vmt[3]))(s);
	cout << "Area of circle w/ radius 100 is " << circleArea << endl;

	//vmt[5]
	cout << "Radius of circle is " << ((fp_Circle_getRadius(s->vmt[5]))((Circle*)s)) << endl;

	cout << "END of Circle\n" << endl;
	// END Circle
	
	//=============================================================================================\\
	\\=============================================================================================//
	
	// START Rectangle
	cout << "TEST Rectangle" << endl;
	Shape* s1 = (Shape*)Rectangle_new(5.0, 4.0, 2.0, 3.0);

	//vmt[0]
	cout << "PositionX of rectangle is " << ((fp_Shape_getPositionX)(s1->vmt[0]))((Shape*)s1) << endl;

	//vmt[1]
	cout << "PositionY of rectangle is " << ((fp_Shape_getPositionY)(s1->vmt[1]))((Shape*)s1) << endl;

	//vmt[2]
	((fp_Shape_move)(s1->vmt[2]))((Shape*)s1, 7.0, 6.0);
	cout << "New PositionX of rectangle is " << ((fp_Shape_getPositionX)(s1->vmt[0]))((Shape*)s1) << endl;
	cout << "New PositionY of rectangle is " << ((fp_Shape_getPositionY)(s1->vmt[1]))((Shape*)s1) << endl;

	//vmt[3]
	double rectangleArea = ((fp_Shape_area)(s1->vmt[3]))(s1);
	cout << "Area of rectangle w/ width=2 and height=3 is " << rectangleArea << endl;

	//vmt[4]
	((fp_Rectangle_resize)(s1->vmt[4]))((Rectangle*)s1, 10.0, 15.0);
	rectangleArea = ((fp_Shape_area)(s1->vmt[3]))(s1);
	cout << "Area of rectangle w/ width=10 and height=15 is " << rectangleArea << endl;

	//vmt[5]
	cout << "Width of rectangle is " << ((fp_Rectangle_getWidth(s1->vmt[5]))((Rectangle*)s1)) << endl;

	//vmt[6]
	cout << "Height of rectangle is " << ((fp_Rectangle_getHeight(s1->vmt[6]))((Rectangle*)s1)) << endl;

	cout << "END of Rectangle\n" << endl;
	// END Rectangle
	
	//=============================================================================================\\
	\\=============================================================================================//

	// START Square
	cout << "TEST Square" << endl;
	Shape* s2 = (Shape*)Square_new(3.0, 4.0, 2.0);

	//vmt[0]
	cout << "PositionX of square is " << ((fp_Shape_getPositionX)(s2->vmt[0]))((Shape*)s2) << endl;

	//vmt[1]
	cout << "PositionY of square is " << ((fp_Shape_getPositionY)(s2->vmt[1]))((Shape*)s2) << endl;

	//vmt[2]
	((fp_Shape_move)(s2->vmt[2]))((Shape*)s2, 5.0, 6.0);
	cout << "New PositionX of square is " << ((fp_Shape_getPositionX)(s2->vmt[0]))((Shape*)s2) << endl;
	cout << "New PositionY of square is " << ((fp_Shape_getPositionY)(s2->vmt[1]))((Shape*)s2) << endl;
	
	//vmt[3]
	double squareArea = ((fp_Shape_area)(s2->vmt[3]))(s2);
	cout << "Area of square w/ x=2 is " << squareArea << endl;
	
	//vmt[4]
	((fp_Square_resize1)(s2->vmt[4]))((Square*)s2, 10.0, 10.0);
	squareArea = ((fp_Shape_area)(s2->vmt[3]))(s2);
	cout << "Area of square w/ x=10 y=10 is " << squareArea << endl;
	
	((fp_Square_resize1)(s2->vmt[4]))((Square*)s2, 10.0, 15.0);
	squareArea = ((fp_Shape_area)(s2->vmt[3]))(s2);
	cout << "Area of square w/ x=10 y=15 is " << squareArea << endl;

	
	//vmt[5]
	((fp_Square_resize2)(s2->vmt[5]))((Square*)s2, 10.0);
	squareArea = ((fp_Shape_area)(s2->vmt[3]))(s2);
	cout << "Area of square w/ x=10 is " << squareArea << endl;
	
	//vmt[6]
	cout << "SideLength of square is " << ((fp_Square_getSideLength(s2->vmt[6]))((Square*)s2)) << endl;

	cout << "END of Square\n" << endl;
	// END Square

	//=============================================================================================\\
	\\=============================================================================================//

	// START RightTriangle
	cout << "TEST RightTriangle" << endl;
	Shape* s3 = (Shape*)RightTriangle_new(4.0, 3.0, 3.0, 4.0);

	//vmt[0]
	cout << "PositionX of RightTriangle is " << ((fp_Shape_getPositionX)(s3->vmt[0]))((Shape*)s3) << endl;

	//vmt[1]
	cout << "PositionY of RightTriangle is " << ((fp_Shape_getPositionY)(s3->vmt[1]))((Shape*)s3) << endl;

	//vmt[2]
	((fp_Shape_move)(s3->vmt[2]))((Shape*)s3, 6.0, 5.0);
	cout << "New PositionX of RightTriangle is " << ((fp_Shape_getPositionX)(s3->vmt[0]))((Shape*)s3) << endl;
	cout << "New PositionY of RightTriangle is " << ((fp_Shape_getPositionY)(s3->vmt[1]))((Shape*)s3) << endl;

	//vmt[3]
	double RightTriangleArea = ((fp_Shape_area)(s3->vmt[3]))(s3);
	cout << "Area of RightTriangle w/ width=3 and height=4 is " << RightTriangleArea << endl;

	//vmt[4]
	((fp_RightTriangle_resize)(s3->vmt[4]))((RightTriangle*)s3, 9.0, 12.0);
	RightTriangleArea = ((fp_Shape_area)(s3->vmt[3]))(s3);
	cout << "Area of RightTriangle w/ width=9 and height=12 is " << RightTriangleArea << endl;

	//vmt[5]
	cout << "Width of RightTriangle is " << ((fp_RightTriangle_getWidth(s3->vmt[5]))((RightTriangle*)s3)) << endl;

	//vmt[6]
	cout << "Height of RightTriangle is " << ((fp_RightTriangle_getHeight(s3->vmt[6]))((RightTriangle*)s3)) << endl;

	//vmt[7]
	cout << "HypotenuseLength of RightTriangle is " << ((fp_RightTriangle_getHypotenuseLength(s3->vmt[7]))((RightTriangle*)s3)) << endl;

	cout << "END of RightTriangle\n" << endl;
	// END RightTriangle

	//=============================================================================================\\
	\\=============================================================================================//

	cout << "Deleting Circle Object" << endl;
	((fp_Circle_destructor)(s->vmt[6]))((Circle *)s);
	delete s;
	cout << "\n" << endl;

	cout << "Deleting Rectangle Object" << endl;
	((fp_Rectangle_destructor)(s1->vmt[7]))((Rectangle *)s1);
	delete s1;
	cout << "\n" << endl;

	cout << "Deleting Square Object" << endl;
	((fp_Square_destructor)(s2->vmt[7]))((Square *)s2);
	//delete s2;
	cout << "\n" << endl;

	cout << "Deleting RightTriangle Object" << endl;
	((fp_RightTriangle_destructor)(s3->vmt[8]))((RightTriangle *)s3);
	delete s3;
	cout << "\n" << endl;

	return 0;
}
