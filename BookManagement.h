#include <iostream>
#include "DStructures.h"

using namespace std;

class BookManagement {

	//Constructor
public:
	BookManagement() {}
	~BookManagement() {}

	void AddBook(int id, string name, string author, int year) { /*You can change parameters*/ }
	void DeleteBook(int id) { /*You can change parameters*/ }
	void Search(int id) { /*you can change parameters*/ }
	void Display() {}
	void Sort() {}

};

class Book: public Node {
	int id;
	string name;
	string author;
	int year;
	// you can add your book parameters
	Book *head;
	Book *next;
};

#pragma once