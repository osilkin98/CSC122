#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int strcmp_ncase( const char * s1, const int sz1, const char * s2, const int sz2, bool ig_space = false, bool ig_punct = false) {
	int max = sz1 > sz2 ? sz2 : sz1;
	for(int i = 0; i < max; i++) {		
		//cout << s1[i] << " - " << s2[i] << " = " << tolower(s1[i]) - tolower(s2[i]) << endl;
		if( ig_space && (isspace(s2[i]) != 0 || isspace(s1[i]) != 0) ) {
			continue;	
		} else if ( ig_punct && (ispunct(s1[i]) != 0 || ispunct(s2[i]) != 0) ) {
			continue;
		}
		if( tolower(s1[i]) != tolower(s2[i])) {
			
			return isdigit(s1[i]) && isdigit(s2[i]) ? (-1)*(tolower(s2[i]) - tolower(s1[i])) 
				: tolower(s2[i]) - tolower(s1[i]);
		}
	}
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

// bubble sort algorithm for sorting ann array of numbers
void number_sort(auto *arr, int length) {
	int c, b;
	cout << endl;
	while(b != 0) {
		for( int i = length - 1; i > -1; i--) {
			b = 0;
			cout << i + 1 << ".) ";
			if(arr[i + 1] < arr[i]) {
				b++;
				c = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = c;
				print_array(arr, length);
				cout << " " << arr[i + 1] << " <=> " << arr[i] << endl;
			} else {
				print_array(arr, length);
				cout << " false\n";
			}
		}
	}
}

