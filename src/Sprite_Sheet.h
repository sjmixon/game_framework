
#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include <SDL.h>

class Sprite_Sheet
{
    public :
        Sprite_Sheet(SDL_Surface*, int, int);
        SDL_Surface* get(unsigned);

    private :
        SDL_Surface* src;
        SDL_Rect view;
        unsigned frames;
        static SDL_Surface* crop(SDL_Surface*, const SDL_Rect*);
};

#endif

