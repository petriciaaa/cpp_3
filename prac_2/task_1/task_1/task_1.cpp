#include <iostream>
#include <string>
#include<windows.h>
#include <conio.h>
#include "Fraction.h" 

using namespace std;

int main()
{


	int num1 , num2, num3, num4;
	char oper1, oper2, calcChar;
    char key;

    while (true) {

        cout << "Enter operation, type is a/b + c/d " << endl;
        cin >> num1 >> oper1 >> num2 >> calcChar >> num3 >> oper2 >> num4;

        Fraction fraction1(num1,num2);
        Fraction fraction2(num3, num4);
        
        if (num2== 0 || num4 == 0)
        {
            return 0;
        }
          
        ///
        Fraction res;
        switch (calcChar)
        {
        case '+':
            res = fraction1.addition(fraction2); 
            /*
            * Overrided method call
            */
            //res = Fraction::addition(fraction1,fraction2);
            break;
        case '-':
            res = fraction1.subtraction(fraction2);  
            break;
        case '*':
            res = fraction1.multiplication(fraction2);  
            break;
        case '/':
            res = fraction1.division(fraction2);
            break;
        default:
            break;
        }
        res.reduce();
        res.display();

        cout << "Continue? (y/n)" << endl;

        key = _getch();
        if (key == 'n') {
            cout << endl;
            break;
        }
     
    }

    return 0;
}

