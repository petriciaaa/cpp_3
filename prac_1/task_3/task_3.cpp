#include<iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

struct Color
{
	int R;
	int G;
	int B;
};


class Rect {


	private:
		COORD leftTop;
		COORD rightBottom;
		Color color;


	public:
		Rect(COORD lt = { 700,250 }, COORD rb = { 800,300 }, Color c = { 12,123,12}):leftTop(lt) , rightBottom(rb),color(c) {
			//
		}
		void setRect(COORD lb, COORD rb, Color c) {
			leftTop = lb;
			rightBottom = rb;
			color = c;
		}		
		void get_rect(COORD* leftTop, COORD* rightBottom) {
			*leftTop = this->leftTop;
			*rightBottom = this->rightBottom;
		}
		void drawRect() {

			HWND hWindow = GetConsoleWindow();
			HDC hDeviceContext = GetDC(hWindow);

			HBRUSH hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));
			SelectObject(hDeviceContext, hBrush);
			Rectangle(
				hDeviceContext,
				leftTop.X,
				leftTop.Y,
				rightBottom.X,
				rightBottom.Y);

			DeleteObject(hBrush);
			ReleaseDC(hWindow, hDeviceContext);


		}
};


const int INCREMENT = 100; 
const int MAX_WIDTH = 1000;
const int MAX_HEIGHT = MAX_WIDTH/2;
void increase(COORD* coord1, COORD* coord2) {
	coord1->X -= INCREMENT; 
	coord1->Y -= INCREMENT/2; 
	coord2->X += INCREMENT; 
	coord2->Y += INCREMENT/2; 
}

void decrease(COORD* coord1, COORD* coord2) {
	coord1->X += INCREMENT; 
	coord1->Y += INCREMENT/2; 
	coord2->X -= INCREMENT; 
	coord2->Y -= INCREMENT/2; 
}

int main() {
	Rect rect; 

	srand(time(0));

	bool increasing = true; 
	COORD originalLeftTop = { 700, 250 };
	COORD originalRightBottom = { 800, 300 };
	
	while (true)
	{
		system("cls");

		rect.drawRect();
		COORD leftTop , rightBottom ;
		rect.get_rect(&leftTop, &rightBottom);
		if (increasing) {
			if (rightBottom.X - leftTop.X < MAX_WIDTH && leftTop.Y > 0) {
				increase(&leftTop, &rightBottom);
			}
			else {
				increasing = false; 
			}
		}
		else {
			if (rightBottom.X - leftTop.X > (originalRightBottom.X - originalLeftTop.X)) {
				decrease(&leftTop, &rightBottom);
			}
			else {
				increasing = true;
				leftTop = originalLeftTop;
				rightBottom = originalRightBottom;
			}
		}


		rect.setRect(leftTop, rightBottom, { rand() % 256,rand() % 256,rand() % 256 });

		Sleep(500);
	}

	std::getchar();

	return 0;
}