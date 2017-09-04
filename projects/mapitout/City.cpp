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

	

private:
	void set_location(const Point & new_loc) {
		location.set_x(new_loc.get_x());
		location.set_y(new_loc.get_y());
	}
public:
	void new_location(void) {
		cout << "Enter the city's location (x-coordinate, y-coordinate):\n";
		location.Input();
	}
	// future implementation to allow control returning
	bool new_name(void) {
		cout << "Enter city name:\n";
		cin.getline(name, MAX_CITY_NAME);
		return true;
	}

	void print(void) {
		cout << "Name: " << name << "\nLocation: ( x: " << location.get_x() << " , y: " << location.get_y() << " )\n";
	}
};

City::City(void) {
	new_name();
	new_location();
}

int main() {
	City * cit = new City();
	cit -> print();
	delete cit;
}