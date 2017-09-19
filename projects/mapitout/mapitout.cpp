#include "City.h"
#include "Point.h"
#include <vector>
#include <cstring>
#include <cctype>

#define CITY_LIMIT 512

using namespace std;

// method to print all the cities we have,
// if we have 
void print_cities(vector<City*> *v) {
	// prints the individual cities within the vector
	for(int i = 0; i < v -> size(); i++) {
		cout << i + 1 << ") ";
		(*v)[i] -> print();
		cout << "\n";
	} // unless we have a custom menu using the print cities function,
	 // we pause the program and wait for the user to hit enter
	
}

// basically measures the distance between two user-specified cities
bool measure_distance(vector<City*> *v) {
	if(v -> size() < 2) { // if we have < 2 cities, we can't do anything
		cout << "\n\t\nError: Must have at least 2 entries in order to make distance measurements\n\n";
		return false;
	} else { // otherwise
		int a, b;
		// if the size is EXACTLY 2, then we can measure the distance
		// between the two cities that we have
		if(v -> size() == 2) {
			a = 1;
			b = 2;
		} else { // otherwise, print the cities for the user to choose from
			print_cities(v); 
			
			// to be added: verification that both a & b are within the correct indices of v.size()		
			cout << "\nEnter the first city's number: ";
			cin >> a;
			cout << "\nEnter the second city's number: ";
			cin >> b;
			cin.clear();
			cin.ignore(256, '\n');
		}
		// calculate the distance between two user specified cities and print it out
		 cout << "\nDistance between " << v[0][a - 1] -> get_name() << " and " << v[0][b - 1] -> get_name() << " is: " 
			  << (v[0][a - 1] -> get_location()).distance((v[0][b - 1] -> get_location())) << endl;
		 
		 return true;
	}
}

// function which allows the user to enter cities
void enter_cities(vector<City*> *v) {
	// i don't know why there's a limit on cities seeing as we're using a vector but I'm fine with it
	// if the current size is less than the maximum size, then we can add more cities
	if(v -> size() < CITY_LIMIT) {
		char t = 'y'; 
		bool mem_full = false;
		// while the memory isn't full and the user still wants to enter new cities
		while(tolower(t) != 'n' && !mem_full) {
			//cout << v -> size();
			City *cit = new City();	
			cit -> new_name();
			cout << endl;
			cit -> new_location();
			cout << endl;
			v -> push_back(cit);
			mem_full = v -> size() < CITY_LIMIT ? false : true;
			
			cout << "Continue? (y/n): ";
			cin >> t;
			cout << "\n";
			// if the user gives us something other than y/n,
			while(tolower(t) != 'y' && tolower(t) != 'n') {
				cout << "Error: invalid option!\n\nContinue? (y/n): ";
				cin >> t;
			}
			
		} // if the memory is full, then we must notify the user at once!
		if(mem_full) {
			cout << "\n\t\nError: Exiting: Memory Full! Delete entries before making new ones!\n\n";
		}
		// otherwise if the current size is at the limit, notify the user at once!
	} else {
		cout << "\n\nError: Memory Full; Delete entries before making new ones\n\n";
	}
}

// main function basically
int main() {
	
	//initialization
	vector<City*> cities;
	cities.reserve(CITY_LIMIT);
	char in = 'a';
	
	// main loop
	while(in != '4' && 'q' != tolower(in)) {
		cout << "\n\nEnter the number or first letter of your choice:\n\n" 
			<< "\t1) Enter city information" 
			<< "\n\t2) Calculate distance between two cities"
			<< "\n\t3) Print all cities"
			<< "\n\t4) Quit\n\t\nMenu: "; 
		
		cin >> in;
		cout << "\n";
		// create & append new cities to the vector
		if( in == '1' || tolower(in) == 'e') {
			enter_cities(&cities);
		} else if ( in == '2' || tolower(in) == 'c') { // calculate distance between two cities in the grid
			
			measure_distance(&cities);
		} else if(in == '3' || tolower(in) == 'p') { // print a list of cities in the grid alongside their information
			print_cities(&cities);
		}
	}
	
	// exit here 
	return 0;
}
