#include <iostream>
#include <string>
#include <vector>
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
	string bookName;
	int bookID;
	string personName;
};

int Operation::operationID = 0;

//class HistoryStack to store history
class HistoryStack {

	vector<Operation> history;

	HistoryStack() {}
	~HistoryStack() {}

	//push
	void addOperation(int operationType, string bookName, int bookID, string personName) {
		Operation op;
		op.operationType = operationType;
		op.bookName = bookName;
		op.bookID = bookID;
		op.personName = personName;

		history.push_back(op);
		Operation::operationID++;
	}

	//pop
	void deleteLastOperation() {
		
	}
	void seeLastOperation() {} //peek
	void isEmptyHistory() {} //isEmpty
	void displayHistory() {} //NEEDS WORK
};

//history = {operationType, operationID, bookName, bookID, personName}