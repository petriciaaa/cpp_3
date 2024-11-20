#pragma once
#include "../../../src/classes/linkedList.h"
#include "../../../src/classes/linkedList.cpp"

class Stack {
private:
    LinkedList list;

public:
    void additem(int value) {
        list.additem(value);
    }

    int pop() {
        return list.pop();
    }

    void display()  {
        list.display();
    }
};
