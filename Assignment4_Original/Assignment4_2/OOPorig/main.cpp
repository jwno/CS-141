// main.cpp
// Assignment 4 example
// This source file contains the main() function, which is where C++ programs
// begin their execution.  While C++ programs can take command-line parameters,
// just as Java programs can, including the necessary parameters to main() is
// optional, so I've left them off.  According to the C++ standard, the main()
// function must return int.  This value is returned to the operating system,
// and is typically used as a rather primitive way for a program to indicate to
// the operating system whether it succeeded or not, with 0 indicating success,
// and non-zero values indicating various error conditions.  (Java programs can
// do this, too, by passing this value as a parameter to System.exit().)

// Standard C and C++ headers should be included using the angle-bracket 
// notation shown here.  Interestingly, Standard C++ headers don't use the
// .h extension anymore.  In fact, if you include <iostream.h> instead of
// <iostream>, you get an older version that is different (and incompatible)
// with the current one.
#include <iostream>

// This line is necessary to allow variables like cout to be globally
// visible, as opposed to being accessible only with their full names
// (e.g., std::cout).  This is roughly analogous to the import statement
// in Java.
using namespace std;

// We'll also need our program to be able to use classes like Circle,
// Rectangle, Square, and RightTriangle, so we'll include their declarations
// (but not their definitions!) here.
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "RightTriangle.h"

int main()
{
	// This line of code declares an array of four Shape pointers.  Each
	// Shape pointer will be able to legally point to any kind of shape
	// object (e.g., Circle, Rectangle, etc.), just like Shape references
	// in Java.  The array is allocated statically (i.e., on the run-time
	// stack).  We could also opt to allocate the array dynamically with
	// the following line of code:
	//
	//     Shape** s = new Shape*[4];
	//
	// ...but since the size of the array is known at compile time (and is
	// small), and since the array will only be accessed within this function,
	// it makes sense to declare it on the stack.  (Remember: whenever you
	// use "new", you have to remember to use "delete".  Better to put things
	// on the stack when possible.)
	Shape* s[4];

	// Assigning to an array element in C++ is done just like it is in Java.
	// Creating an object using new is the same, too.  The result of the
	// call to the new operator is a Circle pointer; since Shape pointers
	// can point to Circle objects, this is a legal assignment.
	s[0] = new Circle(5.0, 2.0, 3.0);

	// This is analogous to System.out.println in Java.  The "endl" notation
	// indicates that an end-of-line should be printed, and that the output
	// should be flushed, so that it is written to the console immediately,
	// rather than buffered to be written later.
	cout << "shape 0 is a Circle at (5.0, 2.0) with radius 3.0" << endl;

	s[1] = new Rectangle(4.0, 5.0, 6.0, 7.0);
	cout << "shape 1 is a Rectangle at (4.0, 5.0) with width 6.0 and height 7.0" << endl;

	s[2] = new Square(3.0, 4.0, 5.0);
	cout << "shape 2 is a Square at (3.0, 4.0) with side length 5.0" << endl;

	s[3] = new RightTriangle(4.0, 5.0, 6.0, 7.0);
	cout << "shape 3 is a RightTriangle at (4.0, 5.0) with width 6.0 and height 7.0" << endl;

	// for loops behave essentially the same way in C++ as they do in Java.
	for (int i = 0; i < 4; i++)
	{
		// s[i]->area() is a call to the area() function on the i-th object
		// in the array.  The -> operator is a shorthand for "follow this
		// pointer to where it points and then call a function on that
		// object".  Since s[i] is a pointer to a Shape, the -> operator is
		// needed to call the function.
		//
		// (Java uses only one operator, ".", for accessing the members of an
		// object.  C++ provides two: "." and "->".  The reason is that Java
		// requires all objects to be on the heap, but C++ allows you to put
		// them either on the heap or on the stack.  So C++ has two different
		// operators for accessing a member of an object, depending on where
		// you decided to put it.)
		cout << "the area of shape " << i << " is " << s[i]->area() << endl;
	}
	
	// Now it's time to delete the objects that were created dynamically
	// using "new".  There are four such objects in the array.
	// Failing to delete the objects will result in a memory
	// leak.  Oftentimes, too, an object holds some kind of global resource
	// (e.g., a file or a database connection) that needs to be cleaned up
	// when the object is destroyed; failing to destroy the object will
	// also cause the global resource to be leaked, which can often be much
	// worse than just leaking memory.
	for (int i = 0; i < 4; i++)
	{
		delete s[i];
	}

	// Since main is required to return an int, but we're not going to use
	// the return value for anything, we'll simply return 0, which typically
	// indicates that the program succeeded.
	return 0;
}
