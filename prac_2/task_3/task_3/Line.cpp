#include "Line.h"
#include <iostream>

Line::Line(COORD start, COORD end, Color color, int width, const int lineType) {
    this->start = start;
    this->end = end;
    this->color = color;
    this->width = width;
    this->lineType = lineType;
};

void Line::draw() {

        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);

        HPEN hPen = CreatePen(lineType, width, (RGB(color.R, color.G, color.B)));

        SelectObject(hDeviceContext, hPen);

        MoveToEx(hDeviceContext, start.X, start.Y,NULL);
        LineTo(hDeviceContext, end.X, end.Y);

        DeleteObject(hPen);
        ReleaseDC(hWindow, hDeviceContext);
};
