
#include <iostream>
#include <string>

#include "Engine.h"
#include "Main.h"

int main(int, char**)
{
    try
    {
        bool keep_playing = true;
        while (keep_playing)
        {
            Engine* engine = new Engine();
            keep_playing = engine->play();
            delete (engine);
        }
    }
    catch (const std::string& msg)
    {
        std::cerr << msg << std::endl;
    }
    catch (...)
    {
        std::cerr << "Game: exception thrown." << std::endl;
    }
    return (0);
}

