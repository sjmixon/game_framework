
#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include <map>
#include <string>
#include <vector>

#include "Image.h"

class Image_Factory
{
    public :
        ~Image_Factory();

        static Image_Factory& get_instance();
        Image* get_image(const std::string&);
        std::vector<Image*> get_images(const std::string&);

    private :
        const Game_Data& game_data;
        std::map<std::string, SDL_Surface*> surfaces;
        std::map<std::string, SDL_Texture*> textures;
        std::map<std::string, Image*> images;
        std::map<std::string, std::vector<SDL_Surface*>> multisurfaces;
        std::map<std::string, std::vector<SDL_Surface*>> multitextures;
        std::map<std::string, std::vector<Image*>> multiimages;

        Image_Factory();
        Image_Factory(const Image_Factory&);
        Image_Factory& operator(const Image_Factory&);
};

#endif

