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
    const int pong_width = 25;  // width of the "pong pad"
    const int pong_height = 100;  // height of the "pong pad"
    const Vector2 pong_dimensions {25, 100};  // dimensions of the "pong pad"
    const Color main_color {25, 25, 25, 255};  // main color of the game (ball, pong, etc.)

    const int vertical_line_width = 10;  // width of vertical separator
    const int vertical_line_x = half_window_dimensions.x - (vertical_line_width / 2);  // x value of vertical separator (and width of each player's side)

    const int text_y = 10;  // text y offset
    const int text_size = 30;  // size of text

    const int ball_size = 25;  // size of a ball

    // default values
    const int pong_start_vertical_speed = 3;  // vertical speed of pong
    const float pong_start_y = half_window_dimensions.y - (pong_height) / 2;  // start y value of pongs
    const float ball_start_speed = 3.0f;  // start speed of ball
    const float ball_speed_change = 0.2f;  // how fast ball is accelerating on each bounce
    const float ball_speed_max = 6.0f;  // max ball speed

    // initializing Pongs and a Ball
    Pong pong_1((Vector2) {pong_margin, pong_start_y},
                (Vector2) {pong_width, pong_height},
                pong_start_vertical_speed, main_color);
    Pong pong_2((Vector2) {window_dimensions.x - (pong_margin + pong_width), pong_start_y},
                (Vector2) {pong_width, pong_height},
                pong_start_vertical_speed, main_color);
    Ball ball((Vector2) {half_window_dimensions.x, half_window_dimensions.y},
              ball_start_speed, ball_speed_change, ball_speed_max, ball_size, main_color);

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

        EndDrawing();
    }

    CloseWindow();
    return 0;
}