
#include <string>

using namespace std;

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

};

void LinkedList::additem(int d) {
	Node* newLink = new Node;
	newLink->data = d;
	newLink->next = first;
	first = newLink;

}void LinkedList::display() {
	Node* current = first;
	while (current)
	{
		cout << current->data;
		current = current->next;
	}
}