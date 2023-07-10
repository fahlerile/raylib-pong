#include <string>
#include "raylib.h"

class Pong
{
    public:
        int x;
        int y;
        int width;
        int height;
        int score;
        Color color;
        int text_y;
        int text_size;
        int width_to_center_in;  // the width to center text in

        Pong(int x, int y, int width, int height, Color color, int text_y, int text_size, int width_to_center_in)
        {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            this->color = color;
            this->score = 0;
            this->text_y = text_y,
            this->text_size = text_size;
            this->width_to_center_in = width_to_center_in;
        }

        // Draw the pong.
        void draw()
        {
            DrawRectangle(this->x, this->y, this->width, this->height, this->color);
        }

        // Draw score text.
        void write_score(int x_offset)
        {
            // formatting the string and converting it to char *
            std::string score_str = "";
            score_str += "SCORE: ";
            score_str += (this->score + '0');
            const char *c_str = score_str.c_str();

            // drawing the text
            DrawText(c_str, x_offset + (this->width_to_center_in - (MeasureText(c_str, this->text_size))) / 2,
                     this->text_y, this->text_size, BLACK);
        }
};

int main(void)
{
    // CONSTANTS
    const int screen_width = 800;
    const int screen_height = 600;
    const int screen_middle_width = screen_width / 2;

    const int pong_x_offset = 10;  // pong margin from the window borders
    const int pong_width = 25;
    const int pong_height = 100;
    const int pong_vertical_speed = 3;
    const Color pong_color {25, 25, 25, 255};

    const int vertical_line_width = 10;
    const int vertical_line_x = screen_middle_width - (vertical_line_width / 2);

    const int text_y = 10;
    const int text_size = 30;

    // initializing Pong objects
    Pong pong_1(pong_x_offset, 10, pong_width, pong_height, pong_color, text_y, text_size, vertical_line_x);
    Pong pong_2(screen_width - (pong_x_offset + pong_width), 10, pong_width, pong_height, pong_color, text_y, text_size, vertical_line_x);

    // initializing a window
    InitWindow(screen_width, screen_height, "Pong!");
    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose())
    {
        // process input for player 1
        if (IsKeyDown(KEY_W) && pong_1.y > 0)
            pong_1.y -= pong_vertical_speed;
        else if (IsKeyDown(KEY_S) && pong_1.y < (screen_height - pong_height))
            pong_1.y += pong_vertical_speed;

        // process input for player 2
        if (IsKeyDown(KEY_UP) && pong_2.y > 0)
            pong_2.y -= pong_vertical_speed;
        else if (IsKeyDown(KEY_DOWN) && pong_2.y < (screen_height - pong_height))
            pong_2.y += pong_vertical_speed;

        BeginDrawing();

            // clear the screen
            ClearBackground(RAYWHITE);

            // draw vertical line
            DrawRectangle(vertical_line_x, 0, vertical_line_width, screen_height, pong_color);

            // write score text
            pong_1.write_score(0);
            pong_2.write_score(vertical_line_x);

            // draw pongs
            pong_1.draw();
            pong_2.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}