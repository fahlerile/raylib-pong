#pragma once
#include <raylib.h>
#include "Entity.hpp"

class Pong : public Entity
{
    private:
        int score;

    public:
        Pong(Vector2 position, Vector2 dimensions, float speed, Color color);
        int get_score();
        void set_score(int new_score);
        void increment_score();
        void draw();
        void process_input(KeyboardKey up, KeyboardKey down, int screen_height);
};