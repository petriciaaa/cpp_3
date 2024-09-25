#pragma once
class Fraction {
private:
    int numerator;   
    unsigned int denominator; 

public:

    Fraction();

    Fraction(int numerator, int denominator);


    void display();

    Fraction addition(Fraction fraction);
    static Fraction addition(Fraction fraction1, Fraction fraction2);
    Fraction subtraction( Fraction fraction) ;
    Fraction multiplication( Fraction fraction) ;
    Fraction division( Fraction fraction) ;
    void reduce();
};