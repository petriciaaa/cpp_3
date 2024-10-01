#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Circle.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    const unsigned int RADIUS = 75;
    const unsigned int TICK = 500;
    const Color COLOR = { 255, 20, 147 };

    int count;

    cout << "Enter count of circles per tick: ";
    cin >> count;

    system("cls");

    while (true) {
        for (int i = 0; i < count; i++) {
            COORD centre = { rand() % 2000, rand() % 2000 };

            Circle circle(centre, RADIUS, COLOR); // Создание объекта Circle с параметрами
            circle.draw();
        }
        Sleep(TICK);
    }

    return 0;
}
