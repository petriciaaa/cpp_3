#pragma once
#include <iostream>

class stack_list {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    stack_list() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1; 
        }

        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

