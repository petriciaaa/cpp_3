#include <iostream>    
#include "Windows.h"   
using namespace std;
class Fraction {
private:
    int P, Q;
    void reduce(); 
public:
    Fraction() {               
        P = 0; 
        Q = 1;  
    }
    Fraction(int A, int B) {        
        
            P = A;
            Q = B;
    }
    void display() const;
    Fraction operator +(const Fraction& fr) const; 
    Fraction operator -(const Fraction& fr) const;
    Fraction operator *(const Fraction& fr) const;
    Fraction operator /(const Fraction& fr) const;

};

void Fraction::display() const { 
    if (!P)
    {
        std::cout << 0 << std::endl;
        return;
    }
    if (Q == 1) {
        std::cout << P << std::endl;
        return;
    }
    std::cout << P << "/" << Q << std::endl;
}


void Fraction::reduce() {
    int a = abs(P);
    int b = Q;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    int gcd = a;

    P /= gcd;
    Q /= gcd;
}

Fraction Fraction::operator +(const Fraction& fr) const {   
    Fraction res;                                         
    res.P = P * fr.Q + Q * fr.P;
    res.Q = Q * fr.Q;
    res.reduce();
    return res;
}

Fraction Fraction::operator -(const Fraction& fr) const { 
    Fraction res;
    res.P = P * fr.Q - Q * fr.P;
    res.Q = Q * fr.Q;
    res.reduce();
    return res;
}

Fraction Fraction::operator *(const Fraction& fr) const {
    Fraction res;
    res.P = P * fr.P;
    res.Q = Q * fr.Q;
    res.reduce();
    return res;
}

Fraction Fraction::operator /(const Fraction& fr) const { 
   
    Fraction res;
    res.P = P * fr.Q;
    res.Q = Q * fr.P;
    res.reduce();
    return res;
}
