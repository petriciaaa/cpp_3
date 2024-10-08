
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	float salary;

public:
	
	void setData() {
		cout << "Enter name:"; cin>> name;
		cout << "Enter salary (rub):"; cin>> salary;
	};
	void printData() {
		cout <<name<< " : " << salary<<" rub " << endl;

	};
	float getSalary() {
		return salary;
	};


};


int main()
{
	void bubleSort(Person**, int n);

	int n;
	cout << "Enter count of employers: ";
	cin >> n;

	Person** persPtr = new Person * [n];

	for (int i = 0; i < n; i++)
	{
		persPtr[i] = new Person;
		persPtr[i] -> setData();

	}
	cout << endl;

	cout << "\nNon sorted list:"<<endl;
	for (int i = 0; i < n; i++)
	{
		persPtr[i]->printData();
	}

	bubleSort(persPtr, n);

	cout << endl;cout << "\nSorted list:" << endl;
	for (int j = 0; j < n; j++)
	{
		persPtr[j]->printData();
	}

	cout << endl;


}

void bubleSort(Person** pp, int n) {
	void order(Person**, Person**);

	for (int j = 0; j < n - 1; j++)
	{
		for (int k = j+1; k < n; k++){
			order(pp + j, pp + k);
		}
	}
}
void order(Person** pp1, Person** pp2) {
	if ((*pp1)->getSalary() > (*pp2)->getSalary())
	{
		Person* temp = *pp1;
		*pp1 = *pp2;
		*pp2 = temp;
	}
}