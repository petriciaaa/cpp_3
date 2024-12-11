#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;


struct Employe {

	string name;
	string lastName;
	int id;
	float salary;

	string getFullInfo() {
		return to_string(id) + " " + lastName + " " + name + " " + to_string(salary) + "\n";
	}
};

void findEmploye(const char*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* file = "list_2.txt";
	findEmploye(file);
}

void findEmploye(const char* file)
{
	int count = 0, employeID = -1;

	fstream fs;
	char yn='y';

	fs.open(file, ios::in );
	Employe employe;
	while (fs >> employe.id >> employe.lastName >> employe.name >> employe.salary)
	{
		count++;
	}
	fs.close();
	cout << "Всего записей: " << count << endl;

	while (yn != 'n'){

		fs.open(file, ios::in );
		
		cout << "Введите номер записи(id): ";
		cin >> employeID; 
			
		for (int i = 0; i < employeID; i++){
			fs >> employe.id >> employe.lastName >> employe.name >> employe.salary;
		}
		cout << "\nНомер: " << employeID << ":\n";
		
		cout << employe.getFullInfo();
		
		fs.close();
		cout << "Продолжаем? (y/n) "; cin >> yn;
	
	}

	cout << endl << endl;
}