#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

const char* FIRST_FILE = "task_18_2_1.txt";
const char* SECOND_FILE = "task_18_2_2.txt";
const char* INDEX_FILE = "task_18_2_3.txt";
const int LEN = 5;


void write(int arr[LEN][3], const char* file){
	
	ofstream out(file);
	
	for (int k = 0; k < 3; k++){
		for (int i = 0; i < LEN; i++){
			out << arr[i][k] << " ";
		}
		out << endl;
	}
	
	out.close();

}


void read(int arr[], const char* file) {

	ifstream in(file);

	for (int i = 0; i < LEN; i++) {
		in >> arr[i];
	}

	in.close();
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int arr1[LEN];
	int arr2[LEN];
	int arr3[LEN][3];

	read(arr1, FIRST_FILE);
	cout << "������ ������ ������ �� ����� task_18_2_1.txt"  << endl;
	
	for (int i = 0; i < LEN; i++) {
		cout << arr1[i] << " ";
	}
	
	read(arr2, SECOND_FILE);
	cout << "\n������ ������ ������ �� ����� task_18_2_2.txt" << endl;
	
	for (int i = 0; i < LEN; i++){
		cout << arr2[i] << " "; 
	}

	for (int k = 0; k < 3; k++){
		for (int i = 0; i < LEN; i++){
			switch (k) {
				case 0:
					arr3[i][k] = arr1[i] + arr2[i];
					break;
				case 1:
					arr3[i][k] = arr1[i] - arr2[i];
					break;
				case 2:
					arr3[i][k] = arr1[i] * arr2[i];
					break;
				default:
					arr3[i][k] = 0;
			}
		}
	}


	cout << endl;
	cout << "�������������� ������\n";

	for (int k = 0; k < 3; k++){
		for (int i = 0; i < LEN; i++){
			cout << arr3[i][k] << " ";
		}
		cout << endl;
	}

	write(arr3, INDEX_FILE);

	cout << "�������������� ������ ������� � ���� task_18_2_3.txt\n";
	ifstream in(INDEX_FILE);

	cout << "�������������� ������ ������ �� ����� task_18_2_3.txt\n";
	cout << in.rdbuf();

	return 0;
}