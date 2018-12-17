
#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <vector>

class Sound
{
    public :
        ~Sound();

        static Sound& get_instance();
        void play_track(int);
        void play_effect(int);
        void stop_track();

    private :
        std::vector<Mix_Music*> tracks;
        std::vector<Mix_Chunk*> effects;

        Sound();
        Sound(const Sound&);
        Sound& operator=(const Sound&);
};

#endif

