#include <cmath>
#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H


class rational {
	private:
		int num, dem;
		double ratio;
		
		bool set_dem(const int d) {
			switch(d) {
				case 0:
					return false;
				default:
					dem = d;
					return true;
			}
		}
		
		bool set_num(const int n) { 
			num = n; 
			return true;
		}
		
	public:
		/****** ACCESSORS *********/
		int get_num(void) { return num; }
		int get_dem(void) { return dem; }
		
		
		
		/******* CONSTRUCTORS ********/
		
		rational(void) { 
			set_frac(1, 1);
		}
		
		rational(const int n, const int d) {
			if(!set_frac(n, d)) {
				set_frac(1, 1);
			}
		}
		
		/****** UTILITIES *************/
		// checks to see if the denominator value != 0 & sets 
		bool set_frac(const int n, const int d) {
			
			if(d < 0 && n < 0) { // if both n & d are negative then factor out the -1
				set_dem((-1)*d);
				set_num((-1)*n);
			}
			else if(set_dem(d)) { // else if d is non-zero 
				return set_num(n);
			} else { // else if d is 0 return nothing; dont set 
				return false;
			}
		}
		
		char const* print(void) {
			//std::cout << num << "/" << dem << std::endl;
			if( dem < 0 ) {
				set_frac(-1 * num, -1 * dem);
			}
			return  num + "/" + dem;
		}
		
		//additive inverse will be added whence I am to receive more clarification from the instructor
		
			
		
		/******* MATH RELATED FUNCTIONS *******/
		
		bool reciprocal(void) {
			return set_frac(dem, num);
		}
		// sum
		bool sum(rational & other) {
			return set_frac(num * other.get_dem() + dem * other.get_num(), other.get_dem() * dem);
		}
		
		bool diff(rational & other) { 
			return set_frac(num * other.get_dem() - dem * other.get_num(), dem * other.get_dem());
		}
		
		bool product(rational & other) {
			return set_frac(num * other.get_num(), dem * other.get_dem());
		}
		
		bool quotient(rational & other) { 
			return set_frac( num * other.get_dem(), dem * other.get_num());
		}
		
		/***** COMPARISON FUNCTIONS ****/
		
		bool less_than(rational & other) { 
			return num * other.get_dem() < dem * other.get_num();
		}
		
		bool greater_than(rational & other) {
			return num * other.get_dem() > dem * other.get_num();
		}
		
		bool equal_to(rational & other) {
			return num * other.get_dem() == dem * other.get_num();
		}
		
		bool greater_than_equal_to(rational & other) {
			return greater_than(other) || equal_to(other);
		}
		
		bool less_than_equal_to(rational & other) {
			return less_than(other) || equal_to(other);
		}
		
		bool not_equal_to(rational & other) {
			return !equal_to(other);
		}
};

#endif
