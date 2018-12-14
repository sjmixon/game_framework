
#include "Image.h"
#include "Render_Context.h"
#include "Viewport.h"

Image::Image(SDL_Surface* surf) :
    renderer(Render_Context::get_instance().get_renderer()),
    surface(surf),
    texture(nullptr),
    view{0, 0, surf->w, surf->h}
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
    texture = SDL_CreateTextureFromSurface(
            Render_Context::get_instance().get_renderer(), surface);
}

Image::Image(const Image& image) :
    renderer(image.renderer),
    surface(image.surface),
    texture(image.texture),
    view(image.view)
{
}

int Image::get_width() const
{
    return (surface->w);
}

int Image::get_height() const
{
    return (surface->h);
}

SDL_Surface* Image::get_surface() const
{
    return (surface);
}

Image& Image::operator=(const Image& rhs)
{
    renderer = rhs.renderer;
    texture = rhs.texture;
    view = rhs.view;
    return (*this);
}

void Image::draw(int x, int y, float scale) const
{
    x -= Viewport::get_instance().get_x();
    y -= Viewport::get_instance().get_y();
    int temp_height = scale * view.h;
    int temp_width = scale * view.w;
    SDL_Rect dest = {x, y, temp_width, temp_height};
    SDL_RenderCopy(renderer, texture, &view, &dest);
}

