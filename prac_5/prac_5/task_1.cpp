// main.cpp
#include <iostream>
#include "Queue.h"

int main() {
    queue_list q;

    std::cout << "Add: 25"<<std::endl;
    q.enqueue(25);
    std::cout << "Add: 36" << std::endl;
    q.enqueue(36);
    std::cout << "Add: 49" << std::endl;
    q.enqueue(49);

    std::cout << "Dequeued: " << q.dequeue() << std::endl; 
    
    std::cout << "Add: 64" << std::endl;
    q.enqueue(64);

    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    q.dequeue();

    return 0;
}
