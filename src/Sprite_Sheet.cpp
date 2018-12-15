
#include "Sprite_Sheet.h"

Sprite_Sheet::Sprite_Sheet(SDL_Surface* s, int w, int h) :
    src(s),
    view{0, 0, w, h},
    frames(s->w / w)
{
}
    
SDL_Surface* Sprite_Sheet::get(unsigned i)
{
    if (i > frames)
    {
        return (nullptr);
    }
    view.x = i * view.w;
    return (Sprite_Sheet::crop(src, &view));
}

SDL_Surface* Sprite_Sheet::crop(SDL_Surface* surf, const SDL_Rect* view)
{
    const auto* fmt = surf->format;
    SDL_Surface* sub = SDL_CreateRGBSurface(0, view->w, view->h,
            fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_BlitSurface(surf, view, sub, nullptr);
    return (sub);
}

