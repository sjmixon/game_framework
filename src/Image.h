
#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

class Image
{
    public :
        Image(SDL_Surface*);
        Image(const Image&);
        Image& operator=(const Image&);

        void regenerate_texture();
        void draw(int, int, float) const;
        void draw(int, int, int, int) const;
        int get_width() const;
        int get_height() const;
        SDL_Surface* get_surface() const;

    private :
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect view;

        Image();
};

#endif

