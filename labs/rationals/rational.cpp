#include "rational.h"
#include <cmath>



/*** critical mutators***/
bool rational::set_dem(const int d) {
	switch(d) {
		case 0:
			return false;
		default:
			dem = d;
			return true;
	}
}


bool rational::set_num(const int n) { 
	num = n; 
	return true;
}


// set fractions
bool rational::set_frac(const int n, const int d) {
	if(d < 0 && n < 0) { // if both n & d are negative then factor out the -1
		set_dem((-1)*d);
		set_num((-1)*n);
	} else if( d < 0 && n >= 0) { // else if d is negative and n >= 0 then flip that
		set_dem((-1)*d);
		set_num((-1)*n);
	} else if(set_dem(d)) { // else if d is non-zero 
		return set_num(n);
	} else { // else if d is 0 return nothing; dont set 
		return false;
	}
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
	
	return 0;
}
