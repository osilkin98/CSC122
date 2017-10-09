/*** this will be the main running file ***/
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstring>
#include <climits>
#define MAX_FNAME 256
#define MAX_LINE 1024
using namespace std;

// string compare function from previous lab
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

void print_arr(char **& array, size_t size) {
	cout << "{";
	for(size_t word = 0; word < size; ++word) {
		cout << array[word] << ", ";
	}
	cout << "}" << endl;
}
/*
bool dyn_append(char ** & array_original, size_t & current_size, char * new_name) {
	cout << "Reallocating the size of the old array to append '" << new_name << "' to it ..." << endl;
	char ** temp_array;
	bool ok = false;
	temp_array = new char*[current_size + 1];
	if(temp_array != NULL) {
		ok = true;
		size_t word;
		cout << "Copying the contents over to the temp array" << endl;
		for(word = 0; word < current_size; ++word) {
			temp_array[word] = (char*)malloc(strlen(array_original[word]) + 1);
			strcpy(temp_array[word], array_original[word]);
		}
		
		temp_array[word] = new_name;
		
		cout << "Printing the temp array... " << endl;
		print_arr(temp_array, current_size + 1);
		
		
		cout << "original array prior to deletion: " << endl;
		print_arr(array_original, current_size);
		
		//cout << "About to delete the contents of the original array..." << endl;
		for(int i = 0; i < current_size; ++i) {
			//cout << "Deleting: " << 
			delete [] array_original[i];
			array_original[i] = NULL;
		}
		delete [] array_original;
		array_original = temp_array;
		for(size_t word; word < current_size + 1; ++word) {
			temp_array[word] = NULL;
		}
		temp_array = NULL;
		
	}
	
	cout << "Original array has been reallocated and appended..." << endl;
	//cout << "returning from the append function." << endl;
	return ok;
}
	*/
	//Since the scheme i use appends one at a time, there's no reason for a logical size this time
	// although i probably shouldve just used a vector
bool reallocate( int * & original_array, size_t current_size, ssize_t extra_size = 1) {
	bool valid_alloc = false;
	if(extra_size + current_size < 0) {
		return valid_alloc;
	} else {
		int* temp_array;
		temp_array = new int[extra_size+current_size];
		if(extra_size != 0 && temp_array != NULL) {
			valid_alloc = true;
			size_t limit = (current_size + extra_size) > current_size ? current_size : current_size + extra_size;
			for(size_t r = 0; r < limit; ++r) {
				temp_array[r] = original_array[r];
			}
			
			delete [] original_array;
			original_array = temp_array;
			temp_array = NULL;
		}
	}
	return valid_alloc;
}
// works!
bool rtrim(char * & original, int offset) {
	bool valid = false;
	char * temp_string;
	temp_string = new char[strlen(original) - offset];
	if(temp_string != NULL && offset < strlen(original)) {
		valid = true;
		temp_string[strlen(original) - offset] = 0;
		//cout << "strlen(original) - offset = " << strlen(original) << " - " << offset << " = " << strlen(original) - offset << endl;
		//cout << "Original: " << original << "\tlength of original: " << strlen(original) << endl;
		//strncpy(temp_string, original, strlen(original) - offset);
		//cout << temp_string << endl;
		
		for(int start = 0; start < strlen(original) - offset; ++start) {
			temp_string[start] = original[start + offset];
			//cout << "start - offset: " << start - offset << "\n" << start << " : " << original[start] << endl;
		}
		
		//cout << "Trimmed: " << temp_string << "\tlength of trimmed: " << strlen(temp_string) << endl;
		//for(int s = 0; s < strlen(temp_string); ++s) {
	//		cout << temp_string[s] << " ";
		//}
		/*cout << "Using strncpy to fix the error... " << endl;
		char * new_copy;
		strncpy(new_copy, temp_string, strlen(original) - offset);
		cout << "Now temp_string is: " << new_copy << endl;
		cout << endl;*/
		delete [] original;
		original = temp_string;
		temp_string = NULL;
	}
	return false;
}

int string_search_offset(char * search_string, char * target_string, size_t offset = 0) {
	if(offset + strlen(search_string) <= strlen(target_string)) {
		
		char * mod;
		mod = new char[strlen(target_string)];
		strcpy(mod, target_string);
		rtrim(mod, offset);
		
		int i = strcmp_ncase(search_string, strlen(search_string), mod, strlen(search_string));
		//cout << "String comparisson yields: " << i << endl;
		return i;
	}
	//cout << "We can NOT compare the two strings" << endl;
	return -1;
}

int file_search(char const * file_name) {
	ifstream file;
	file.open(file_name);
	int status = 1;
	if(!file) {
		status = -2;
	} else {
		char search_string[MAX_LINE+1];
		cout << "Enter a name: " << flush;
		cin.getline(search_string, MAX_LINE);
		cin.clear();
		
		size_t ln = 1, size = 0; 
		char line[MAX_LINE + 1];
		char * dynstr = NULL;
		int *indeces = NULL;
		indeces = new int[size];
		
		// fill the array with words
		while(file.getline(line, MAX_LINE)) {

			dynstr = line;		
			if(strlen(search_string) <= strlen(dynstr)) {
				for(size_t offset = 0; offset <= strlen(dynstr) - strlen(search_string); ++offset) {
					if(string_search_offset(search_string, dynstr, offset) == 0) {
						reallocate(indeces, size);
						indeces[size] = ln;
						size++;
					}
				}
			}

			
			ln++;
		}
		
		cout << "'" << search_string << "' occurs " << size << " time";
		if(size != 1) {
			cout << "s";
		}
		cout << " on the following lines: {";
		for(int i = 0; i < size; ++i) {
			cout << indeces[i];
			if(i+1 < size) {
				cout << ", ";
			}
		}
		cout << "}" << endl;
		
	}
	
	file.close();
	file.clear();
	return status;
}


int main() {
	
	// 1. get file name
	// 2. check open status of file, if failed to open, go back to step 1
	// 3. prompt name to look for or to open a new file,
	// 	  if the latter is chosen, go back to step 1
	// 4. search for name, if name is not found, go back to step 3
	// 5. name is found, output position of name in file, go back to step 3
	
	char cont= 'y';
	char filename[MAX_FNAME];
	while(tolower(cont) == 'y') {
		// prompt for filename
		cout << "Enter the name of your file: ";
		cin.getline(filename, MAX_FNAME);
		cout << endl << filename << endl;
		// try to open the file and initiate search algorithm
		if(file_search(filename) == -2) {
			cout << "Sorry the file does not exist." << endl;
		}
		cout << "Enter another filename?\n[y/n]: " << flush;
		cin >> cont;
		cin.ignore(INT_MAX, '\n');
		cout << cont << endl;
		while(tolower(cont) != 'y' && tolower(cont) != 'n') {
			cout << "Type 'y' or 'n': " << flush;
			cin >> cont;
			cin.ignore(INT_MAX, '\n');
			
		}
	}
	
	return 0;
}
