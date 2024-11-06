

#include "Stack.h"

class queue_list : public stack_list {
private:

    stack_list stack1;
    stack_list stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }

        return stack2.pop();
    }


};

