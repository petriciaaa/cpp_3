#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

void read(const char* file)
{
	ifstream myfile(file);
	cout << myfile.rdbuf() << endl << endl;
	myfile.close();
}
void write(const char* file1, const char* file2)
{
	ifstream Rfile(file2);
	ofstream Wfile(file1);
	Wfile << Rfile.rdbuf();
	Rfile.close();
	Wfile.close();
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const char* file = "list.txt", * file_1 = "list_1.txt";
	cout << "Начальный список...\n\n";
	read(file);
	cout << "Дополнительный список...\n\n";
	read(file_1);
	write(file, file_1);
	cout << "Обновленный список...\n\n";
	read(file);
}

