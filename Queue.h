#pragma once
#include <iostream>
using namespace std;

class Student {
public:
	Student* next;
	int studentID;
};
class Queue {
public:
	Student* head;
	Student* rear;

	Queue() {
		head = nullptr;
		rear = nullptr;
	}


	bool isEmpty() {
		return head == nullptr;
	}

	void enqueue(int id) {
		Student* st = new Student;
		st->studentID = id;
		st->next = nullptr;
		if (isEmpty()) {
			head = rear = st;
		}
		else {
			rear->next = st;
			rear = st;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Underflow" << endl;
		}
		else {
			Student* deleted = head;
			cout << "Deleted student: " << deleted->studentID << endl;
			deleted = nullptr;
			head = head->next;
		}
	}

	void front() {
		cout << "Front: " << head->studentID << endl;
	}

	void displayQueue() {
		Student* current = head;
		cout << current->studentID << "->";
		while (current != rear) {
			current = current->next;
			cout << current->studentID << "->";
		}
	}
};
