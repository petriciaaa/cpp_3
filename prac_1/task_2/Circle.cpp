#include <windows.h>
#include "Circle.h"

Circle::Circle(COORD centre, int radius, COLOR1 color) {
    this->centre = centre;
    this->radius = radius;
    this->color = color;
}

void Circle::setCircle(COORD centre, int radius, COLOR1 color) {
    this->centre = centre;
    this->radius = radius;
    this->color = color;
}

void Circle::draw() {
    HWND hWindow = GetConsoleWindow();
    HDC hDeviceContext = GetDC(hWindow);

    HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));
    SelectObject(hDeviceContext, hBrush);

    Ellipse(hDeviceContext,
        centre.X - radius,
        centre.Y - radius,
        centre.X + radius,
        centre.Y + radius);

    DeleteObject(hBrush);
    ReleaseDC(hWindow, hDeviceContext);
}
