
#include "Clock.h"

Clock& Clock::get_instance()
{
    static Clock clock;
    return (clock);
}

Clock::Clock() :
    FRAME_CAP_ON(false /* FIX ME */),
    PERIOD(0 /* FIX ME */),
    started(false),
    paused(false),
    frames(0),
    time_at_start(0),
    time_at_pause(0),
    current_ticks(0),
    previous_ticks(0),
    ticks(0)
{
}

unsigned int Clock::get_ticks() const
{
    if (paused)
    {
        return (time_at_pause);
    }
    else
    {
        return (SDL_GetTicks() - time_at_start);
    }
}

unsigned int Clock::get_elapsed_ticks()
{
    if (paused)
    {
        return (0);
    }
    current_ticks = this->get_ticks();
    ticks = current_ticks - previous_ticks;
    if (FRAME_CAP_ON && ticks < PERIOD)
    {
        return (0);
    }
    previous_ticks = current_ticks;
    return (ticks);
}

int Clock::get_fps() const
{
    if (this->get_seconds() > 0)
    {
        return (frames / this->get_seconds());
    }
    else
    {
        return (0);
    }
}

void Clock::increment_frame()
{
    if (!paused)
    {
        frames++;
    }
}

void Clock::start_clock()
{
    started = true;
    paused = false;
    frames = 0;
    time_at_pause = SDL_GetTicks();
    time_at_start = time_at_pause;
    previous_ticks = 0;
}

void Clock::pause()
{
    if (started && !paused)
    {
        time_at_pause = SDL_GetTicks() - time_at_start;
        paused = true;
    }
}

void Clock::resume()
{
    if (started && paused)
    {
        time_at_start = SDL_GetTicks() - time_at_pause;
        paused = false;
    }
}

bool Clock::is_started() const
{
    return (started);
}

bool Clock::is_paused() const
{
    return (paused);
}

unsigned int Clock::get_frames() const
{
    return (frames);
}

unsigned int Clock::get_seconds() const
{
    return (this->get_ticks() / 1000);
}

