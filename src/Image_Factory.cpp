
#include <SDL_image.h>

#include "Image_Factory.h"
#include "Render_Context.h"
#include "Sprite_Sheet.h"

Image_Factory::Image_Factory() :
    game_data(Game_Data::get_instance()),
    surfaces(),
    textures(),
    images(),
    multisurfaces(),
    multitextures(),
    multiimages()
{
}

Image_Factory& Image_Factory::get_instance()
{
    static Image_Factory instance;
    return (instance);
}

Image_Factory::~Image_Factory()
{
    for (auto& s : surfaces)
    {
        SDL_FreeSurface(s.second);
    }
    for (auto& t : textures)
    {
        SDL_DestroyTexture(t.second);
    }
    for (auto& i : images)
    {
        delete (i.second);
    }
    for (auto& ss : multisurfaces)
    {
        for (unsigned int i = 0; i < ss.second.size(); i++)
        {
            SDL_FreeSurface(ss.second[i]);
        }
    }
    for (auto& ts : multitextures)
    {
        for (unsigned int i = 0; i < ts.second.size(); i++)
        {
            SDL_DestroyTexture(ts.second[i]);
        }
    }
    for (auto& is : multiimages)
    {
        for (unsigned int i = 0; i < is.second.size(); i++)
        {
            delete (is.second[i]);
        }
    }
}

Image* Image_Factory::get_image(const std::string& name)
{
    std::map<std::string, Image*>::const_iterator it = images.find(name);
    if (it == images.end())
    {
        SDL_Surface* surface = IMG_Load(game_data.get_xml_string(name +
                "/file").c_str());
        if (!surface)
        {
            throw (std::string("Game couldn't load ") + name +
                    std::string("."));
        }
        surfaces[name] = surface;
        Image* image = new Image(surface);
        images[name] = image;
        return (image);
    }
    else
    {
        return (it->second);
    }
}

std::vector<Image*> Image_Factory::get_images(const std::string& name)
{
    std::map<std::string, std::vector<Image*>>::const_iterator it = 
            multiimages.find(name);
    if (it != multiimages.end())
    {
        return (it->second);
    }
    std::string sheet_path = game_data.get_xml_string(name + "/file");
    SDL_Surface* surface = IMG_Load(sheet_path.c_str());
    if (!surface)
    {
        throw (std::string("Game couldn't load ") + name + std::string("."));
    }
    int num_frames = game_data.get_xml_int(name + "/frames");
    std::vector<Image*> iv;
    std::vector<SDL_Surface*> sv;
    std::vector<SDL_Texture*> tv;
    iv.reserve(num_frames);
    sv.reserve(num_frames);
    tv.reserve(num_frames);
    int w = surface->w / num_frames;
    int h = surface->h;
    Sprite_Sheet sheet(surface, w, h);
    for (int i = 0; i < num_frames; i++)
    {
        SDL_Surface* srfc = sheet.get(i);
        SDL_Texture* txtr = SDL_CreateTextureFromSurface(
                Render_Context::get_instance().get_renderer(), srfc);
        sv.push_back(srfc);
        tv.push_back(txtr);
        iv.push_back(new Image(srfc));
    }
    multisurfaces[name] = sv;
    multitextures[name] = tv;
    multiimages[name] = iv;
    return (iv);
}

