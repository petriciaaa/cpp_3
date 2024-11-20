#include <iostream>
#include <windows.h>
using namespace std;

class Distance {
private:
    int meters;
    float centimeters;

public:

    Distance() : meters(0), centimeters(0.0) {}
    Distance(int m, float c) : meters(m), centimeters(c) {}


    void get_dist() {
        cout << "Enter meters: ";
        cin >> meters;
        cout << "Enter centimeters: ";
        cin >> centimeters;
    }


    void show_dist() const {
        cout << meters << "m " << centimeters << "cm" << endl;
    }


    Distance operator += (const Distance dist);
    Distance operator - (const Distance dist) const;
    Distance operator * (const Distance dist) const;

    bool operator < (const Distance dist) const;
    bool operator > (const Distance dist) const;
    bool operator == (const Distance dist) const;
};

Distance Distance::operator += (const Distance dist) {
    meters += dist.meters;
    centimeters += dist.centimeters;

    if (centimeters >= 100.0) {
        centimeters -= 100.0;
        meters++;
    }

    return *this;
}

Distance Distance::operator - (const Distance dist) const {
    int totalCentimeters1 = meters * 100 + static_cast<int>(centimeters);
    int totalCentimeters2 = dist.meters * 100 + static_cast<int>(dist.centimeters);

    if (totalCentimeters1 < totalCentimeters2) {
        cout << "First distance must be greater than second." << endl;
        return Distance();
    }

    int resultCentimeters = totalCentimeters1 - totalCentimeters2;

    return Distance(resultCentimeters / 100, resultCentimeters % 100);
}

Distance Distance::operator * (const Distance dist) const {
    float totalMeters1 = meters + centimeters / 100.0f;
    float totalMeters2 = dist.meters + dist.centimeters / 100.0f;

    float prod = totalMeters1 * totalMeters2;

    return Distance(static_cast<int>(prod), (prod - static_cast<int>(prod)) * 100);
}

bool Distance::operator < (const Distance dist) const {
    float bd1 = meters + centimeters / 100.0f;
    float bd2 = dist.meters + dist.centimeters / 100.0f;

    return bd1 < bd2;
}

bool Distance::operator > (const Distance dist) const {
    float bd1 = meters + centimeters / 100;
    float bd2 = dist.meters + dist.centimeters / 100;
    return (bd1 > bd2) ? true : false;
}

bool Distance::operator == (const Distance dist) const {
    return meters == dist.meters && centimeters == dist.centimeters;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Distance dist1, dist2(13,6.5);


    dist1.get_dist();

    cout << "\ndist 1 =  ";
    dist1.show_dist();    
    cout << "dist 2 =  ";
    dist2.show_dist();


    Distance dist3 = dist1;
    dist3 += dist2;
    cout << "dist 3 =  ";
    dist3.show_dist();

    Distance dist4 = dist1 - dist2;
    cout << "dist 4 = ";
    dist4.show_dist();

    Distance dist5 = dist1 * dist2;
    cout << "dist 5 = ";
    dist5.show_dist();

    if (dist1 == dist2) {
        cout << "dist1 equals dist2." << endl;
    }
    else if (dist1 < dist2) {
        cout << "dist1 is less than  dist2." << endl;
    }
    else {
        cout << "dist1 is greater than dist2." << endl;
    }
    return 0;
}