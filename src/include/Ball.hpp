#pragma once
#include <raylib.h>
#include "Entity.hpp"

enum Touched {VERTICAL, HORIZONTAL, BOTH};

class Ball : Entity
{
    private:
        bool up = false;
        bool right = true;

        float initial_x;
        float initial_y;

    public:
        Ball(float x, float y, float speed, float size, Color color);
        void toggle_bonuce_direction(Touched touched_side);
        void move();
        void reset();
        void draw();
};