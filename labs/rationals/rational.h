#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H


class rational {
	private:
		int num, dem;
		//double ratio;
		
		/****** CRITICAL MUTATORS *****/
		bool set_dem(const int d);
		bool set_num(const int n);
		void reduce(int &a, int &b);
	public:
		/****** ACCESSORS *********/
		int get_num(void) { return num; }
		int get_dem(void) { return dem; }
		double get_ratio(void) { return ((double)num / (double)dem); }
		
		int gcd(int x, int y);
		
		/******* CONSTRUCTORS ********/
		
		rational(void);
		
		rational(const int n, const int d);
		
		
		/****** MUTATORS  *************/
		bool set_frac(const int n, const int d);
		bool change_dem(const int d); // must be implemented 
		bool change_num(const int n);
		
		 
		// print function 
		char const* get_text(void) { return  num + "/" + dem; }
		void print(void) { std::cout << num <<  "/" << dem << std::endl; }
		//additive inverse will be added whence I am to receive more clarification from the instructor
		
		
		
		/******* MATH RELATED FUNCTIONS (MUTATORS) *******/
		
		bool reciprocal(void);
		// sum
		bool sum(rational & other);
		
		bool diff(rational & other);
		
		bool product(rational & other);
		
		bool quotient(rational & other);
		
		/***** COMPARISON FUNCTIONS ****/
		
		bool less_than(rational & other) { return num * other.get_dem() < dem * other.get_num(); }

		bool greater_than(rational & other) { return num * other.get_dem() > dem * other.get_num(); }

		bool equal_to(rational & other) { 	return num * other.get_dem() == dem * other.get_num(); }

		bool greater_than_equal_to(rational & other) { 	return greater_than(other) || equal_to(other); }

		bool less_than_equal_to(rational & other) { return less_than(other) || equal_to(other); }

		bool not_equal_to(rational & other) { return !equal_to(other); }
};

#endif
