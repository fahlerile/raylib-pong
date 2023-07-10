#include <iostream>
#include <raylib.h>
#include "Pong.hpp"
#include "Ball.hpp"
#include "utils.hpp"

int main(void)
{
    // CONSTANTS
    const int screen_width = 800;
    const int screen_height = 600;
    const int screen_middle_width = screen_width / 2;
    const int screen_middle_height = screen_height / 2;

    const int pong_margin = 10;  // pong margin from the window borders
    const int pong_width = 25;
    const int pong_height = 100;
    const int pong_vertical_speed = 3;

    const Color main_color {25, 25, 25, 255};

    const int vertical_line_width = 10;
    const int vertical_line_x = screen_middle_width - (vertical_line_width / 2);

    const int text_y = 10;
    const int text_size = 30;

    // initializing Pongs and a Ball
    Pong pong_1(pong_margin, 10, pong_width, pong_height, pong_vertical_speed, main_color);
    Pong pong_2(screen_width - (pong_margin + pong_width), 10, pong_width, pong_height, pong_vertical_speed, main_color);
    Ball ball(screen_middle_width, screen_middle_height, 3, 25, main_color);

    // initializing a window
    InitWindow(screen_width, screen_height, "Pong!");
    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose())
    {
        pong_1.process_input(KEY_W, KEY_S, screen_height);
        pong_2.process_input(KEY_UP, KEY_DOWN, screen_height);

        BeginDrawing();

            // clear the screen
            ClearBackground(RAYWHITE);

            // draw vertical line
            DrawRectangle(vertical_line_x, 0, vertical_line_width, screen_height, main_color);

            // write score text
            write_score(pong_1.score, vertical_line_x, 0, text_y, text_size);
            write_score(pong_2.score, vertical_line_x, vertical_line_x + vertical_line_width, text_y, text_size);

            // draw pongs
            pong_1.draw();
            pong_2.draw();
            ball.draw();

            if (CheckCollisionBoxes(ball.box, pong_2.box) || CheckCollisionBoxes(ball.box, pong_1.box))
                ball.toggle_bonuce_direction(HORIZONTAL);
            if (ball.y < 0 || (ball.y + ball.size) > screen_height)
                ball.toggle_bonuce_direction(VERTICAL);

            if (ball.x < 0)
            {
                ball.reset();
                pong_2.score++;
            }
            else if ((ball.x + ball.size) > screen_width)
            {
                ball.reset();
                pong_1.score++;
            }

            ball.move();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}