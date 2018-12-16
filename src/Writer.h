
#ifndef WRITER_H
#define WRITER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>

class Writer
{
    public :
        ~Writer();

        static Writer& get_instance();
        void write(const std::string&, int, int, int, SDL_Color);

    private :
        std::vector<TTF_Font*> fonts;

        Writer();
        Writer(const Writer&);
        Writer& operator=(const Writer&);
};

#endif

