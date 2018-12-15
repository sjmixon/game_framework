
#include "Image_Factory.h"
#include "World.h"

World::World(const std::string& name, int fact) :
    image(Image_Factory::get_instance().get_image(name)),
    factor(fact),
    world_width(Game_Data::get_instance().get_xml_int("world/width")),
    world_height(Game_Data::get_instance().get_xml_int("world/height")),
    image_width(image->get_width()),
    image_height(image->get_height()),
    view_x(0.0),
    view_y(0.0),
    viewport(Viewport::get_instance())
{
}

void World::update()
{
    view_x = static_cast<int>(viewport.get_x() / factor) % image_width;
    view_y = static_cast<int>(viewport.get_y() / factor) % image_height;
}

void World::draw() const
{
    image->draw(0, 0, -view_x, -view_y);
    image->draw(0, 0, image_width - view_x, -view_y);
    image->draw(0, 0, -view_x, image_height - view_y);
    image->draw(0, 0, image_width - view_x, image_height - view_y);
}

