#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H


class rational {
	private:
		int long num, dem;
		//double ratio;
		
		/****** CRITICAL MUTATORS *****/
		inline bool set_dem(const long int d);
		inline bool set_num(const long int n);
		void reduce(int long &a, int long &b);
	public:
		/****** ACCESSORS *********/
		inline int long get_num(void) { return num; }
		inline int long get_dem(void) { return dem; }
		inline double get_ratio(void) { return ((double)num / (double)dem); }
		
		long int gcd(long int x,long int y);
		
		/******* CONSTRUCTORS ********/
		
		rational(void);
		
		rational(const long int n, const long int d);
		
		
		/****** MUTATORS  *************/
		bool set_frac(const long int n, const long int d);
		
		 
		// simply outputs the rational with no endline
		inline void Output(void) { if(num == 0) { std::cout << "0"; 
					} else if(dem == 1) { std::cout << num;
					} else { std::cout << num << "/" << dem; } }
		inline void printline(void) { if(num == 0) { std::cout << "0" << std::endl; 
					} else if(dem == 1) { std::cout << num << std::endl;
					} else { std::cout << num << "/" << dem << std::endl; } }
		// takes in the user's input without prompting them to enter anything, which is something they should do on their own
		bool Input(void);
		

		//additive inverse will be added whence I am to receive more clarification from the instructor
		
		
		
		/******* MATH RELATED FUNCTIONS (MUTATORS) *******/
		
		inline rational const reciprocal(void);
		// sum
		inline rational const sum(rational & other);
		
		inline rational const diff(rational & other);
		
		inline rational const  product(rational & other);
		
		inline rational const  quotient(rational & other);
		
		/***** COMPARISON FUNCTIONS ****/
		
		inline bool less_than(rational & other) { return num * other.get_dem() < dem * other.get_num(); }

		inline bool greater_than(rational & other) { return num * other.get_dem() > dem * other.get_num(); }

		inline bool equal_to(rational & other) { 	return num * other.get_dem() == dem * other.get_num(); }

		inline bool greater_than_equal_to(rational & other) { 	return greater_than(other) || equal_to(other); }

		inline bool less_than_equal_to(rational & other) { return less_than(other) || equal_to(other); }

		inline bool not_equal_to(rational & other) { return !equal_to(other); }
};

#endif

