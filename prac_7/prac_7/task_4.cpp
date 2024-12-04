#include <conio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

void read(const char*);
void write(const char*, const char*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* file = "list.txt";
	cout << "Начальный список...\n\n";
	read(file);
	char yn = 'y';
	while (yn != 'n')
	{
		int x;
		char* data;
		string str;
		if (yn == 'y')
		{
			cout << "Выберите вариант ввода данных:  1 - с экрана\n" << "				2 - из файла: ";
			cin >> x;
			if (x == 1)
			{
				string lastname, name, number, salary;
				cout << "Введите номер сотрудника: "; cin >> number;
				cout << "Введите фамилию сотрудника: "; cin >> lastname;
				cout << "Введите имя сотрудника: "; cin >> name;
				cout << "Введите оклад сотрудника: "; cin >> salary;
				str = number + " " + lastname + " " + name + " " + salary + "\n";
				ofstream Wfile(file, ios::app);
				Wfile << str;
				Wfile.close();
			}
			else if (x == 2)
			{
				cout << "Введите имя файла: ";
				cin >> str;
				const char* file_1 = str.c_str();
				cout << "Дополнительный список...\n\n";
				read(file_1);
				write(file, file_1);
			}
			cout << "Обновленный список...\n\n";
			read(file);
		}
		cout << "Продолжаем ввод? (y/n) "; cin >> yn;
	}
}

void read(const char* file)
{
	ifstream myfile(file);
	cout << myfile.rdbuf() << endl << endl;
	myfile.close();
}
void write(const char* file1, const char* file2)
{
	ifstream Rfile(file2);
	ofstream Wfile(file1, ios::app);
	Wfile << Rfile.rdbuf();
	Rfile.close();
	Wfile.close();
}