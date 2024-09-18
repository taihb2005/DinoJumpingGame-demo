#include "CactusHandle.h"
#include "Globals.h"

const float SPAWN_TIME = 1.5f;

CactusHandle * CactusHandle:: m_CactusInstance = NULL;
std::deque<Cactus*> QueueOfCactus(0);

CactusHandle::CactusHandle()
{
    QueueOfCactus.clear();
    LastTime = 0;
}



void CactusHandle::spawnCactus()
{
    timer = static_cast<float> (SDL_GetTicks() - LastTime) / static_cast<float> (1000.0f);

    if(timer >= SPAWN_TIME){

        float rng = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

        if(rng >= 0.90)
        {
            Cactus * BlockCactus = new Cactus(new Properties("cactus3" , SCREEN_W , GROUND_H - Cactus3_Height , Cactus3_Width , Cactus3_Height , SDL_FLIP_NONE));
            QueueOfCactus.push_back(BlockCactus);
        } else if(rng >= 0.70)
        {
            Cactus * BlockCactus = new Cactus(new Properties("cactus2" , SCREEN_W , GROUND_H - Cactus2_Height , Cactus2_Width , Cactus2_Height , SDL_FLIP_NONE));
            QueueOfCactus.push_back(BlockCactus);
        } else
        {
            Cactus * BlockCactus = new Cactus(new Properties("cactus1" , SCREEN_W , GROUND_H - Cactus1_Height , Cactus1_Width , Cactus1_Height , SDL_FLIP_NONE));
            QueueOfCactus.push_back(BlockCactus);
        }

        if(QueueOfCactus.size() > 4)
        {
            Cactus * Cactus_tmp = QueueOfCactus.front();
            QueueOfCactus.pop_front();
            free(Cactus_tmp);
        }

        LastTime = SDL_GetTicks();
    }

}

void CactusHandle::placeCactus()
{
    spawnCactus();
    for(unsigned i = 0 ; i < QueueOfCactus.size() ; i++)
    {
        QueueOfCactus[i]->Draw();
    }
}

void CactusHandle::updateCactus(float dt)
{

    for(unsigned int i = 0 ; i < QueueOfCactus.size() ; i++)
    {
        if(CollisionHandler::getInstance()->CheckCollision(Dino1->getHitbox() , QueueOfCactus[i]->getHitbox()))
        {
            Engine::getEngine()->setTheGameIsOver(true);
        }
        QueueOfCactus[i]->Update(dt);
    }
}


void CactusHandle::clearCactus()
{
    for(unsigned i = 0 ; i < QueueOfCactus.size() ; i++)
    {
        Cactus * Cactus_tmp = QueueOfCactus[i];
        QueueOfCactus.pop_front();
        free(Cactus_tmp);
    }

    QueueOfCactus.clear();
}
