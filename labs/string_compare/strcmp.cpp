#include <iostream>
#include <cstring>
#include "strextra.h"
#include <stdio.h>

#define size(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

int main() {
	char s1[] = "1 34";
	char s2[] = "12'5";
	// returns 15
	//int size = sizeof(s1)/sizeof(s1[0])
	//int arr[] = { 5, 1 , 10, 11, 4 };
	cout << strcmp_ncase(s1, size(s1) , s2, size(s2), true, true);
	
		
	
	return 0;
}

