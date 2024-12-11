#include "linkedList.h"
using namespace std;



class Queue: public LinkedList {

	public: void addItem(int value)  {
        Node* newNode = new Node();
        newNode->value = value;
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next; 
            }
            current->next = newNode;
        }
	}

};