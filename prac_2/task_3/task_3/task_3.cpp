#include <iostream>
#include "Line.h"

Color COLOR = { 212,122,12 };

int main()
{
   

    Line lines[6] = {
         Line({ 400,400 }, { 600,300 }, COLOR,5, PS_SOLID),
         Line({ 400,400 }, { 250,320 }, COLOR,5, PS_SOLID),
         Line({ 250,320 }, { 600,300 }, COLOR,1, PS_DOT),
         Line({ 250,320 }, { 420,100 }, COLOR,5, PS_SOLID),
         Line({ 400,400 }, { 420,100 }, COLOR,5, PS_SOLID),
         Line({ 600,300 }, { 420,100 }, COLOR,5, PS_SOLID),
    };

    
    for (Line line : lines) {
        line.draw();
    }

    std::getchar();

    return 0;
}

