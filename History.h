#include <iostream>
#include "DStructures.h"

using namespace std;

//identifying operation type
enum operationType {
	bookBorrowed = 1,
	bookReturned = 2,
	bookSearched = 3,
};

//operation struct
struct Operation {
	int operationType;
	static int operationID;
	int bookID;
	int personID;
};

int Operation::operationID = 0;

//class HistoryStack to store history
class HistoryStack : public Stack<Operation> {

	Node<Operation>* lastOperation;

public:
	HistoryStack() {
		lastOperation = nullptr;
	}

	~HistoryStack() {
		while (lastOperation != nullptr) {
			Node<Operation>* deletedOperation = lastOperation;
			lastOperation = lastOperation->next;
			delete deletedOperation;
		}
	}

	//push
	void addOperation(int operationType, int bookID, int personID) {
		Operation op;
		op.operationType = operationType;
		op.bookID = bookID;
		op.personID = personID;

		push(op);
		Operation::operationID++;
		cout << "Operation added to history successfully\n";
	}

	//pop
	void deleteLastOperation() {
		pop();
		Operation::operationID++;
		cout << "Last operation deleted from history successfully\n";
	}

	void seeLastOperation() {
		Operation lastOperation = peek();

		cout << "=== Last operation details ===\n";
		cout << "Operation type: " << lastOperation.operationType << endl;
		cout << "Operation ID: " << lastOperation.operationID;
		cout << "Book ID: " << lastOperation.bookID;
		cout << "Person ID: " << lastOperation.personID;
	} //peek

	bool isEmptyHistory() {
		return isEmpty();
	} //isEmpty

	void displayHistory() {} //NEEDS WORK
};