#pragma once

struct COLOR1 {
    int R;
    int G;
    int B;
};

class Circle {
private:
    COORD centre;
    unsigned int radius;
    COLOR1 color;

public:
    Circle(COORD centre, int radius, COLOR1 color);
    void setCircle(COORD centre, int radius, COLOR1 color);
    void draw();
};
