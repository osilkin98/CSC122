#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int strcmp_ncase( const char * s1, const int sz1, const char * s2, const int sz2) {
	if(sz1 > sz2) {
		return 1;
	} else if (sz2 > sz1) {
		return -1;
	} else {
		for(int i = 0; i < sz1; i++) {
			if( tolower(s1[i]) > tolower(s2[i]) ) {
				return 1;
			} else if ( tolower(s1[i]) < tolower(s2[i]) ) {
				return -1;
			}
		}
		return 0;
	}
}
