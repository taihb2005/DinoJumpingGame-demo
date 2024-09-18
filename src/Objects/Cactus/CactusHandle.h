#ifndef CACTUSHANDLE_H
#define CACTUSHANDLE_H

#include <cstdlib>
#include <deque>

#include "Cactus.h"
#include "Dinosaur.h"

#include "TextureManager.h"
#include "CollisionHandler.h"

const int Cactus1_Width = 22;
const int Cactus1_Height = 28;

const int Cactus2_Width = 40;
const int Cactus2_Height = 28;

const int Cactus3_Width = 54;
const int Cactus3_Height = 28;

const int BigCactus_Width = 26;
const int BigCactus_Height = 34;

class CactusHandle
{
    public:
        static CactusHandle * getCactusInstance()
        {
            if(m_CactusInstance == NULL) m_CactusInstance = new CactusHandle();
            return m_CactusInstance;
        }


        void spawnCactus();

        Cactus *  spawnBig();
        Cactus *  spawnSmall();

        void placeCactus();
        void updateCactus(float dt);
        void pauseCactus();
        void clearCactus();


    private:
        CactusHandle();
        static CactusHandle * m_CactusInstance;

        //std::deque<Cactus*> QueueOfCactus;

        float timer;
        float LastTime;

};

#endif // CACTUSHANDLE_H
