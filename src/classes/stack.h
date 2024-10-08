#include <iostream>


class Stack {
private:
    static const int MAX = 10;
    int st[MAX];
    int top;

public:
    Stack() {
        top = -1;
        for (auto& node : st)
        {
            node = NULL;
        }
    }

    void push(int value) {
            st[++top] = value;
    }

    int pop() {
            return st[top--];
    }
    bool isEmpty() {
        return top<0;
    }


};