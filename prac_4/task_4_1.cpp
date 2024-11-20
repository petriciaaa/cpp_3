#include <iostream> 
#include "Windows.h"  
#include <string> 
using namespace std;

class Time24 {
public:
    int hours;    
    int minutes; 

    Time24() : hours(0), minutes(0) {}  

    void display() const {  
        cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }
};

class Time12 {
public:
    int hours;   
    int minutes; 
    string period; 
    Time12() : hours(0), minutes(0), period("a.m.") {} 

    void display() const { 
        cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;
    }

    void fromTime24(const Time24& t24) {  
        minutes = t24.minutes;

        if (t24.hours == 0) {
            hours = 12;
            period = "a.m.";
        }
        else if (t24.hours == 12) {
            hours = 12;
            period = "p.m.";
        }
        else if (t24.hours < 12) {
            hours = t24.hours;
            period = "a.m.";
        }
        else {
            hours = t24.hours - 12;
            period = "p.m.";
        }
    }
};

int main() {
    Time24 t24;
    Time12 t12;
    char ch;
    SetConsoleOutputCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Enter time in 24 hours format: ";
    cin >> t24.hours >> ch >> t24.minutes;
    t12.fromTime24(t24);
    // Вывод результатов 
    cout << "24-hours format: ";
    t24.display();
    cout << "12-hours format: ";
    t12.display();
}
