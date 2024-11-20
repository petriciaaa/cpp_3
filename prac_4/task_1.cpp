#include <iostream>    
#include "Windows.h"   
#include "fraction.h"
#include <conio.h>
using namespace std;


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, c, d;
    char ch, oper;
 

    while (true) {
        char key;
        cout << "Enter operation, type is a/b + c/d " << endl;

        cin >> a >> ch >> b >> oper >> c >> ch >> d;
        Fraction f1(a, b), f2(c, d);
        Fraction result;

        switch (oper) {
        case '+':
            result = f1 + f2;

            break;
        case '-':
            result = f1 - f2;
            break;
        case '*':
            result = f1 * f2;
            break;
        case '/':
            result = f1 / f2;
            break;
        }

        cout << "Result : " << endl;
        result.display();

        cout << "Continue? (y/n)" << endl;

        key = _getch();
        if (key == 'n') {
            cout << endl;
            break;
        }

    }
}

