#include <iostream>
#include <vector>
using namespace std;

//node classes
class Node {
public:
    int info;
    Node *next;
    Node(int info) {
        this->info = info;
    }
    ~Node() {}
};
class DoubleNode: public Node {
    Node *prev;
};

//data structure classes
class Stack {

    Node *head;


    Stack() {
        head = nullptr;
    }

    void push(int info) {

        Node *temp = new Node(info);

        if (isEmpty() == true) {
            head = temp;
        }

        else if (isEmpty() == false) {

        }
    }
    void pop() {}
    void peek() {}
    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }
};
