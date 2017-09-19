#ifndef STREXTRA_H
#define STREXTRA_H


int strcmp_ncase( const char * s1, const int sz1, const char * s2, const int sz2, bool ig_space, bool ig_punct);
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
void number_sort(int *arr, int length);
#endif
