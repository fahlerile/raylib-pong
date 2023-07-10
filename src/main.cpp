#include <iostream>

#include <raylib.h>
#include "Pong.hpp"
#include "Ball.hpp"
#include "utils.hpp"

int main(void)
{
    // CONSTANTS
    const Vector2 window_dimensions {800, 600};
    const Vector2 half_window_dimensions {window_dimensions.x / 2,
                                          window_dimensions.y / 2};

    const int pong_margin = 10;  // pong margin from the window borders
    const int pong_width = 25;
    const int pong_height = 100;
    const Color main_color {25, 25, 25, 255};

    const int vertical_line_width = 10;
    const int vertical_line_x = half_window_dimensions.x - (vertical_line_width / 2);

    const int text_y = 10;
    const int text_size = 30;

    // default values
    const int pong_start_vertical_speed = 3;
    const int pong_start_y = half_window_dimensions.y - (pong_height) / 2;
    const int ball_start_speed = 3;
    const float ball_speed_change = 0.2f;
    const float ball_speed_max = 6.0f;
    const int ball_start_size = 25;

    // initializing Pongs and a Ball
    Pong pong_1(pong_margin, pong_start_y, pong_width, pong_height, pong_start_vertical_speed, main_color);
    Pong pong_2(window_dimensions.x - (pong_margin + pong_width), pong_start_y, pong_width, pong_height, pong_start_vertical_speed, main_color);
    Ball ball(half_window_dimensions.x, half_window_dimensions.y, ball_start_speed, ball_speed_change, ball_speed_max, ball_start_size, main_color);

    // initializing a window
    InitWindow(window_dimensions.x, window_dimensions.y, "Pong!");
    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose())
    {
        pong_1.process_input(KEY_W, KEY_S, window_dimensions.y);
        pong_2.process_input(KEY_UP, KEY_DOWN, window_dimensions.y);

        BeginDrawing();

            // clear the screen
            ClearBackground(RAYWHITE);

            // draw vertical line
            DrawRectangle(vertical_line_x, 0, vertical_line_width, window_dimensions.y, main_color);

            // write score text
            write_score(pong_1.get_score(), vertical_line_x, 0, text_y, text_size);
            write_score(pong_2.get_score(), vertical_line_x, vertical_line_x + vertical_line_width, text_y, text_size);

            // draw pongs
            pong_1.draw();
            pong_2.draw();
            ball.draw();

            ball.check_collision_and_bounce(pong_1, pong_2, window_dimensions);
            ball.move();

            std::cout << ball.get_speed() << std::endl;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}