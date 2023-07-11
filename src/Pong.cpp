#include <raylib.h>
#include "Pong.hpp"

#include <iostream>

Pong::Pong(Vector2 position, Vector2 dimensions, float speed, Color color)
{
    this->position = position;
    this->dimensions = dimensions;
    this->speed = speed;
    this->color = color;

    this->score = 0;
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
    this->score += 1;
}

// Draw the pong.
void Pong::draw()
{
    DrawRectangle(this->position.x, this->position.y,
                  this->dimensions.x, this->dimensions.y,
                  this->color);
}

void Pong::process_input(KeyboardKey up, KeyboardKey down, int screen_height)
{
    if (IsKeyDown(up) && this->position.y > 0)
        this->position.y -= this->speed;
    else if (IsKeyDown(down) && this->position.y < (screen_height - this->dimensions.y))
        this->position.y += this->speed;

    this->set_box();
}