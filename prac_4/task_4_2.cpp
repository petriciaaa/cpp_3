#include <iostream> 
#include "Windows.h"  
#include <string> 
using namespace std;

class Time12 {
public:
    int hours;    
    int minutes;  
    string period; 

    Time12() : hours(0), minutes(0), period("a.m.") {}

    void display() const { 
        cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;
    }
};

class Time24 {
public:
    int hours;   
    int minutes; 

    Time24() : hours(0), minutes(0) {}

    void display() const { 
        cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }

    Time12 toTime12() const {
        Time12 t12;
        t12.minutes = minutes;

        if (hours == 0) {
            t12.hours = 12;
            t12.period = "a.m.";
        }
        else if (hours == 12) {
            t12.hours = 12;
            t12.period = "p.m.";
        }
        else if (hours < 12) {
            t12.hours = hours;
            t12.period = "a.m.";
        }
        else {
            t12.hours = hours - 12;
            t12.period = "p.m.";
        }

        return t12;
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

    t12 = t24.toTime12();

    cout << "24-hours format: ";
    t24.display();
    cout << "12-hours format: ";
    t12.display();

}
