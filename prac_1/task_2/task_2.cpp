#include<iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Color {
    int R;
    int G;
    int B;
};


class Circle {

    private:
        COORD centre;
        unsigned int radius;
        Color color;

    public:
    
        Circle(COORD centre = { 700,200 }, int radius = 75, Color color = { 125, 125 ,70 }) {
            this->centre = centre;
            this->radius = radius;
            this->color = color;
        }

        void setCircle(COORD centre , int radius , Color color ) {
            this->centre = centre;
            this->radius = radius;
            this->color = color;
        }

        void draw() {

            HWND hWindow = GetConsoleWindow();
            HDC hDeviceContext = GetDC(hWindow);

            HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));

            SelectObject(hDeviceContext, hBrush);
            Ellipse(hDeviceContext, centre.X+radius, centre.Y+ radius, centre.X- radius, centre.Y- radius);

            DeleteObject(hBrush);
            ReleaseDC(hWindow, hDeviceContext);
        }
};

int main() {

    SetConsoleOutputCP(1251);

    Circle circle;

    srand(time(NULL));

    int count;

    const unsigned int RADIUS = 75;
    const unsigned int TICK = 500;
    const Color COLOR ={ 255, 20, 147 };

    cout << "Enter count of circles per tick: ";
    cin >> count;
    system("cls");

    while (true) {

        for (int i = 0; i < count; i++)
        {
            COORD centre = { rand() % 2000,rand() % 2000 };

            circle.setCircle(
                  centre
                , RADIUS
                , COLOR);
            
            circle.draw();

        }
        Sleep(TICK);

    }


    return 0;
}