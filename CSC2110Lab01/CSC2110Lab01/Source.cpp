//==========================================================
//
// Title:      NumberInput
// Course:     CSC 2110
// Lab Number: 01
// Author:     Cayden Koweck
// Date:       9/01/2021
// Description:
//   Takes user int input, splits into individual digits, and returns sum of digits
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
	//declare consts

	//declare varibles
	int input;
	int sum = 0;
	int out;

	//header statement
	cout << "Number Splitter and Summation\n=============================\n\n";

	//Main
	cout << "Please insert an integer>>> ";
	cin >> input;

	//assigning input length to a varible
	int len = to_string(input).length();
	
	cout << "\nInput number:\t" << input << "\nSplit digits:\t";

	//the big loop, I spent a bit trying to figure out how to split and store it into an array (or vector as the length is varible) and then realized I didn't have to! Is this efficient? probobly not but it works...

	for (int x = len -1; x >= 0; x--) {
		out = (input / (int)(pow(10, x))) % 10;
		cout << out << " ";
		sum += out;
	}
	cout << "\nSum of digits:\t" << sum;

	//closing statement
	cout << "\n\nEnd of Application";

	// spent a while trying to find out why the input was suddenly changing from assignmtn to printing, then realized my buttopn-mashing of the keyboard was overflowing the int, could probobly change this to a double but no time for that...
	
}
