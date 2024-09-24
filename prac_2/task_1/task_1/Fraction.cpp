#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : numerator(0), denominator(1) {};

Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
};
void Fraction::display(){
    if (!numerator)
    {
        std::cout << 0<<std::endl;
        return;
    }
    if (denominator == 1) {
        std::cout << numerator <<std::endl;
        return;
    }
	std::cout << numerator << "/" << denominator<<std::endl;
};
/*
* Override of addition method
*/

Fraction Fraction::addition( Fraction fraction) {
	return Fraction(numerator * fraction.denominator + fraction.numerator * denominator, denominator * fraction.denominator);
};

 Fraction Fraction::addition( Fraction fraction1,Fraction fraction2) {
	return Fraction(fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator, fraction1.denominator * fraction2.denominator);
}; 

 /*
 */
Fraction Fraction::subtraction(Fraction fraction) {
	return Fraction(numerator * fraction.denominator - fraction.numerator * denominator, denominator * fraction.denominator);
};

Fraction Fraction::multiplication(Fraction fraction) {
	return Fraction(numerator * fraction.numerator , denominator * fraction.denominator);
};

Fraction Fraction::division(Fraction fraction) {
	return Fraction(numerator * fraction.denominator, denominator * fraction.numerator);
}; 

void Fraction::reduce() {
    int a = abs(numerator);
    int b = denominator;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    int gcd = a; 

    numerator /= gcd;
    denominator /= gcd;


};