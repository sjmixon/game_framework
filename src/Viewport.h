
#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Drawable.h"

class Viewport
{
    public :
        static Viewport& get_instance();
        void update();
        Vector get_position() const;
        float get_x() const;
        void set_x(float);
        float get_y() const;
        void set_y(float);
        void set_object_to_track(Drawable* obj);
        Drawable* get_object_to_track() const;

    private :
        Vector view_position;
        int world_width;
        int world_height;
        int view_width;
        int view_height;
        int object_width;
        int object_height;
        Drawable* object_to_track;

        Viewport();
        Viewport(const Viewport&);
        Viewport& operator=(const Viewport&);
};

#endif

