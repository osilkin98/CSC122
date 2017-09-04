#include "City.h"
#include "Point.h"
#include <vector>
#include <cstring>
#include <cctype>

#define CITY_LIMIT 3

using namespace std;

// works 
void print_cities(vector<City*> *v, bool const cust) {
	for(int i = 0; i < v -> size(); i++) {
		cout << i + 1 << ") ";
		(*v)[i] -> print();
		cout << "\n";
	}
	if(!cust) {
		system("pause");
	}
	
}


double measure_distance(vector<City*> *v) {
	if(v -> size() < 2) {
		return -1;
	} else {
		int a, b;
		if(v -> size() == 2) {
			a = 1;
			b = 2;
		} else {
			print_cities(v, true); 
			
			// to be added: verification that both a & b are within the correct indices of v.size()		
			cout << "\nEnter the first city's number: ";
			cin >> a;
			cout << "\nEnter the second city's number: ";
			cin >> b;
		}
		return (*v)[a - 1] -> distance( (*v)[b - 1] );
	}
}

void enter_cities(vector<City*> *v) {
	if(v -> size() < CITY_LIMIT) {
		char t = 'y';
		bool mem_full = false;
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
			cout << "\n\n";
			while(tolower(t) != 'y' && tolower(t) != 'n') {
				cout << "Error: invalid option!\n\nContinue? (y/n): ";
				cin >> t;
			}
			
		}
		if(mem_full)
			cout << "\n\nError: Exiting: Memory Full! Delete entries before making new ones!\n\n";
	} else {
		cout << "\n\nError: Memory Full; Delete entries before making new ones\n\n";
	}
}

int main() {
	
	//initialization
	vector<City*> cities;
	cities.reserve(CITY_LIMIT);
	char in = 'a';
	
	// main loop
	while(in != '4' && 'q' != tolower(in)) {
		cout << "\n\nEnter the number or first letter of your choice\n\n" 
			<< "1) enter city information\n" 
			<< "2) calculate distance between two cities\n"
			<< "3) print all cities\n"
			<< "4) quit\n\nMenu: "; 
		
		cin >> in;
		cout << "\n\n";
		// create & append new cities to the vector
		if( in == '1' || tolower(in) == 'e') {
			enter_cities(&cities);
		} else if ( in == '2' || tolower(in) == 'c') { // calculate distance between two cities in the grid
			
			double dist = measure_distance(&cities);
			
			if(dist < 0) {
				cout << "\n\nError: Must have at least 2 entries in order to make distance measurements\n\n";
			} else { 
				cout << "Distance: " << dist << "\n";
			}
		} else if(in == '3' || tolower(in) == 'p') { // print a list of cities in the grid alongside their information
			print_cities(&cities, false);
		}
	}
	
	// exit here 
	delete & cities;
	return 0;
}
