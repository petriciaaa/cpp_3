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
	COORD rightTop;
	Color color;


public:
	Rect() {
		leftBottom = { 100, 230 };
		rightTop = { 280, 225 };
		color = { 10, 10, 10 };
	}
	void setRect(COORD lb, COORD rt, Color c) {
		leftBottom = lb;
		rightTop = rt;
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
			rightTop.X,
			rightTop.Y);

		DeleteObject(hBrush);	
		ReleaseDC(hWindow, hDeviceContext);


	}
};


int main() {

	Rect rect1;
	Rect rect2;
	Rect rect3;
	Rect rect4;

	rect1.setRect({ 120,20 }, { 310,310 }, { 250,130,80 });
	rect2.setRect({ 440,160 }, { 500,340 }, { 50,10,80 });
	rect3.setRect({ 620,325 }, { 720,110 }, { 20,13,130 });
	rect4.setRect({ 820,105 }, { 900,410 }, {137,98,230 });

	rect1.drawRect();
	rect2.drawRect();
	rect3.drawRect();
	rect4.drawRect();

	std::getchar();

	return 0;
}