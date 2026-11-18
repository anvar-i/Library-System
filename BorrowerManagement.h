#include <iostream>
using namespace std;

#pragma once

class BorrowerManagement {
	//Constrictor
public:
	BorrowerManagement() {

	}

	void addBorrower(String name, String surname, int idOfBorrowedBook) { // you can change parameters

	}

	void searchBorrower(String name, String Surname) { // you can change parameters

	}

	void displayBorrowers() {

	}

	~BorrowerManagement() {};

};

class Borrower {
	String name;
	String surname;
	int idOfBorrowedDook;
	*Borrower next;
	*Borrower prev;
}
