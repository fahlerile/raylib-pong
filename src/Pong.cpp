#include <raylib.h>
#include "Pong.hpp"

Pong::Pong(float x, float y, float width, float height, float speed, Color color)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
    this->color = color;

    this->set_box();
}

int Pong::get_score()
{
    return this->score;
}

void Pong::set_score(int new_score)
{
    if (new_score >= 0)
        this->score = new_score;
}

void Pong::increment_score()
{
    this->score++;
}

// Draw the pong.
void Pong::draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}

void Pong::process_input(KeyboardKey up, KeyboardKey down, int screen_height)
{
    if (IsKeyDown(up) && this->y > 0)
        this->y -= this->speed;
    else if (IsKeyDown(down) && this->y < (screen_height - this->height))
        this->y += this->speed;

    this->set_box();
}