
#include <string>

#include "Game_Data.h"
#include "Render_Context.h"

Render_Context::Render_Context() :
    window(nullptr),
    renderer(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw (std::string("Game could not initialize SDL."));
    }
    window = window_helper();
    renderer = renderer_helper();
}

Render_Context::~Render_Context()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Render_Context& Render_Context::get_instance()
{
    static Render_Context instance;
    return (instance);
}

SDL_Window* Render_Context::get_window() const
{
    return (window);
}

SDL_Renderer* Render_Context::get_renderer() const
{
    return (renderer);
}

SDL_Window* Render_Context::window_helper()
{
    std::string title = Game_Data::get_instance().get_xml_string("title");
    int width = Game_Data::get_instance().get_xml_int("view/width");
    int height = Game_Data::get_instance().get_xml_int("view/height");
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        throw (std::string("Game couldn't make a window."));
    }
    return (window);
}

SDL_Renderer* Render_Context::renderer_helper()
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        throw (std::string("Game couldn't make a renderer."));
    }
    return (renderer);
}

