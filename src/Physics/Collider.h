#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL.h>

class Collider
{
    public:
        Collider(){};

        inline SDL_Rect getHitbox(){return m_Hitbox;};

        void SetBuffer(int x , int y , int w , int h)
        {
            m_Buffer = {x , y , w , h};
        }
        void SetHitbox(int x , int y , int w , int h)
        {
            m_Hitbox.x = x + m_Buffer.x;
            m_Hitbox.y = y + m_Buffer.y;
            m_Hitbox.w = w + m_Buffer.w;
            m_Hitbox.h = h + m_Buffer.h;
        }

        inline SDL_Rect GetHitbox(){return m_Hitbox;};

    private:
        SDL_Rect m_Hitbox;
        SDL_Rect m_Buffer;
};

#endif // COLLIDER_H
