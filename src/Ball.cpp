#include <raylib.h>
#include "Ball.hpp"

Ball::Ball(float x, float y, float speed, float size, Color color)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->width = size;
    this->height = size;
    this->color = color;

    this->initial_x = x;
    this->initial_y = y;

    this->set_box();
}

// Changes the bounce direction
void Ball::toggle_bonuce_direction(Touched touched_side)
{
    if (touched_side == VERTICAL || touched_side == BOTH)
        this->up = !(this->up);
    if (touched_side == HORIZONTAL || touched_side == BOTH)
        this->right = !(this->right);
}

// Moves the ball
void Ball::move()
{
    if (up)
        this->y -= this->speed;
    else
        this->y += this->speed;

    if (right)
        this->x += this->speed;
    else
        this->x -= this->speed;

    this->set_box();
}

// Resets the ball to its initial state (randomizing `y` value)
void Ball::reset()
{
    this->x = this->initial_x;
    this->y = (GetRandomValue(0, 1)) ? this->initial_y + GetRandomValue(0, this->initial_y / 2) :
                                       this->initial_y - GetRandomValue(0, this->initial_y / 2);
    this->up = false;
    this->right = true;

    this->set_box();
}

// Draw the ball to the screen
void Ball::draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}