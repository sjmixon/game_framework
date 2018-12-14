
#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include <SDL.h>

class Render_Context
{
    public :
        ~Render_Context();

        static Render_Context& get_instance();
        SDL_Window* get_window() const;
        SDL_Renderer* get_renderer() const;

    private :
        SDL_Window* window;
        SDL_Renderer* renderer;

        Render_Context();
        Render_Context(const Render_Context&);
        Render_Context& operator=(const Render_Context&);

        SDL_Window* window_helper();
        SDL_Renderer* renderer_helper();
};

#endif

