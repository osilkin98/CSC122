#include "rational.h"
#include <cmath>
#include <iostream>
#include <climits>
using namespace std;

/*** critical mutators***/
inline bool rational::set_dem(const long int d) {
	dem = d; // sets denominator
	return true;
}

// set the numerator 
inline bool rational::set_num(const long int n) { 
	num = n; 
	return true;
}


// set fractions
bool rational::set_frac(long int n, long int d) {
	switch(d) {
		case 0: // in the case that 'd' is 0, we do NOT set the fraction with the given values.
			return false;
		default:
			reduce(n, d);
			if(d < 0 && n < 0) { // if both n & d are negative then factor out the -1
				set_dem((-1)*d);
				set_num((-1)*n);
			} else if( d < 0 && n >= 0) { // else if d is negative and n >= 0 then flip the negatives
				set_dem((-1)*d);
				set_num((-1)*n);
			} else {	// otherwise just set the values for the fraction
				set_dem(d);
				set_num(n);
			}
			return true;
	}
}



// computes the greatest common denominator between two integers using euclid's GCD algorithm 
long int rational::gcd(long int top,long int bot) {
	long int x = abs(top), y = abs(bot); // assign two integers x & y the numerator & denominator values
	long int r = 1, q = 0; // create variables r and q for the remainder and quotient, respectively
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
// private function
void rational::reduce(long int &a,long int&b) {
	long int d = gcd(a, b); // get the greatest common divisor
	a = a / d; // reduce the given variables
	b = b /d;
}
// implement the input function
bool rational::Input(void) {
	long int a, b; // create two temporary variables 
	char c; // temporary character to get the '/' in between 
	cin >> a >> c >> b;
	cin.clear(); // clear the cin buffer so that nothing is in limbo
	cin.ignore(INT_MAX,'\n');
	return set_frac(a,b);

}




/**** CONSTRUCTORS ****/
rational::rational(void) {
	set_frac(1, 1); // just set the fraction to be 1/1
}

rational::rational(const long int n, const long int d) {
	if(!set_frac(n, d)) {
		set_frac(1, 1);  // if the values given aren't valid then set them to 1/1 as default
	}
}

inline rational const rational::reciprocal(void) {
	return rational(dem, num); // just return a new rational object which is a reciprocal of the original fraction
}
// sum a new rational that is the sum of the two
inline rational const rational::sum(rational & other) {
	return rational(num * other.get_dem() + dem * other.get_num(), other.get_dem() * dem);
}
// return a new rational which is the difference between the two rationals
inline rational const rational::diff(rational & other) { 
	return rational(num * other.get_dem() - dem * other.get_num(), dem * other.get_dem());
}
// returns the product of the two rationals
inline rational const rational::product(rational & other) {
	return rational(num * other.get_num(), dem * other.get_dem());
}
// returns the quotient of the first rational over the given rational 
inline rational const rational::quotient(rational & other) { 
	return rational( num * other.get_dem(), dem * other.get_num());
}

int main() {
	rational rat;
	rat.Input();
	rat.Output();
	cout << endl;
	return 0;
}
