#include "Animation.h"

Animation::Animation()
{

}

void Animation::Draw(int x , int y , int Sprite_width , int Sprite_height)
{
    TextureManager::getTextureManager()->DrawFrame(TextureID , x , y , Sprite_width , Sprite_height , anmt_Frame , anmt_Row , anmt_flip);
}

void Animation::Update()
{
    anmt_Frame = (SDL_GetTicks() / anmt_AnimationSpeed) % anmt_TotalFrame;
}

void Animation::SetProperties(std::string id , int animtSpeed , int r , int total_frameCount , SDL_RendererFlip t_flip)
{
    TextureID = id;
    anmt_AnimationSpeed = animtSpeed;
    anmt_Row = r;
    anmt_TotalFrame = total_frameCount;
    anmt_flip = t_flip;

}
