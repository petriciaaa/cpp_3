#include <iostream>
#include <windows.h>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class LinkedList {

	protected: Node* head;

	public: LinkedList() {
		this->head = NULL;
	}
	public: int pop() {
		if (!head) {
			
			return -1; 
		}

		if (!head->next) { 
			int value = head->value;
			delete head;
			head = NULL;
			return value; 
		}

		Node* current = head;
		while (current->next && current->next->next) {
			current = current->next;
		}

		int value = current->next->value;
		delete current->next;
		current->next = NULL;

		return value; 
	}

	 public: void addItem(int value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		head = newNode;
	}
	
	public: void display() {
		Node* current = head;
		while (current) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
};