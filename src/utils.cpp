#include <string>
#include <raylib.h>
#include "utils.hpp"

// Update the bounding box
void update_box_2d(BoundingBox &box, int x, int y, int width, int height)
{
    BoundingBox temp_box {
        Vector3 {(float) x,         (float) y,          (float) 0},
        Vector3 {(float) x + width, (float) y + height, (float) 0}
    };
    box = temp_box;
}

// Draw score text
void write_score(int score, int width_to_center_in, int x_offset, int y, int size)
{
    // formatting the string and converting it to char *
    std::string score_str = "";
    score_str += "SCORE: ";
    score_str += std::to_string(score);
    const char *c_str = score_str.c_str();

    // drawing the text
    DrawText(c_str, x_offset + (width_to_center_in - (MeasureText(c_str, size))) / 2,
             y, size, BLACK);
}