#pragma once
#include <raylib.h>

class Entity
{
    protected:
        float x;
        float y;
        float width;
        float height;
        float speed;
        Color color;
        BoundingBox box;
    public:
        Vector2 get_position();
        Vector2 get_dimensions();
        float get_speed();
        void set_speed(float new_speed);
        void set_box();
        BoundingBox get_box();
};
