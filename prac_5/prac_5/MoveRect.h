#include "Rect.h"

class MoveRect : public Rect {
public:
    MoveRect() : Rect() {}
    MoveRect(COORD left, COORD right, Color color) : Rect(left, right, color) {}

    void increase(Color newColor) {

        COORD center = getCenter();
        COORD newLeft = { center.X - (right.X - left.X) / 2 - 20, center.Y - (right.Y - left.Y) / 2 - 20 };
        COORD newRight = { center.X + (right.X - left.X) / 2 + 20, center.Y + (right.Y - left.Y) / 2 + 20 };


        setRect(newLeft, newRight, newColor);
    }

    void decrease(Color newColor) {

        COORD center = getCenter();
        COORD newLeft = { center.X - (right.X - left.X) / 2 + 20, center.Y - (right.Y - left.Y) / 2 + 20 };
        COORD newRight = { center.X + (right.X - left.X) / 2 - 20, center.Y + (right.Y - left.Y) / 2 - 20 };


        setRect(newLeft, newRight, newColor);
    }
};
