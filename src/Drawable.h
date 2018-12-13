
#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>
#include <string>

#include "Vector.h"

class Drawable
{
    public :
        Drawable(const std::string&, const Vector&, const Vector&, float);
        Drawable(const Drawable&);
        virtual ~Drawable() = 0;

        virtual void draw() const = 0;
        virtual void update(Uint32) = 0;
        float get_scale() const;
        void set_scale(float);
        virtual int get_scaled_width() const = 0;
        virtual int get_scaled_height() const = 0;
        const std::string& get_name() const;
        void set_name(const std::string&);
        /* FIX ME *///virtual const Image* get_image() const = 0;
        virtual const SDL_Surface* get_surface() const = 0;
        float get_x() const;
        void set_x(float);
        float get_y() const;
        void set_y(float);
        const Vector& get_velocity() const;
        void set_velocity(const Vector&);
        const Vector& get_position() const;
        void set_position(const Vector&);
        float get_velocity_x() const;
        float get_velocity_y() const;
        void set_velocity_x(float);
        void set_velocity_y(float);

    private :
        std::string name;
        Vector position;
        Vector velocity;
        float scale;
};

#endif

