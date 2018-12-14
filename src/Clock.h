
#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
    public :
        static Clock& get_instance();
        unsigned int get_ticks() const;
        unsigned int get_elapsed_ticks();
        void increment_frame();
        bool is_started() const;
        bool is_paused() const;
        unsigned int get_frames() const;
        unsigned int get_seconds() const;
        unsigned int cap_frame_rate() const;
        int get_fps() const;
        void start_clock();
        void pause();
        void resume();

    private :
        const bool FRAME_CAP_ON;
        const Uint32 PERIOD;

        bool started;
        bool paused;
        unsigned int frames;
        unsigned int time_at_start;
        unsigned int time_at_pause;
        unsigned int current_ticks;
        unsigned int previous_ticks;
        unsigned int ticks;

        Clock();
        Clock(const Clock&);
        Clock& operator=(const Clock&);
};

#endif

