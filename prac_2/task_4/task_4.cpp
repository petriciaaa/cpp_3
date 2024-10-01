#include <iostream>
#include<windows.h>
#include "../../prac_2/task_3/task_3/Line.h"
#include "../../prac_2/task_3/task_3/Line.cpp"
#include "../../prac_2/task_3/task_3/Color.h"
#include "../../prac_1/task_2/Circle.h"
#include "../../prac_1/task_2/Circle.cpp"

const Color COLOR = { 123,23,44 };
const COORD INIT_START = { 500,300 };
const COORD CENTER = { 500, 300 };
const COORD INIT_END = { 500,100 };
const int RADIUS = 200;
const int INCREMENT = 3.5;
const double  M_PI = 3.1423343123;

int main()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);


    HWND hWindow = GetConsoleWindow();
    HDC hDeviceContext = GetDC(hWindow);

    TextOutA(hDeviceContext, CENTER.X - strlen("Секундомер")*1.5, (CENTER.Y - RADIUS) - 50, "Секундомер", strlen("Секундомер"));

    TextOutA(hDeviceContext, CENTER.X  , (CENTER.Y - RADIUS) -20, "60",2);
    TextOutA(hDeviceContext, CENTER.X , (CENTER.Y +RADIUS ) +10, "15",2);
    TextOutA(hDeviceContext, CENTER.X + RADIUS +10, (CENTER.Y  ) +10, "30",2);
    TextOutA(hDeviceContext, CENTER.X - RADIUS -20, (CENTER.Y) + 10, "45", 2);



    Circle circle(CENTER, RADIUS + 3 ,{200,20,02});
    circle.draw();

    Line line(INIT_START, INIT_END, COLOR, 5, PS_SOLID);
   
    int angle = 270;
    while (true)
    {
        double radians = angle * (M_PI / 180.0); 
        COORD start = { CENTER.X, CENTER.Y };
        COORD end;

        end.X = CENTER.X + int(RADIUS * cos(radians) ); 
        end.Y = CENTER.Y + int(RADIUS * sin(radians) ); 

        line.setLine(start, end, COLOR, 5, PS_SOLID);
        line.draw();
      
        angle += INCREMENT;
        if (angle >= 360) angle -= 360; 

        Sleep(1000);
        line.setLine(start, end, { 200,20,02 }, 5, PS_SOLID);
        line.draw();
    }
    std::getchar();
}


