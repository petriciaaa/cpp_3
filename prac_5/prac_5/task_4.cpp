#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

struct Color {
    int R;
    int G;
    int B;
};

class Circle {
protected:
    COORD leftBottom;
    COORD rightTop;
    Color color;

public:
    Circle() : leftBottom({ 300, 200 }), rightTop({ 500, 400 }), color({ 100, 100, 100 }) {}

    void setCircle(COORD lb, COORD rt, Color c) {
        leftBottom = lb;
        rightTop = rt;
        color = c;
    }

    void drawCircle() {
        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);
        HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));

        SelectObject(hDeviceContext, hBrush);
        Ellipse(hDeviceContext, leftBottom.X, leftBottom.Y, rightTop.X, rightTop.Y);

        DeleteObject(hBrush);
        ReleaseDC(hWindow, hDeviceContext);
    }
};

class MyEllipse : public Circle {
private:
    int flat;

public:

    MyEllipse() : Circle(), flat(50) {}

    void setEllipse(COORD center, int radius1, int radius2, Color c) {

        COORD lb = { center.X - radius1, center.Y - radius2 };
        COORD rt = { center.X + radius1, center.Y + radius2 };

        setCircle(lb, rt, c);

        flat = radius2;
    }

    void drawEllipse() {
        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);
        HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));

        SelectObject(hDeviceContext, hBrush);
        Ellipse(hDeviceContext,
            (leftBottom.X + rightTop.X) / 2,
            (leftBottom.Y + rightTop.Y) / 2,
            (rightTop.X - leftBottom.X) / 2,
            (rightTop.Y - leftBottom.Y) / 2);

        DeleteObject(hBrush);
        ReleaseDC(hWindow, hDeviceContext);
    }
};

int main() {

    MyEllipse ellipse1;
    MyEllipse ellipse2;

    ellipse1.setEllipse({ 600, 500 }, 300, 100, { 200, 200, 200 });

    ellipse1.drawEllipse();
    ellipse2.drawEllipse();

    _getche();

    return 0;
}