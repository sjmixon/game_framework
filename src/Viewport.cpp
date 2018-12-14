
#include "Game_Data.h"
#include "Viewport.h"

Viewport& Viewport::get_instance()
{
    static Viewport viewport;
    return (viewport);
}

Viewport::Viewport() :
    view_position(0, 0),
    world_width(Game_Data::get_instance().get_xml_int("world/width")),
    world_height(Game_Data::get_instance().get_xml_int("world/height")),
    view_width(Game_Data::get_instance().get_xml_int("view/width")),
    view_height(Game_Data::get_instance().get_xml_int("view/height")),
    object_width(0),
    object_height(0),
    object_to_track(nullptr)
{
}

void Viewport::update()
{
    const float x = object_to_track->get_x();
    const float y = object_to_track->get_y();
    view_position[0] = (x + object_width / 2) - view_width / 2;
    view_position[1] = (y + object_height / 2) - view_height / 2;
    if (view_position[0] < 0)
    {
        view_position[0] = 0;
    }
    if (view_position[1] < 0)
    {
        view_position[1] = 0;
    }
    if (view_position[0] > (world_width - view_width))
    {
        view_position[0] = world_width - view_width;
    }
    if (view_position[1] > (world_height - view_height))
    {
        view_position[1] = world_height - view_height;
    }
}

void Viewport::set_object_to_track(Drawable* obj)
{
    object_to_track = obj;
    object_width = object_to_track->get_scaled_width();
    object_height = object_to_track->get_scaled_width();
}

float Viewport::get_x() const
{
    return (view_position[0]);
}

float Viewport::get_y() const
{
    return (view_position[1]);
}

void Viewport::set_x(float x)
{
    view_position[0] = x;
}

void Viewport::set_y(float y)
{
    view_position[1] = y;
}

Drawable* Viewport::get_object_to_track() const
{
    return (object_to_track);
}

