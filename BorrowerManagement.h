#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "DStructures.h"

using namespace std;

// Borrower Information
struct Borrower {
    string name;
    string surname;
    int PersonID;
    int borrowedBookID;
};

//Borrower Management System
class BorrowerManagement {

    DoubleNode<Borrower>* head;
    DoubleNode<Borrower>* tail;
    DoubleNode<Borrower>* last_borrowed;
    int size;

    // Convert inherited Node pointer to DoubleNode pointer
    DoubleNode<Borrower>* nextNode(DoubleNode<Borrower>* node) {
        if (node == nullptr) return nullptr;

        return static_cast<DoubleNode<Borrower>*>(node->next);
    }

    // Display one borrowing record
    void printRecord(DoubleNode<Borrower>* node) {

        if (node == nullptr)
            return;

        cout << "\nBorrower Information\n";
        cout << "--------------------\n";

        cout << "Name: " << node->info.name << endl;
        cout << "Surname: " << node->info.surname << endl;
        cout << "Person ID: " << node->info.PersonID << endl;
        cout << "Book ID: " << node->info.borrowedBookID << endl;
    }


    // Calculate number of unique PersonIDs
    int uniqueBorrowers() {

        int uniqueCount = 0;
        DoubleNode<Borrower>* current = head;

        while (current != nullptr) {
            bool alreadyExists = false;
            DoubleNode<Borrower>* previous = head;

            while (previous != current) {
                if (previous->info.PersonID == current->info.PersonID) {
                    alreadyExists = true;
                    break;
                }
                previous = nextNode(previous);
            }

            if (!alreadyExists) uniqueCount++;
            current = nextNode(current);
        }
        return uniqueCount;
    }

    // Display table border
    void printBorder(int w1, int w2, int w3, int w4) {

        cout << "+";

        cout << string(w1 + 2, '-') << "+";
        cout << string(w2 + 2, '-') << "+";
        cout << string(w3 + 2, '-') << "+";
        cout << string(w4 + 2, '-') << "+" << endl;
    }
public:
    // Constructor
    BorrowerManagement() {

        head = nullptr;
        tail = nullptr;
        last_borrowed = nullptr;

        size = 0;
    }
    // Destructor
    ~BorrowerManagement() {

        DoubleNode<Borrower>* current = head;
        while (current != nullptr) {
            DoubleNode<Borrower>* next = nextNode(current);
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        last_borrowed = nullptr;
        size = 0;
    }


    // Prevent shallow copies of linked-list
    BorrowerManagement(const BorrowerManagement&) = delete;
    BorrowerManagement& operator=(const BorrowerManagement&) = delete;


    // Add borrower
    void addBorrower(string name, string surname, int borrowedBookID, int PersonID) {

        Borrower newBorrower;
        newBorrower.name = name;
        newBorrower.surname = surname;
        newBorrower.PersonID = PersonID;
        newBorrower.borrowedBookID = borrowedBookID;

        DoubleNode<Borrower>* newNode = new DoubleNode<Borrower>(newBorrower);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }

        // Non-empty list
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        // Update last borrowing record
        last_borrowed = newNode;
        size++;
    }

    // Display the last borrowing record of a specific person
    void lastBorrower(int PersonID) {
        DoubleNode<Borrower>* current = tail;

        while (current != nullptr) {
            if (current->info.PersonID == PersonID) {
                printRecord(current);
                return;
            }
            current = current->prev;
        }
        cout << "No borrowing records found for Person ID: " << PersonID << endl;
    }

    // Display the globally last borrowing record
    void lastBorrower() {

        if (last_borrowed == nullptr) {
            cout << "No borrowing records available.\n";
            return;
        }

        printRecord(last_borrowed);
    }

    // Search by PersonID
    // Returns the first matching node
    DoubleNode<Borrower>* getBorrower(int PersonID) {

        DoubleNode<Borrower>* current = head;
        while (current != nullptr) {
            if (current->info.PersonID == PersonID) return current;
            current = nextNode(current);
        }
        return nullptr;
    }

