
#include <cmath>

#include "Game_Data.h"
#include "Image_Factory.h"
#include "Sprite.h"

void Sprite::advance_frame(Uint32 ticks)
{
    time_since_last_frame += ticks;
    if (time_since_last_frame > frame_interval)
    {
        current_frame = (current_frame + 1) % num_frames;
        time_since_last_frame = 0;
    }
}

Sprite::Sprite(const std::string& name, float s) :
    Drawable(name, Vector(Game_Data::get_instance().get_xml_int(name +
            "/start/x"), Game_Data::get_instance().get_xml_int(name +
            "/start/y")), Vector(Game_Data::get_instance().get_xml_int(name +
            "/speed/x"), Game_Data::get_instance().get_xml_int(name +
            "/speed/y")), s),
    images(Image_Factory::get_instance().get_images(name)),
    current_frame(0),
    num_frames(Game_Data::get_instance().get_xml_int(name + "/frames")),
    frame_interval(Game_Data::get_instance().get_xml_int(name +
            "/frame_interval")),
    time_since_last_frame(0),
    world_width(Game_Data::get_instance().get_xml_int("world/width")),
    world_height(Game_Data::get_instance().get_xml_int("world/height"))
{
}

void Sprite::draw() const
{
    images[current_frame]->draw(this->get_x(), this->get_y(),
            this->get_scale());
}

void Sprite::update(Uint32 ticks)
{
    this->advance_frame(ticks);
    Vector incr = this->get_velocity() * static_cast<float>(ticks) * 0.001;
    this->set_position(this->get_position() + incr);
    if (this->get_y() < 0)
    {
        this->set_velocity_y(fabs(this->get_velocity_y()));
    }
    if (this->get_y() > world_height - this->get_scaled_height())
    {
        this->set_velocity_y(-fabs(this->get_velocity_y()));
    }
    if (this->get_x() < 0)
    {
        this->set_velocity_x(fabs(this->get_velocity_x()));
    }
    if (this->get_x() > world_width - this->get_scaled_width())
    {
        this->set_velocity_x(-fabs(this->get_velocity_x()));
    }
}

const Image* Sprite::get_image() const
{
    return (images[current_frame]);
}

int Sprite::get_scaled_height() const
{
    return (this->get_scale() * images[current_frame]->get_height());
}

int Sprite::get_scaled_width() const
{
    return (this->get_scale() * images[current_frame]->get_width());
}

const SDL_Surface* Sprite::get_surface() const
{
    return (images[current_frame]->get_surface());
}

