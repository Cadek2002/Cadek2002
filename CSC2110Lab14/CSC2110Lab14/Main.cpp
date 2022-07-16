//==========================================================
//
// Title:      Inheritance/Virtual Funcitons lab
// Course:     CSC 2110
// Lab Number: 14
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

class Complex {

	float real, imag;

public:

	Complex(float a, float b) {
		real = a;
		imag = b;
	}

	float getReal() {
		return real;
	}

	float getImag() {
		return imag;
	}

	void setReal(float a) {
		real = a;
	}

	void setImag(float a) {
		imag = a;
	}

	void display() {
		cout << real << (imag >= 0 ? "+" : "") << imag << "i";
	}

	Complex operator + (Complex const& a) {
		return Complex(real + a.real, imag + a.imag);
	}

	Complex operator - (Complex const& a) {
		return Complex(real - a.real, imag - a.imag);
	}

	Complex operator / (Complex const& a) {
			if (a.real && a.imag) return Complex((real * a.real + imag * a.imag) / (pow(a.real, 2) + pow(a.imag, 2)), (real * a.imag * (-1) + imag * a.real) / (pow(a.real, 2) + pow(a.imag, 2)));
			else {
				cout << "ERROR: One or more elements of denominator is a zero. ";
				return Complex(0, 0);
		}
	}

};
int main() {
	float x, y;
	int input = 0;
	cout << "Enter two sets of real numbers: ";
	cin >> x >> y;
	Complex a(x, y);
	cin >> x >> y;
	Complex  b(x, y);

	cout << "Comlpex number a: ";
	a.display();
	cout << "\nComlpex number b: ";
	b.display();


	while (input != 6) {
		cout << "\n\nOptions:\n1) Set Complex numbers.\n2) Add\n3) Subtract\n4) Divide\n5) Display a&b\n6) Exit\nChoose an Option: ";
		cin >> input;

		switch (input) {
		case 1:
			cout << "Enter two sets of real numbers: ";
			cin >> x >> y;
			a.setReal(x);
			a.setImag(y);
			cin >> x >> y;
			b.setReal(x);
			b.setImag(y);
			break;
		case 2:
			(a + b).display();
			break;
		case 3:
			(a - b).display();
			break;
		case 4:
			(a / b).display();
			break;
		case 5: 
			cout << "a: ";
			a.display();
			cout << "\nb: ";
			b.display();
		case 6:
			break;
		default:
			cout << "UNRECKOGNIZED INPUT\n";
		}
	}
}