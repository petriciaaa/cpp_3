#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include "Color.h"

class Line {
    private:
  
        COORD start;
        COORD end;
        Color color;
        unsigned int width;
        int lineType;

    public:
  
        Line(COORD start, COORD end, Color color, int width, int lineType);
        void draw();

};