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
        void setLine(COORD start, COORD end, Color color, int width, int lineType);

        void draw();
        void setCords(COORD start, COORD end);
        COORD getStart();
        COORD getEnd();

};