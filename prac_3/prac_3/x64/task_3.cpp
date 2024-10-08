
#include "stack.h"
using namespace std;
int main() {

	Stack stack;

	std::cout << "Add item in stack 25 " << endl;
	stack.additem(25);

	std::cout << "Add item in stack 35 " << endl;
	stack.additem(35);
	
	std::cout << "Add item in stack 45 " << endl;
	stack.additem(45);
	
	std::cout << "Add item in stack 55 " << endl;
	stack.additem(55);


	std::cout << "Stack elements: "<<endl;
	stack.display();
	
	int popped;
	while ((popped = stack.pop()))
	{
		std::cout << "Pop from stack: "<< popped << endl;
	}
	cout << endl;

	return 0;
}