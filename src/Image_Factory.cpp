
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
        for (unsigned int i = 0; i < textures.second.size(); i++)
        {
            SDL_DestroyTexture(ts.second[i]);
        }
    }
    for (auto& is : multiimages)
    {
        for (unsigned int i = 0; i < images.second.size(); i++)
        {
            delete (is.second[i]);
        }
    }
}

Image* Image_Factory::get_image(const std::string& name)
{
    std::map<std::string, Image*>::const_iterator it = images.find(name);
    if (
    {
        SDL_Surface* surface = IMG_Load(filename.c_str());
    }
}

