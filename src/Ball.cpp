#include <raylib.h>
#include "Ball.hpp"
#include "utils.hpp"

Ball::Ball(int x, int y, int speed, int size, Color color)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->size = size;
    this->color = color;

    this->initial_x = x;
    this->initial_y = y;

    update_box_2d(this->box, this->x, this->y, this->size, this->size);
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

    update_box_2d(this->box, this->x, this->y, this->size, this->size);
}

// Resets the ball to its initial state
void Ball::reset() 
{
    this->x = this->initial_x;
    this->y = this->initial_y;
    this->up = false;
    this->right = true;

    update_box_2d(this->box, this->x, this->y, this->size, this->size);
}

// Draw the ball to the screen
void Ball::draw()
{
    DrawRectangle(this->x, this->y, this->size, this->size, this->color);
}