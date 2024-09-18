#include "Cactus.h"

Cactus::Cactus(Properties * props):Obstacle(props)
{
    Cactus_Collider = new Collider() ;
    Cactus_Collider->SetBuffer(0 , 0 , 0 , 0);

    Cactus_RigidBody = new RigidBody();
    Cactus_RigidBody->setGravity(0);


}

void Cactus::Draw()
{
    TextureManager::getTextureManager()->Draw(m_TextureID , m_Transform->X , GROUND_H - height , width , height , SDL_FLIP_NONE);
}

void Cactus::Update(float dt)
{
    Cactus_RigidBody->SetForceX(-20);
    Cactus_RigidBody->Update(dt);

    m_Transform->X += Cactus_RigidBody->getPosition().X;
    Cactus_Collider->SetHitbox(m_Transform->X , GROUND_H - height , width , height);

    if(m_Transform->X + width > 0)
        TextureManager::getTextureManager()->Draw(m_TextureID , m_Transform->X , SCREEN_H - height , width , height , SDL_FLIP_NONE);

}


void Cactus::CleanUp()
{
    TextureManager::getTextureManager()->Drop(m_TextureID);
}

void Cactus::Pause()
{
    TextureManager::getTextureManager()->Draw(m_TextureID , m_Transform->X , GROUND_H - height , width , height , SDL_FLIP_NONE);
}

Cactus::~Cactus()
{
    free(Cactus_Collider);
    free(Cactus_RigidBody);
}
