
#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>

#include "Drawable.h"

class Sprite : public Drawable
{
    public :
        Sprite(const std::string&, float);
        Sprite(const Sprite&);

        virtual void draw() const;
        virtual void update(Uint32);
        virtual const Image* get_image() const;
        int get_scaled_width() const;
        int get_scaled_height() const;
        virtual const SDL_Surface* get_surface() const;

    private :
        std::vector<Image*> images;
        unsigned current_frame;
        unsigned num_frames;
        unsigned frame_interval;
        float time_since_last_frame;
        int world_width;
        int world_height;
        void advance_frame(Uint32);
        Sprite& operator=(const Sprite&);
};

#endif

