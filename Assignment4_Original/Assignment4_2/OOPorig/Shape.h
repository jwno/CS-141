// Shape.h
// Assignment 4 example
// Contains the declaration (but not the definition!) of the Shape class.
// Remember that header files are used to allow multiple source files to
// share the same set of declarations. However, if definitions (e.g.,
// definitions of functions) are included, the linker will become confused
// in the almost inevitable event that the header file is included in more
// than one source file. So, we tend to declare things in the header file
// and define them in a source file.

// (The distinction between a declaration and a definition is this: A
// declaration states the existence of something -- say, a function -- while
// a definition gives it a meaning -- in the case of a function, the function's
// body gives it meaning.)

// This rather cryptic-looking bit of syntax is necessary, in conjunction with
// the "#endif" notation at the end of this file, to prevent this header file
// from being included more than once in the same source file, which causes
// compile-time errors (i.e., multiple declarations).

#ifndef SHAPE_H
#define SHAPE_H

// Classes in C++ look basically the same as classes in Java, with some
// minor syntactic differences.
//
// * Access modifiers such as "public" or "private" cannot precede the
//   class declaration.  All top-level classes (i.e., those not defined
//   within other classes) are effectively public.
// * Rather than putting "public" or "private" in front of each declaration,
//   you specify "public:" or "private:" before a sequence of declarations.
// * To keep things simple (and as Java-like as possible), I've marked all
//   of the methods "virtual", so that they'll be dynamically bound
//   (polymorphic), just like they are in Java.  Remember that leaving the
//   "virtual" marker off of a method declaration means that it will not be
//   dynamically bound (i.e., polymorphism will not be used when calling it).
// * The area() method is abstract.  In C++, you mark a method abstract by
//   following its declaration with "= 0".  If at least one method in a class
//   is abstract, the class is considered an "abstract base class"
//   automatically, without the need to declare the class explicitly abstract.
//   The consequences of abstractness are the same in C++ as they are in Java:
//   if the class X is abstract, you can't create X objects, but you can have
//   X pointers that point to objects of concrete classes that inherit from X.

class Shape
{
public:
	Shape(double positionX, double positionY);
	virtual double getPositionX();
	virtual double getPositionY();
	virtual void move(double positionX, double positionY);
	virtual double area() = 0;

private:
	double positionX;
	double positionY;
};

#endif // SHAPE_H
