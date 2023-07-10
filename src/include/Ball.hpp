#pragma once
#include <raylib.h>

enum Touched {VERTICAL, HORIZONTAL, BOTH};

class Ball
{
    private:
        bool up = false;
        bool right = true;
        Color color;

        int initial_x;
        int initial_y;

    public:
        int x;
        int y;
        BoundingBox box;
        int size;
        int speed;

        Ball(int x, int y, int speed, int size, Color color);
        void toggle_bonuce_direction(Touched touched_side);
        void move();
        void reset();
        void draw();
};