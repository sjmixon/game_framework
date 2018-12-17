
#include <string>

#include "Game_Data.h"
#include "Sound.h"

Sound::~Sound()
{
    for (auto& t : tracks)
    {
        Mix_FreeMusic(t);
    }
    Mix_CloseAudio();
}

Sound& Sound::get_instance()
{
    static Sound sound;
    return (sound);
}

Sound::Sound() :
    tracks(),
    effects()
{
    int channels = 2;
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, channels, 4096))
    {
        throw (std::string("Game unable to open audio."));
    }
    for (int i = 0; i < Game_Data::get_instance().get_xml_int("tracks/count");
            i++)
    {
        tracks.emplace_back(Mix_LoadMUS(
                (Game_Data::get_instance().get_xml_string(
                std::string("tracks/track") +
                std::to_string(i) + std::string("/file"))).c_str()));
    }
    for (int i = 0; i < Game_Data::get_instance().get_xml_int("effects/count");
            i++)
    {
        effects.emplace_back(Mix_LoadWAV(
                (Game_Data::get_instance().get_xml_string(
                std::string("effects/effect") +
                std::to_string(i) + std::string("/file"))).c_str()));
    }
}

void Sound::play_track(int index)
{
    Mix_VolumeMusic(SDL_MIX_MAXVOLUME / Game_Data::get_instance().get_xml_int(
            std::string("tracks/track") + std::to_string(index) +
            std::string("/volume")));
    Mix_PlayMusic(tracks[index], -1);
}

void Sound::play_effect(int index)
{
    Mix_VolumeChunk(effects[index], SDL_MIX_MAXVOLUME /
            Game_Data::get_instance().get_xml_int(
            std::string("effects/effect") + std::to_string(index) +
            std::string("/volume")));
    Mix_PlayChannel(-1, effects[index], 0);
}

void Sound::stop_track()
{
    Mix_HaltMusic();
}

