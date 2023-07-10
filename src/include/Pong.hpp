#pragma once
#include <raylib.h>

class Pong
{
    private:
        int width;
        int height;
        int vertical_speed;
        Color color;

    public:
        int x;
        int y;
        BoundingBox box;
        int score = 0;

        Pong(int x, int y, int width, int height, int vertical_speed, Color color);
        void draw();
        void process_input(KeyboardKey up, KeyboardKey down, int screen_height);
};