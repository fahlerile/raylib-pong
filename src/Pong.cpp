#include <raylib.h>
#include "Pong.hpp"
#include "utils.hpp"

Pong::Pong(int x, int y, int width, int height, int vertical_speed, Color color)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->vertical_speed = vertical_speed;
    this->color = color;

    update_box_2d(this->box, this->x, this->y, this->width, this->height);
}

// Draw the pong.
void Pong::draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}

void Pong::process_input(KeyboardKey up, KeyboardKey down, int screen_height)
{
    if (IsKeyDown(up) && this->y > 0)
        this->y -= this->vertical_speed;
    else if (IsKeyDown(down) && this->y < (screen_height - this->height))
        this->y += this->vertical_speed;

    update_box_2d(this->box, this->x, this->y, this->width, this->height);
}