//==========================================================
//
// Title:      Inheritance/Virtual Funcitons lab
// Course:     CSC 2110
// Lab Number: 13
// Author:     Cayden Koweck
// Date:       10/18/2021
// Description:
//   Virtual functions and other things
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type

using namespace std; // So "std::cout" may be abbreviated to "cout"
	
class rectangle {
	double length;
	double width;
public: 

	double getLength() {
		return length;
	}

	double getWidth() {
			return width;
	}

	void setWidth(double x) {
		width = x;
	}

	void setLength(double x) {
		length = x;
	}

	rectangle() {
		length = 0;
		width = 0;
	}
	rectangle(double x, double y) {
		length = x;
		width = y;
	}

	virtual double area() {
		return length * width;
	}
	double perimeter() {
		return (2 * length + 2 * width);
	}

	void print() {
		cout << "\nLength: " << length << "\nWidth" << width;
	}

	virtual double volume() = 0;

};

class box: public rectangle {
	double height;

public:

	double getHeight() {
		return height;
	}

	void setHeight(double x) {
		height = x;
	}

	box(double x, double y, double z) : rectangle(x, y) {
		height = z;
	}

	box() : rectangle() {
		height = 0;
	}

	double area() {
		return 2 * rectangle::area() + 2 * getLength() * height + 2 * height * getWidth();
	}

	double volume() {
		return rectangle::area() * height;
	}

	void print() {
		cout << "\nLength: " << getLength() << "\nWidth" << getWidth() << "\nHeight: " << height;
	}

};

int main() {
	int dims[3];

	cout << "Insert two sets of length, width and height: ";

	for (int i = 0; i < 3; i++) cin >> dims[i];
	box b1(dims[0], dims[1], dims[2]);

	for (int i = 0; i < 3; i++) cin >> dims[i];
	box b2(dims[0], dims[1], dims[2]);

	cout << "Box One: ";
	b1.print();
	cout << "\nArea: " << b1.area() << "\nVolume: " << b1.volume();

	cout << "\n\nBox Two: ";
	b2.print();
	cout << "\nArea: " << b2.area() << "\nVolume: " << b2.volume();

}