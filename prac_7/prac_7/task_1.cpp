#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "fs.h"

const char* FIRST_FILE = "F101.txt";
const char* SECOND_FILE = "F123.txt";
const char* THIRD_FILE = "F134.txt";
const char* FOURTH_FILE = "F135.txt";
const char* INDEX_FILE = "Уралсиб.txt";

int main()
{
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	FileStream file(FIRST_FILE, INDEX_FILE);
	cout << "Файл " << FIRST_FILE << " записан в файл " << INDEX_FILE << endl;
	file.rewrite();
	file.read(SECOND_FILE);
	cout << "Файл " << SECOND_FILE << " записан в файл " << INDEX_FILE << endl;
	file.rewrite();
	file.read(THIRD_FILE);
	cout << "Файл " << THIRD_FILE << " записан в файл " << INDEX_FILE << endl;
	file.rewrite();
	file.read(FOURTH_FILE);
	cout << "Файл " << FOURTH_FILE << " записан в файл " << INDEX_FILE << endl;
	file.rewrite();
	_getche();
	return 0;
}