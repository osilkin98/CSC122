#include "rational.h"
#include <cmath>
#include <iostream>

using namespace std;

/*** critical mutators***/
bool rational::set_dem(const int d) {
	switch(d) { // can't set 0 as a denominator
		case 0:
			return false;
		default:
			dem = d;
			return true;
	}
}

// set the numerator 
bool rational::set_num(const int n) { 
	num = n; 
	return true;
}


// set fractions
bool rational::set_frac(int n, int d) {
	switch(d) {
		case 0:
			return false;
		default:
			reduce(n, d);
			if(d < 0 && n < 0) { // if both n & d are negative then factor out the -1
				set_dem((-1)*d);
				set_num((-1)*n);
			} else if( d < 0 && n >= 0) { // else if d is negative and n >= 0 then flip that
				set_dem((-1)*d);
				set_num((-1)*n);
			} else {
				set_dem(d);
				set_num(n);
			}
			return true;
	}
}



// computes the greatest common denominator between two integers using euclid's GCD algorithm 
int rational::gcd(int top, int bot) {
	int x = abs(top), y = abs(bot); // assign two integers x & y the numerator & denominator values
	int r = 1, q = 0; // create variables r and q for the remainder and quotient, respectively
	while( r != 0 ) { // while r is not equal to zero
		q = 0; // reset the quotient 
		r = x; // set x as the vaue for the remainder
		while( r > 0 && r >= abs(y)) { // while the remainder does not satisfy: 0 <= r < |y|
			r -= y; // just keep subtractin' y
			q++; // increment the quotient 
		}
		
		// cout << x << " = " << y << " x " << q << " + " << r << endl;
		if( r != 0) { // if the remainder is not yet 0, set (x, y) => (y, r)
			x = y;
			y = r;
		}
	}
	// we have found the GCD!
	return y;
}

void rational::reduce(int &a, int&b) {
	int d = gcd(a, b);
	a = a / d;
	b = b /d;
}



/**** CONSTRUCTORS ****/
rational::rational(void) { set_frac(1, 1); }

rational::rational(const int n, const int d) {
	if(!set_frac(n, d)) {
		set_frac(1, 1);
	}
}

bool rational::reciprocal(void) {
	return set_frac(dem, num);
}
// sum
bool rational::sum(rational & other) {
	return set_frac(num * other.get_dem() + dem * other.get_num(), other.get_dem() * dem);
}

bool rational::diff(rational & other) { 
	return set_frac(num * other.get_dem() - dem * other.get_num(), dem * other.get_dem());
}

bool rational::product(rational & other) {
	return set_frac(num * other.get_num(), dem * other.get_dem());
}

bool rational::quotient(rational & other) { 
	return set_frac( num * other.get_dem(), dem * other.get_num());
}

int main() {
	rational rat(10, -5);
	rat.print();
	return 0;
}
