
#include <string>

#include "Clock.h"
#include "Game_Data.h"
#include "Engine.h"
#include "Render_Context.h"

Engine::~Engine()
{
    for (auto w : worlds)
    {
        delete (w);
    }
    for (auto s : sprites)
    {
        delete (s);
    }
}

Engine::Engine() :
    renderer(Render_Context::get_instance().get_renderer()),
    worlds(),
    sprites(),
    current_sprite(0)
{
    Clock::get_instance().start_clock();
    worlds.push_back(new World(std::string("back"),
            Game_Data::get_instance().get_xml_int("back/factor")));
    sprites.push_back(new Sprite(std::string("yellow"), 1.0));
    sprites.push_back(new Sprite(std::string("spin"), 1.0));
    Viewport::get_instance().set_object_to_track(sprites[0]);
}

void Engine::draw()
{
    for (auto w : worlds)
    {
        w->draw();
    }
    for (auto s : sprites)
    {
        s->draw();
    }
    SDL_RenderPresent(renderer);
}

bool Engine::update(Uint32 ticks)
{
    for (auto w : worlds)
    {
        w->update();
    }
    for (auto s : sprites)
    {
        s->update(ticks);
    }
    Viewport::get_instance().update();
    return (false);
}

bool Engine::play()
{
    SDL_Event event;
    const Uint8* keystate;
    bool done = false;
    Uint32 ticks = Clock::get_instance().get_elapsed_ticks();
    while (!done)
    {
        while (SDL_PollEvent(&event))
        {
            keystate = SDL_GetKeyboardState(NULL);
            if (event.type == SDL_QUIT)
            {
                return (false);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (keystate[SDL_SCANCODE_ESCAPE] || keystate[SDL_SCANCODE_Q])
                {
                    return (false);
                }
            }
        }
        ticks = Clock::get_instance().get_elapsed_ticks();
        this->draw();
        done = this->update(ticks);
    }
    return (false);
}