    // Search by PersonID and BookID
    DoubleNode<Borrower>* getBorrower(int PersonID, int borrowedBookID) {

        DoubleNode<Borrower>* current = head;
        while (current != nullptr) {

            if (current->info.PersonID == PersonID && current->info.borrowedBookID == borrowedBookID) return current;
            current = nextNode(current);
        }
        return nullptr;
    }

    // Display all books borrowed by a specific person
    void displayBorrower(int PersonID) {
        DoubleNode<Borrower>* current = head;
        bool found = false;

        cout << "\nBorrowing Records for Person ID: " << PersonID << endl;
        cout << "----------------------------------\n";
        while (current != nullptr) {
            if (current->info.PersonID == PersonID) {
                if (!found) {
                    cout << "Name: " << current->info.name << endl;
                    cout << "Surname: " << current->info.surname << endl;
                    cout << "\nBorrowed Books:\n";
                }
                cout << "- Book ID: " << current->info.borrowedBookID << endl;
                found = true;
            }
            current = nextNode(current);
        }

        if (!found) cout << "No borrowing records found.\n";
    }

    // Display one specific borrowing record
    void displayBorrower(int PersonID, int borrowedBookID) {
        DoubleNode<Borrower>* result = getBorrower(PersonID, borrowedBookID);

        if (result == nullptr) {
            cout << "Borrowing record not found.\n";
            return;
        }
        printRecord(result);
    }

    // Return book
    // All four fields must match before deletion
    bool returnBook(
        string name,
        string surname,
        int PersonID,
        int borrowedBookID
    ) {
        DoubleNode<Borrower>* current = head;
        while (current != nullptr) {
            if (
                current->info.name == name &&
                current->info.surname == surname &&
                current->info.PersonID == PersonID &&
                current->info.borrowedBookID == borrowedBookID) {
                // Reassign previous node
                if (current->prev != nullptr) { current->prev->next = current->next; }
                else head = nextNode(current);

                // Reassign next node
                DoubleNode<Borrower>* next = nextNode(current);
                if (next != nullptr) next->prev = current->prev;
                else tail = current->prev;

                // Update last borrowing pointer
                last_borrowed = tail;
                // Delete node
                delete current;
                size--;
                return true;
            }
            current = nextNode(current);
        }
        return false;
    }

    // Display all borrowers in a dynamically sized table
    void displayBorrowers() {
        if (head == nullptr) {
            cout << "\nNo borrowers available.\n";
            return;
        }
        // Minimum column widths
        int w1 = 4;   // Name
        int w2 = 7;   // Surname
        int w3 = 9;   // Person ID
        int w4 = 7;   // Book ID

        // Calculate required column widths
        DoubleNode<Borrower>* current = head;

        while (current != nullptr) {
            if (current->info.name.length() > w1) w1 = current->info.name.length();

            if (current->info.surname.length() > w2) w2 = current->info.surname.length();

            if (to_string(current->info.PersonID).length() > w3) w3 = to_string(current->info.PersonID).length();

            if (to_string(current->info.borrowedBookID).length() > w4) w4 = to_string(current->info.borrowedBookID).length();

            current = nextNode(current);
        }

        // Display statistics
        cout << "\n========================================\n";
        cout << "Total borrowing records: " << size << endl;
        cout << "Unique borrowers: " << uniqueBorrowers() << endl;
        cout << "========================================\n\n";

        // Table header
        printBorder(w1, w2, w3, w4);
        cout << "| " << left << setw(w1) << "Name" << " | " << left << setw(w2) << "Surname" << " | " << left << setw(w3) << "Person ID" << " | " << left << setw(w4) << "Book ID" << " |" << endl;
        printBorder(w1, w2, w3, w4);
        // Display records
        current = head;
        while (current != nullptr) {
            cout << "| " << left << setw(w1) << current->info.name << " | " << left << setw(w2) << current->info.surname << " | " << left << setw(w3) << current->info.PersonID << " | " << left << setw(w4) << current->info.borrowedBookID << " |" << endl;
            current = nextNode(current);
        }
        printBorder(w1, w2, w3, w4);
    }
    // Get total borrowing records
    int getSize() { return size; }

    // Check whether list is empty
    bool isEmpty() { return head == nullptr; }
};