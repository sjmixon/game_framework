
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <vector>

#include "Sprite.h"
#include "World.h"

class Engine
{
    public :
        Engine();
        ~Engine();
        bool play();

    private :
        SDL_Renderer* renderer;
        std::vector<World*> worlds;
        std::vector<Sprite*> sprites;
        int current_sprite;

        void draw();
        bool update(Uint32);

        Engine(const Engine&);
        Engine& operator=(const Engine&);
};

#endif

