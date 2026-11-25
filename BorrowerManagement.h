#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Borrower {
	string name;
	string surname;
	int borrowedBookID;
};

class BorrowerManagement {
	//Constructor
public:
	BorrowerManagement() {}
	~BorrowerManagement() {};

	void addBorrower(string name, string surname, int borrowedBookID) { /*You can change parameters*/ }
	void searchBorrower(string name, string surname) { /*You can change parameters*/ }
	void displayBorrowers() {}
};