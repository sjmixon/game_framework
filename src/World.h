
#ifndef WORLD_H
#define WORLD_H

#include <string>

#include "Drawable.h"
#include "Vector.h"
#include "Viewport.h"

class World
{
    public :
        World(const std::string&, int);
        void update();
        void draw() const;

    private :
        const Image* image;
        int factor;
        unsigned world_width;
        unsigned world_height;
        unsigned image_width;
        unsigned image_height;
        float view_x;
        float view_y;
        const Viewport& viewport;

        World(const World&);
        World& operator=(const World&);
};

#endif

