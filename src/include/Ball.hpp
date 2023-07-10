#pragma once
#include <raylib.h>
#include "Entity.hpp"
#include "Pong.hpp"

enum Touched {VERTICAL, HORIZONTAL, BOTH};

class Ball : public Entity
{
    private:
        bool up;
        bool right;

        float speed_change;
        float speed_max;

        float initial_x;
        float initial_y;
        float initial_speed;

    public:
        Ball(float x, float y, float speed, float speed_change, float speed_max, float size, Color color);
        void toggle_bounce_direction(Touched touched_side);
        void move();
        void reset();
        void draw();
        void check_collision_and_bounce(Pong &pong_1, Pong &pong_2, Vector2 window_dimensions);
};