#include <iostream>
#include <string>
#include "DStructures.h"

using namespace std;

struct Book {
	int bookID;
	string bookName;
	string bookAuthor;
	int yearPublished;
	bool isAvailable;
};

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