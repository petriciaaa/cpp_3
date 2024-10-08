
#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;



void LinkedList::additem(int d) {
	Node* newLink = new Node;
	newLink->data = d;
	newLink->next = first;
	first = newLink;

}void LinkedList::display() {
	Node* current = first;
	while (current)
	{
		cout << current->data<<endl;
		current = current->next;
	}
}
int  LinkedList::pop() {
	if (first == NULL) {
		cout << "Error: stack is empty";
		return NULL;
	}
	int value = first->data;
	Node* temp = first;
	first = first->next;
	delete temp;
	return value;
}