#include "strextra.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

// im only using EMACS to write this so these have no real purpose other than describe the parameters to you since I saw you do it this way in class
/*
@param s1 first input string (c-string)
@param sz1 length of first input string (integer)
@param s2 second input string (c-string)
@param sz2 length of second input string (integer)
@param ig_space [optional] ignore spaces in comparisson (boolean)
@param ig_punct [optional] ignore punctuation when doing comparisson (boolean)

*/
int strcmp_ncase( const char * s1, const int sz1, const char * s2, const int sz2, bool ig_space = false, bool ig_punct = false) {
	int max = sz1 > sz2 ? sz2 : sz1; // compare up to the length of the shorter string
	for(int i = 0; i < max; i++) {	// loop all the way up to the length of the shorter string
		// if we're ignoring spaces we skip to the next iteration of the loop
		if( ig_space && (isspace(s2[i]) != 0 || isspace(s1[i]) != 0) ) {
			continue;	
		// else if we're ignoring punctuation, we skip to the next iteration of the loop
		} else if ( ig_punct && (ispunct(s1[i]) != 0 || ispunct(s2[i]) != 0) ) {
			continue;
		}
		// if, the characters in the string do not match even when they are converted to lowercase chars,
		if( tolower(s1[i]) != tolower(s2[i])) {
			// if both of the characters are digit characters then we want to return the displacement of the two, such that the difference is num2 - num1
			// otherwise, return the lexographic displacement by obtaining the asskey values and quickly computing their difference
			return isdigit(s1[i]) && isdigit(s2[i]) ? (-1)*(tolower(s2[i]) - tolower(s1[i])) 
				: tolower(s2[i]) - tolower(s1[i]);
		}
	}
	// if the two strings are equal in size, AND they have failed to test for being different, then return 0
	// else if they are not the same, then if the first string is of greater length than the second, return 1, else return -1
	return sz1 == sz2 ? 0 : sz1 > sz2 ? 1 : -1;
}


/*  						
void print_array(const auto *arr, int length) {  // for debugging
	cout << "{";
	for(int i = 0; i < length; i++) {
		cout << arr[i];
		if( i + 1 < length) {
			cout << ", ";
		}
	}
	cout << "}";
}*/

// bubble sort algorithm for sorting ann array of numbers (the most efficient sorting algorithm in the world!!!!)
/***

@param *arr An integer array, I was previously compiling with -std=c++11 so I was using the auto variable type for my parameter but standard c++ doesn't like that so it's just int* now =)
@param length the length of the array we're passing in!!!!
*/
void number_sort(int *arr, int length) {
	int c, b = 1; // temporary variables, c is for swapping variables whereas b is for counting whether or not we've performed anymore swappings through our iteration
	while(b != 0) {  // while swappings are a thing
		for( int i = length - 2; i > -1; i--) { // sort from the end of the array down
			b = 0; // reset the swap count
			if(arr[i + 1] < arr[i]) { // if the value prior was smaller than the current value
				b++; // WE'VE GOT AN ITERATION!!!!
				c = arr[i + 1]; // triangle swap
				arr[i + 1] = arr[i]; // triangle swap
				arr[i] = c; // TRIANGLE SWAP
			}
		}
	}
}

int main() {

	return 0;
}

