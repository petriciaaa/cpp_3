#pragma once
class Fraction {
private:
    int numerator;   
    unsigned int denominator; 
    void reduce();

public:

    Fraction();

    Fraction(int numerator, int denominator);


    void display();

    void addition(Fraction fraction1, Fraction fraction2);
    void subtraction(Fraction fraction1, Fraction fraction2) ;
    void multiplication(Fraction fraction1, Fraction fraction2) ;
    void division( Fraction fraction1, Fraction fraction2 ) ;
};