#include <iostream>
#include <string>
#include "../../../src/classes/queue.h"

using namespace std;

int main() {

	Queue queue;

	std::cout << "Add item in queue 25 " << endl;
	queue.push(25);

	std::cout << "Add item in queue 35 " << endl;
	queue.push(35);

	std::cout << "Add item in queue 45 " << endl;
	queue.push(45);

	std::cout << "Add item in queue 55 " << endl;
	queue.push(55);


	std::cout << "Pop from queue: " << queue.pop() << endl;

	std::cout << "Add item in queue 65 " << endl;
	queue.push(65);

	std::cout << std::endl;

	int popped;
	while ((popped = queue.pop()))
	{
		std::cout << "Pop from queue: " << popped << endl;
	}
	cout << endl;

	return 0;
}