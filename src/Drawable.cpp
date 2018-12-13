
#include "Drawable.h"

Drawable::Drawable(const std::string& n, const Vector& pos, const Vector& vel,
        float s) :
    name(n),
    position(pos),
    velocity(vel),
    scale(s)
{
}

Drawable::Drawable(const Drawable& d) :
    name(d.name),
    position(d.position),
    velocity(d.velocity),
    scale(d.scale)
{
}

float Drawable::get_scale() const
{
    return (scale);
}

void Drawable::set_scale(float s)
{
    scale = s;
}

const std::string& Drawable::get_name() const
{
    return (name);
}

void Drawable::set_name(const std::string& n)
{
    name = n;
}

float Drawable::get_x() const
{
    return (position[0]);
}

float Drawable::get_y() const
{
    return (position[1]);
}

void Drawable::set_x(float x)
{
    position[0] = x;
}

void Drawable::set_y(float y)
{
    position[1] = y;
}

const Vector& Drawable::get_velocity() const
{
    return (velocity);
}

const Vector& Drawable::get_position() const
{
    return (position);
}

void Drawable::set_velocity(const Vector& vel)
{
    velocity = vel;
}

void Drawable::set_position(const Vector& pos)
{
    position = pos;
}

float Drawable::get_velocity_x() const
{
    return (velocity[0]);
}

float Drawable::get_velocity_y() const
{
    return (velocity[1]);
}

void Drawable::set_velocity_x(float vx)
{
    velocity[0] = vx;
}

void Drawable::set_velocity_y(float vy)
{
    velocity[1] = vy;
}

