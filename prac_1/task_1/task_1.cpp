#include <iostream>
#include <windows.h>
#include <conio.h>

struct Color
{
	int R;
	int G;
	int B;
};


class Rect {


private:
	COORD leftBottom;
	COORD rightBottom;
	Color color;


public:
	Rect() {
		leftBottom = { 0, 0 };
		rightBottom = { 80, 25 };
		color = { 0, 0, 0 };
	}
	void setRect(COORD lb, COORD rb, Color c) {
		leftBottom = lb;
		rightBottom = rb;
		color = c;
	}
	void drawRect() {

		HWND hWindow = GetConsoleWindow();
		HDC hDeviceContext = GetDC(hWindow);

		HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));
		SelectObject(hDeviceContext, hBrush);
		Rectangle(
			hDeviceContext,
			leftBottom.X,
			leftBottom.Y,
			rightBottom.X,
			rightBottom.Y);

		DeleteObject(hBrush);
		ReleaseDC(hWindow, hDeviceContext);


	}
};


int main() {

	Rect rect1;
	Rect rect2;
	Rect rect3;

	rect1.setRect({120,20 }, { 310,310 }, { 250,130,80 });
	rect2.setRect({ 140,160 }, { 365,620 }, { 50,10,80 });
	rect3.setRect({ 410,325 }, { 470,110 }, { 20,13,0 });

	rect1.drawRect();
	rect2.drawRect();
	rect3.drawRect();

	std::getchar();

	return 0;
}