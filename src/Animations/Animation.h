#ifndef ANIMATION_H
#define ANIMATION_H

#include "TextureManager.h"
#include <SDL.h>
#include <string>

class Animation
{
    public:
        Animation();

        void Draw(int x , int y , int Sprite_width , int Sprite_height);

        void Update();

        void SetProperties(std::string id , int AnimationSpeed , int Row , int TotalFrame , SDL_RendererFlip flip = SDL_FLIP_NONE);

    private:
        int anmt_AnimationSpeed , anmt_Frame , anmt_Row , anmt_TotalFrame;
        std::string TextureID;
        SDL_RendererFlip anmt_flip;
};

#endif // ANIMATION_H
