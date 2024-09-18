#include "Timer.h"

Timer * Timer:: m_Instance = NULL;

Timer::Timer()
{
    LastTime = 0;
}


void Timer::Tick()
{
    DeltaTime = (SDL_GetTicks() - LastTime) * (FPS / 1000.0f);

    if(DeltaTime > DESIRED_DELTATIME)
        DeltaTime = DESIRED_DELTATIME;

    LastTime = SDL_GetTicks();

}
