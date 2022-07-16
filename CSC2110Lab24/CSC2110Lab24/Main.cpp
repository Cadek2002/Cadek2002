/*==========================================================

 Title:      Queues
 Course:     CSC 2110
 Lab Number: Lab24
 Author:     Cayden Koweck
 Date:       12/14/2021
 Description:
	Queue implementation lab
===========================================================*/

#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <string> // For string data type
#include <iostream> // For cin, cout, and system

using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::setw;
using std::endl;

class Student {
	string firstName;
	string lastName;

public:
	void setFirstName(string f) {
		firstName = f;
	}
	void setLastName(string f) {
		lastName = f;
	}
	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}

	string fullName() {
		return firstName + " " + lastName;
	}

	Student(string f, string l) {
		firstName = f;
		lastName = l;
	}
	Student() {
		firstName = "Null";
		lastName = "Nullson";
	}

};

class Node {
public:
	Student data;
	Node* next;
	Node() {
		data = Student();
		next = nullptr;
	}
};

class Queue {
	int size;
	Node* first;
	Node* last;
public:

	//test if queue is empty
	const bool isEmpty() {
		return (first == nullptr && last == nullptr);
	}

	//return size of queue
	const int getSize() {
		return size;
	}

	//return the first element in the queue
	Student getFirst() {
		if (isEmpty()) throw (string)"The Queue is empty.";
		else return first->data;
	}

	//add an element to the end of the queue
	const void addElement(Student input) {

		if (isEmpty()) {
			first = new Node();
			last = first;
			last->data = input;
		}
		else {
			last->next = new Node();
			last = last->next;
			last->data = input;
		}
		size++;
	}

	//delete the first element in the queue
	void deleteElement() {
		if (isEmpty())
			throw (string)"Can't delete an element from an empty Queue";
		else if (size == 1) {
			delete first;
			first = nullptr;
			last = nullptr;
		}
		else {
			Node* temp = first->next;
			delete first;
			first = temp;
			size--;
		}
	}

	//default constructor
	Queue() {
		first = nullptr;
		last = nullptr;
		size = 0;
	}
};

int main() {

	//Console Header output
	cout << "\n***********************************************************";
	cout << "\n * Author:  Cayden Koweck";
	cout << "\n* AccessID : hd6247";
	cout << "\n* Date : 12 / 14 / 2021";
	cout << "\n* Program Information : L - 22 - Queues Cont";
	cout << "\n* **********************************************************\n\n";

	//Code Block

	Queue Class = Queue();

	Class.addElement(Student("Cayden", "Koweck"));
	Class.addElement(Student("Deric", "Tre"));
	Class.addElement(Student("Jasmine", "Dawkins"));

	try {
		cout << "Full list:\n";
		cout << Class.getFirst().fullName() << endl;
		Class.deleteElement();
		cout << Class.getFirst().fullName() << endl;
		Class.deleteElement();
		cout << Class.getFirst().fullName() << endl;
		Class.deleteElement();
	}
	catch (string e) {
		cout << endl << e << endl;
	}

	//Closing Statements
	cout << "\n\nEnd Of Application\n";
	return 0;
}
