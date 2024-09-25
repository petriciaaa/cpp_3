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
COORD initLb = { 450,200 }, initRb = { 550,250 };
Color initColor = { 12,123,12 };

class Rect {


	private:
		COORD leftTop;
		COORD rightBottom;
		Color color;


	public:
		Rect(COORD lt = initLb, COORD rb = initRb, Color c = initColor):leftTop(lt) , rightBottom(rb),color(c) {
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


const int INCREMENT = 50; 

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

	
	while (true)
	{

		rect.drawRect();
		COORD leftTop , rightBottom ;
		rect.get_rect(&leftTop, &rightBottom);

		if (increasing) {
			increase(&leftTop, &rightBottom);
			if (rightBottom.X >= 1000 || rightBottom.Y >= 600) {
				increasing = false;
			}
		}
		else {
			decrease(&leftTop, &rightBottom);
				if (initLb.Y == leftTop.Y && initLb.X == leftTop.X && initRb.Y == rightBottom.Y && initRb.X == rightBottom.X)
				{
					increasing = true;

			}
		}


		rect.setRect(leftTop, rightBottom, { rand() % 255,rand() % 255,rand() % 255 });

		Sleep(500);
	}

	std::getchar();

	return 0;
}