#include <float.h>
#include "Point.h" 
#include <cmath>
#include <iostream>
#include <string>
const size_t MAX_CITY_NAME = 58; // longest city name is 58 letters, I don't think  there's any need for anything longer

using namespace std;

class City
{
	Point location;
	char name[MAX_CITY_NAME];
public:
	City(void);
	double distance(const City & other) const
	{
		return location.distance(other.location);
	}
	Point get_location(void) const
	{
		return location;
	}

	char* get_name(void) {
		return name;
	}

private:
	void set_location(const Point & new_loc) {
		location.set_x(new_loc.get_x());
		location.set_y(new_loc.get_y());
	}
public:
	void new_location(void) {
		cout << "Enter the city's location (x-coordinate, y-coordinate): ";
		location.Input();
	}
	// future implementation to allow control returning
	void new_name(void) {
		cout << "Enter city name: ";
		cin.ignore();
		cin.getline(name, MAX_CITY_NAME);
	}
	
	void new_entry(void) {
		new_location();
		new_name();
	}
	
	
	void print(void) {
		cout << "\tName: " << name << "\n\tLocation: ( x: " << location.get_x() << " , y: " << location.get_y() << " )\n";
	}
};

City::City(void) {
	
}
