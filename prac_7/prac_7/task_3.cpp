#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;

void read(const char* file)
{
	ifstream in(file);
	cout << in.rdbuf() << endl << endl;
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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const char* file1 = "list.txt", * file2 = "list_1.txt";	
	cout << "Начальный список...\n\n";
	read(file1);
	cout << "Дополнительный список...\n\n";
	read(file2);
	write(file1, file2);
	cout << "Обновленный список...\n\n";
	read(file1);
}

