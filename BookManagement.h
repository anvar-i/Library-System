#pragma once
#include <iostream>
#include <string>
#include "DStructures.h"
using namespace std;

class Book : public Node {
public:
	int id;
	string name;
	string author;
	int year;
	bool available;
	Book* head;
	Book* next;

	Book(int id, string name, string author, int year) {
		this->id = id;
		this->name = name;
		this->author = author;
		this->year = year;
		this->available = true;
		this->head = nullptr;
		this->next = nullptr;
	}
};

class BookManagement {
	Book* first;

	void Print(Book* b) {
		cout << b->id << " | " << b->name << " | " << b->author << " | "
			<< b->year << " | " << (b->available ? "Available" : "Issued") << endl;
	}

	void SwapData(Book* a, Book* b) {
		swap(a->id, b->id);
		swap(a->name, b->name);
		swap(a->author, b->author);
		swap(a->year, b->year);
		swap(a->available, b->available);
	}

public:
	BookManagement() { first = nullptr; }

	~BookManagement() {
		while (first != nullptr) {
			Book* temp = first;
			first = first->next;
			delete temp;
		}
	}
	Book* Find(int id) {
		Book* cur = first;
		while (cur != nullptr) {
			if (cur->id == id) return cur;
			cur = cur->next;
		}
		return nullptr;
	}
	void AddBook(int id, string name, string author, int year) {
		if (id <= 0 || year < 0 || name.empty() || author.empty()) {
			cout << "Error: invalid data." << endl;
			return;
		}
		if (Find(id) != nullptr) {
			cout << "Error: book with this ID already exists." << endl;
			return;
		}
		Book* b = new Book(id, name, author, year);
		if (first == nullptr) {
			first = b;
		}
		else {
			Book* cur = first;
			while (cur->next != nullptr) cur = cur->next;
			cur->next = b;
		}
		cout << "Book added." << endl;
	}
	void DeleteBook(int id) {
		if (first == nullptr) {
			cout << "Error: list is empty." << endl;
			return;
		}
		Book* prev = nullptr;
		Book* cur = first;
		while (cur != nullptr && cur->id != id) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == nullptr) {
			cout << "Error: book not found." << endl;
			return;
		}
		if (!cur->available) {
			cout << "Error: book is issued, cannot delete." << endl;
			return;
		}
		if (prev == nullptr) first = cur->next;
		else prev->next = cur->next;
		delete cur;
		cout << "Book deleted." << endl;
	}


	void Search(int id) {
		Book* b = Find(id);
		if (b == nullptr) cout << "Book not found." << endl;
		else Print(b);
	}
	void Display() {
		if (first == nullptr) {
			cout << "No books." << endl;
			return;
		}
		for (Book* cur = first; cur != nullptr; cur = cur->next)
			Print(cur);
	}
	void Sort(bool byId) {
		if (first == nullptr || first->next == nullptr) return;
		bool swapped;
		do {
			swapped = false;
			for (Book* cur = first; cur->next != nullptr; cur = cur->next) {
				bool wrongOrder = byId ? (cur->id > cur->next->id)
					: (cur->name > cur->next->name);
				if (wrongOrder) {
					SwapData(cur, cur->next);
					swapped = true;
				}
			}
		} while (swapped);
		cout << "Sorted." << endl;
	}
};