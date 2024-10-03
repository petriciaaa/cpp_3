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

void Fraction::addition(Fraction fraction1, Fraction fraction2) {
    numerator = (fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator);
    denominator = (fraction1.denominator * fraction2.denominator);
    reduce();
};


void Fraction::subtraction(Fraction fraction1, Fraction fraction2) {
    numerator = (fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator);
    denominator = (fraction1.denominator * fraction2.denominator);
    reduce();
};

void Fraction::multiplication(Fraction fraction1, Fraction fraction2) {
    numerator = (fraction2.numerator * fraction1.numerator);
    denominator = (fraction1.denominator* fraction2.denominator);
    reduce();
};

void Fraction::division(Fraction fraction1, Fraction fraction2) {
    numerator = (fraction1.numerator * fraction2.denominator);
    denominator =  (fraction1.denominator* fraction2.numerator);
    reduce();

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