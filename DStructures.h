#include <iostream>
using namespace std;

//node classes
class Node {
public:
    int info;
    Node *next;
    Node(int info) {
        this->info = info;
        this->next = nullptr;
    }
    ~Node() {}
};
class DoubleNode: public Node {
    Node *prev;
};

//data structure classes
class Stack {

    Node *top;

public:

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node *deletedNode = top;
            top = top->next;
            delete deletedNode;
        }
    };

    void push(int info) {
        Node *temp = new Node(info);

        if (isEmpty()) {
            top = temp;
        } //for empty stack

        else if (!isEmpty()) {
            Node *cur = top;
            top = temp;
            top->next = cur;
        } //for non-empty stack

    }

    void pop() {

        if (isEmpty()) {
            cout << "Cannot pop. Stack is empty\n";
        } //for empty stack

        if (!isEmpty()) {

            Node *deletedNode = top;
            top = top->next;
            delete deletedNode;
        } //for non-empty stack
    }

    int peek() {
        if (isEmpty()) {
            return -1;

        } //for empty stack

        return top->info; //for non-empty stack
    }

    bool isEmpty() {
        if (top == nullptr) return true;
        return false;
    }
};
