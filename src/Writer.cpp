
#include "Game_Data.h"
#include "Render_Context.h"
#include "Writer.h"

Writer& Writer::get_instance()
{
    static Writer writer;
    return (writer);
}

Writer::~Writer()
{
    for (auto& f : fonts)
    {
        TTF_CloseFont(f);
    }
    TTF_Quit();
}

Writer::Writer() :
    fonts()
{
    int init = TTF_Init();
    if (init == -1)
    {
        throw (std::string("Game couldn't initialize TTF."));
    }
    for (int i = 0; i < Game_Data::get_instance().get_xml_int("fonts/count");
            i++)
    {
        fonts.emplace_back(TTF_OpenFont(
                Game_Data::get_instance().get_xml_string(
                std::string("fonts/font") + std::to_string(i) +
                std::string("/file")).c_str(),
                Game_Data::get_instance().get_xml_int(
                std::string("fonts/font") + std::to_string(i) +
                std::string("/size"))));
    }
    if (fonts.size() == 0)
    {
        throw (std::string("Game couldn't find a font."));
    }
}

void Writer::write(const std::string& msg, int x, int y, int font,
        SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(fonts[font], msg.c_str(),
            color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(
            Render_Context::get_instance().get_renderer(), surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);
    SDL_Rect dst = {x, y, text_width, text_height};
    SDL_RenderCopy(Render_Context::get_instance().get_renderer(), texture,
            NULL, &dst);
    SDL_DestroyTexture(texture);
}

