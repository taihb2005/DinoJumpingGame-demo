#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SDL.h>

#include "Engine.h"

class CollisionHandler
{
    public:

        bool CheckCollision(SDL_Rect  a , SDL_Rect  b);

        static CollisionHandler * getInstance(){
            if(m_Instance == NULL) m_Instance = new CollisionHandler();
            return m_Instance;
        }

    private:
        CollisionHandler();

        static CollisionHandler * m_Instance;

};

#endif // COLLISIONHANDLER_H
