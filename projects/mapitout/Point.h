#pragma once
#include <float.h>
#include <cmath>
#include <iostream>

#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED

using namespace std;

// A 2D point class
class Point
{
	double x, // x coordinate of point
		y; // y coordinate of point

public:
	Point(void);
	Point(double new_x, double new_y);
	Point(const Point & p);

	void Output(void) const {
		cout << "(" << x << ", " << y << ")\n";
	}

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

	Point midpoint(const Point & other) const {
		return Point((other.get_x() + x) / 2, (other.get_y() + y) / 2);
	}

	double get_x(void) const { return x; }
	double get_y(void) const { return y; }

	void set_x(double new_x) {
		x = new_x;
	}// mutators
	void set_y(double new_y) {
		y = new_y;
	};

	Point flip_x(void) const {
		return Point(-1 * x, y);
	}
	Point flip_y(void) const {
		return Point(x, -1 * y);
	} 

	Point shift_x(double move_by) const {
		return Point(x + move_by, y);
	}  
	Point shift_y(double move_by) const {
		return Point(x, move_by + y);
	}
};

Point::Point(void) {
	x = y = 0;
}

Point::Point(double new_x, double new_y) {
	x = new_x;
	y = new_y;
}

Point::Point(const Point & p) {
	x = p.x;
	y = p.y;
}
 
#endif
