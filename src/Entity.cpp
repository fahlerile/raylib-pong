#include <raylib.h>
#include "Entity.hpp"

// Get position vector. (x, y)
Vector2 Entity::get_position()
{
    return this->position;
}

// Get dimensions vector. (width, height)
Vector2 Entity::get_dimensions()
{
    return this->dimensions;
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
    this->box = (BoundingBox) {
        Vector3 {this->position.x,                      this->position.y,                      0},
        Vector3 {this->position.x + this->dimensions.x, this->position.y + this->dimensions.y, 0}
    };
}

BoundingBox Entity::get_box()
{
    return this->box;
}