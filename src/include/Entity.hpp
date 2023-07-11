#pragma once
#include <raylib.h>

class Entity
{
    protected:
        Vector2 position;
        Vector2 dimensions;
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
