#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <SDL.h>
#include "CactusHandle.h"

#define FPS 60
#define DESIRED_DELTATIME 1.5f

class Timer
{
    public:
        void Tick();

        static Timer * getInstance()
        {
            if(m_Instance == NULL)
                m_Instance = new Timer();
            return m_Instance;
        }

        float getDeltatime(){return DeltaTime;}

    private:
        Timer();
        static Timer * m_Instance;
        float DeltaTime;
        float LastTime;
};

#endif // TIMER_H
