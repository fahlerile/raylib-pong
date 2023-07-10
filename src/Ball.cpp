#include <raylib.h>
#include "Ball.hpp"
#include "Pong.hpp"

Ball::Ball(float x, float y, float speed, float speed_change, float speed_max, float size, Color color)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->width = size;
    this->height = size;
    this->color = color;

    this->up = (bool) GetRandomValue(0, 1);
    this->right = (bool) GetRandomValue(0, 1);

    this->speed_change = speed_change;
    this->speed_max = speed_max;

    this->initial_x = x;
    this->initial_y = y;
    this->initial_speed = speed;

    this->set_box();
}

// Changes the bounce direction
void Ball::toggle_bounce_direction(Touched touched_side)
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
    this->up = (bool) GetRandomValue(0, 1);
    this->right = (bool) GetRandomValue(0, 1);

    this->set_box();
}

// Draw the ball to the screen
void Ball::draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}

// Check collision for ball and bounce if needed.
// `window_dimensions` is a vector (width, height).
void Ball::check_collision_and_bounce(Pong &pong_1, Pong &pong_2, Vector2 window_dimensions)
{
    // if collision with pong
    if (CheckCollisionBoxes(this->box, pong_1.get_box()) ||
        CheckCollisionBoxes(this->box, pong_2.get_box()))
    {
        this->toggle_bounce_direction(HORIZONTAL);
        if (this->speed < this->speed_max)
            this->speed += this->speed_change;
    }

    // if collision with up or down ends of the screen
    if (this->y < 0 || (this->y + this->height) > window_dimensions.y)
        this->toggle_bounce_direction(VERTICAL);

    // if collision with left or right ends of the screen
    bool collision_left = (this->x < 0);
    bool collision_right = ((this->x + this->width) > window_dimensions.x);

    if (collision_left || collision_right)
    {
        this->reset();
        this->speed = this->initial_speed;
        if (collision_left)
            pong_2.increment_score();
        else
            pong_1.increment_score();
    }
}