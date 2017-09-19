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
	// calculates the distance between this city and another
	double distance(const City & other) const
	{
		return location.distance(other.location);
	}
	// accessor method to return the city's current location as a point
	Point get_location(void) const
	{
		return location;
	}
	// returns the city's name as a c-string
	char* get_name(void) {
		return name;
	}

private:
	// sets a new location for this city
	void set_location(const Point & new_loc) {
		location.set_x(new_loc.get_x());
		location.set_y(new_loc.get_y());
	}
public:
	// basically just creates a new location for the city (poorly designed)
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
	// creates a new entry for the city, again very poorly designed
	void new_entry(void) {
		new_location();
		new_name();
	}
	
	// print the city information out to the screen
	void print(void) {
		cout << "\tName: " << name << "\n\tLocation: ( x: " << location.get_x() << " , y: " << location.get_y() << " )\n";
	}
};

City::City(void) {
	
}
