#include <iostream>
#include <string>

using namespace std;

#pragma once

class BorrowerManagement {
	//Constructor
public:
	BorrowerManagement() {}
	~BorrowerManagement() {};

	void addBorrower(string name, string surname, int borrowedBookID) { /*You can change parameters*/ }
	void searchBorrower(string name, string surname) { /*You can change parameters*/ }
	void displayBorrowers() {}
};

class Borrower: public DoubleNode {
	string name;
	string surname;
	int borrowedBookID;
	Borrower *next;
	Borrower *prev;
};
