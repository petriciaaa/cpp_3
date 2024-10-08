
#include <iostream>
#include <string>

using namespace std;


class Queue
{
	private:

		static const int MAX = 10;
		int qu[MAX];
		int head;
		int tail;
		int lenght;

	public:

		Queue() : head(0), tail(0) ,lenght(0){};
		
		void put(int val) {
			if (lenght == MAX) {
				cout << "Queue is full" << endl;
				return;
			}
			qu[tail] = val;
			tail = (tail + 1) % MAX;
			lenght += 1;
		}
		
		int get() {
			if (lenght == 0) {
				cout << "Queue is empty" << endl;
				return -1; 
			}
			int value = qu[head];
			//qu[head] = 0;
			head = (head + 1) % MAX;
			lenght -= 1;

			return value;

		}
		int getLenght() {
			return lenght;
		}
};


int main() {

	Queue qu1;
	
	for (int i = 0; i < 11; i++)
	{
		qu1.put((i + 1) * 10);
		cout << "Element " << (i+1)*10 << " added to queue. Lenght  " <<  qu1.getLenght()<< endl ;
	}

	cout << endl;

	int val;
	while ((val = qu1.get()) != -1)
	{
		cout << "Element " << val << " poped from queue " << endl;

	}
		




	return 0;
}