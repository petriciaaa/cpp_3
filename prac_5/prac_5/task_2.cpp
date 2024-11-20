#include "MoveRect.h"   

int main() {
    int const DELAY = 1000;

    int centre[2] = { 500, 250 };
    const int increase = 50;
    int size = 40;


    COORD left = { centre[0] - size, centre[1] - size };
    COORD right = { centre[0] + size, centre[1] + size };

    Color color = { 0, 255, 0 };

    MoveRect rect(left, right, color);


    rect.draw();


    Color colors[] = {
    {10, 255, 0},
    {20, 0, 0},
    {30, 0, 255},
    {40, 255, 0},
    {50, 0, 255},
    {10, 255, 55},
    {20, 25, 25},
    {30, 55, 255},
    {40, 255, 255},
    {50, 25, 25},

    };



    while (true) {

        for (int i = size; i <= increase; i ++) {
            Color newColor = colors[(i - (size + 1)) % 10];
            rect.increase(newColor);
            rect.draw();
            Sleep(DELAY);
        }


        for (int i = increase; i >= size; i --) {
            Color newColor = colors[(i - (size)) % 10];
            rect.decrease(newColor);
            rect.draw();
            Sleep(DELAY);
        }


        rect.setRect(left, right, color);
        rect.draw();
    }

    return 0;
}
