#pragma once
#include <iostream>

using namespace std;

//node classes
template <typename T>
class Node {
public:
    T info;
    Node<T> *next;

    Node(T info) {
        this->info = info;
        this->next = nullptr;
    }
    ~Node() {}
};

template <typename T>
class DoubleNode: public Node<T> {
public:
    Node<T> *prev;
};

//data structure classes
template <typename T>
class Stack {

    Node<T> *top;

public:

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node<T> *deletedNode = top;
            top = top->next;
            delete deletedNode;
        }
    };

    void push(T info) {
        Node<T> *temp = new Node<T>(info);

        if (isEmpty()) {
            top = temp;
        } //for empty stack

        else if (!isEmpty()) {
            Node<T> *cur = top;
            top = temp;
            top->next = cur;
        } //for non-empty stack

    }

    void pop() {

        if (isEmpty()) {
            cout << "Cannot pop. Stack is empty\n";
        } //for empty stack

        if (!isEmpty()) {

            Node<T> *deletedNode = top;
            top = top->next;
            delete deletedNode;
        } //for non-empty stack
    }

    T peek() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        } //for empty stack

        return top->info; //for non-empty stack
    }

    bool isEmpty() {
        if (top == nullptr) return true;
        return false;
    }
};
