#include <iostream>
#include <windows.h>
#include <conio.h>

struct Color {
    int R;
    int G;
    int B;
};

class Rect {
protected:
    COORD left;
    COORD right;
    Color color;

public:
    Rect() {
        left.X = 500;
        left.Y = 250;
        right.X = 500;
        right.Y = 250;

        color.R = 0;
        color.G = 0;
        color.B = 0;
    }

    Rect(COORD left, COORD right, Color color) {
        this->left = left;
        this->right = right;
        this->color = color;
    }

    void setRect(COORD lb, COORD rb, Color c) {
        left = lb;
        right = rb;
        color = c;
    }

    void draw() {
        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);
        HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));

        SelectObject(hDeviceContext, hBrush);
        Rectangle(hDeviceContext, left.X, left.Y, right.X, right.Y);

        DeleteObject(hBrush);
        ReleaseDC(hWindow, hDeviceContext);
    }

    COORD getCenter()  {
        COORD center;
        center.X = (left.X + right.X) / 2;
        center.Y = (left.Y + right.Y) / 2;
        return center;
    }
};
