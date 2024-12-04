#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

struct person
{
	int id;
	char lname[15];
	char name[15];
	float salary;
};

void read_f(const char*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* file = "list_2.txt";
	read_f(file);
}

void read_f(const char* file)
{
	int counter = 0, number;
	person pers;
	fstream employees;
	char symbol = ' ', yn = 'y';
	cout << "Список сотрудников из файла " << file << endl << endl;
	employees.open(file, ios::in | ios::_Nocreate);
	employees.read((char*)&pers, sizeof(pers));
	while (employees)
	{
		counter++;
		employees.read((char*)&pers, sizeof(pers));
	}
	employees.close();
	cout << "В файле " << counter << " записей\n\n";
	while (yn != 'n')
	{
		employees.open(file, ios::in | ios::_Nocreate);
		if (yn == 'y')
		{
			cout << "Введите номер записи: "; cin >> number; cout << endl;
			if (number == 1 or number == 2)
			{
				for (int i = 0; i < number; i++)
				{
					employees.read((char*)&pers, sizeof(pers));
				}
				cout << "Элемент списка № " << number << ":\n";
				cout << pers.id << symbol << pers.lname << symbol << pers.name << symbol
					<< setiosflags(ios::fixed) << setprecision(2) << pers.salary << endl << endl;
			}
			else cout << "Введен неверный номер!\n";
		}
		else cout << "Введен неверный символ!\n";
		cout << "Продолжаем просмотр записей? (y/n) "; cin >> yn;
		employees.close();
	}

	cout << endl << endl;
}