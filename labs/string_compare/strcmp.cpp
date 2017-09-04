#include <iostream>
#include <cstring>
#include "strextra.h"
#include <stdio.h>

#define sz(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

int main() {
	char s1[] = "a";
	char s2[] = "ba";
	// returns 15
	//int size = sizeof(s1)/sizeof(s1[0])
	
	cout << strcmp_ncase(s1, sz(s1) , s2, sz(s2));
	
	
	
	return 0;
}

