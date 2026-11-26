#include <iostream>
#include "./History.h"
#include "./BookManagement.h"
#include "./BorrowerMAnagement.h"
#include "./Queue.h"
using namespace std;
#include <string>
int main() {
	int choice;
	do {
		cout << "=== MENU ===" << endl;
		cout << "1. Book Management\n";
		cout << "2. Borrower Management \n";
		cout << "3. Borrow/Return queue \n";
		cout << "4. Waiting queue \n";
		cout << "5. Borrowing history \n";
		cout << "6. Library Inventory \n";
		cout << "0. EXIT \n";
		cout << "\n ================================== \n Enter your choice: ";
		cin >> choice; 
		switch (choice) {
		case 1:
			int choice1;
			do {
				cout << "1. Add book \n";
				cout << "2. Delete book \n ";
				cout << "3. Search book \n";
				cout << "4. Display books \n";
				cout << "5. Sort books \n";
				cout << "0. Back";
				cin >> choice1;
				switch (choice1) {
				case 1: 
					break;
				case 2: 
					break;
				}
			} while (choice1 != 0);
			break;
		case 2:
			break;
		case 3:
			break; 

		}
	} while (choice != 0);

	
	cout << "6. Add borrower \n";
	cout << "7. Search borrower \n";
	cout << "8. Display borrower \n";
	cout << "9. Add to the queue \n"; 
	cout << "10. Delete from the queue \n";
	cout << "11. Show"

	return 0;
}

