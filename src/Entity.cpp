#include <raylib.h>
#include "Entity.hpp"

// Get position vector. (x, y)
Vector2 Entity::get_position()
{
    return Vector2 {this->x, this->y};
}

// Get dimensions vector. (width, height)
Vector2 Entity::get_dimensions()
{
    return Vector2 {this->width, this->height};
}

// Get speed value
float Entity::get_speed()
{
    return this->speed;
}

// Set speed value. Negative values are prohibited.
void Entity::set_speed(float new_speed)
{
    if (new_speed >= 0)
        this->speed = new_speed;
}

// Update the bounding box
void Entity::set_box()
{
    BoundingBox temp_box {
        Vector3 {this->x,               this->y,                0},
        Vector3 {this->x + this->width, this->y + this->height, 0}
    };
    this->box = temp_box;
}

BoundingBox Entity::get_box()
{
    return this->box;
}