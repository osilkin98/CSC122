#include <float.h>
#include <cmath>
#include <iostream>

#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED

/*
	this was the first real project that I had written in C++, so what I wrote is very inefficient for
	the language that it's intended for, so please take that into consideration before passing judgement on me
	for explicitly defining member functions within the header file. Need I remind you that I had not programmed
	anything more than a few math classes here and there in python/Java for the past year.
*/



using namespace std;

// A 2D point class
class Point
{
	double x, // x coordinate of point
		y; // y coordinate of point

public:

	Point(void);  // default constructor
	Point(double new_x, double new_y); // explicit constructor
	Point(const Point & p); // copy constructor
	// outputs the point in (x, y) format
	void Output(void) const {
		cout << "(" << x << ", " << y << ")";
	}
	
	// gets user input
	void Input(void) {
		double n_x, n_y;
		char r, s, t;

		cin >> r >> n_x >> s >> n_y >> t;
		x = n_x;
		y = n_y;
	}

							   // distance between this point and other
	double distance(const Point & other) const {
		return pow(pow(other.get_x() - x, 2) + pow(y - other.get_y(), 2), 0.5);
	}
	// the midpoint between this point and another
	Point midpoint(const Point & other) const {
		return Point((other.get_x() + x) / 2, (other.get_y() + y) / 2);
	}
	// accessor methods to retrieve the point's coordinates
	double get_x(void) const { return x; }
	double get_y(void) const { return y; }
	// sets the x variable
	void set_x(double new_x) {
		x = new_x;
	}// sets the y variable
	void set_y(double new_y) {
		y = new_y;
	};
	// flips the x-coordinate about the y-axis
	Point flip_x(void) const {
		return Point(-1 * x, y);
	}
	// flips the y-coordinate about the x-axis
	Point flip_y(void) const {
		return Point(x, -1 * y);
	} 
	// displaces the x-coordinate by a set amount
	Point shift_x(double move_by) const {
		return Point(x + move_by, y);
	}  

	// displaces the y-coordinate by a set amount
	Point shift_y(double move_by) const {
		return Point(x, move_by + y);
	}
};
// i dont know why i implemented this here but i did
Point::Point(void) {
	x = y = 0;
}
// definitions for the constructor in an unnecessary place
Point::Point(double new_x, double new_y) {
	x = new_x;
	y = new_y;
}
// copy of another object
Point::Point(const Point & p) {
	x = p.x;
	y = p.y;
}
 
#endif
