#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* first;

public:
	LinkedList()
	{
		first = NULL;
	}
	void additem(int d);
	void display();
	int  pop();
};