#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void read(const char* file)
{
	ifstream in(file);
	if (!in) {
		cout << "Ошибка открытия файла: " << file << endl;
		return;
	}
	cout << in.rdbuf() << endl ;
	in.close();

}
void write(const char* file1, const char* file2)
{
	ifstream in(file2);
	ofstream out(file1, ios::app);
	out << in.rdbuf();
	in.close();
	out.close();
}


struct Employe {

	string name;
	string lastName;
	int id;
	float salary;

	string getFullInfo() {
		return to_string(id) + " " + lastName + " " + name + " " + to_string(salary) + "\n";
	}
};

void writeEmployeInFile( const char* file) {
	Employe employe;

	cout << "Номер: "; cin >> employe.id;
	cout << "Фамилия: "; cin >> employe.lastName;
	cout << "Имя "; cin >> employe.name;
	cout << "Зарплата: "; cin >> employe.salary;
	
	ofstream out(file, ios::app);
	out << employe.getFullInfo();

	out.close();
}

void writeEmployeInFile( const char* to, const char* from) {
		cout << "Будет записано:\n\n";
		read(from);
		write(to, from);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const char* file = "list.txt";
	cout << "Начальный список из list.txt...\n\n";

	read(file);
	char yn = 'y';

	while (yn != 'n'){
		int option;
		cout << "Выберите вариант ввода данных\n" << "1 - с экрана; 2 - из файла:";
		cin >> option;

		if (option == 1){
			writeEmployeInFile(file);
		}
		else if (option == 2){
			string fileName;
			cout << "Введите имя файла: ";
			cin >> fileName;
			writeEmployeInFile(file, fileName.c_str());
			
		}
		cout << "Обновленный список...\n\n";
		read(file);
		cout << "Продолжим? (y/n) "; 
		cin >> yn;
	}
}

