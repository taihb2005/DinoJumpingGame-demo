#ifndef CACTUS_H
#define CACTUS_H

#include "Obstacle.h"
#include "Collider.h"
#include "RigidBody.h"
#include "Animation.h"

class Cactus : public Obstacle
{
    public:
        Cactus();
        virtual ~Cactus();
        Cactus(Properties * props);

        SDL_Rect getHitbox()
        {
            return Cactus_Collider->GetHitbox();
        }

        virtual void Draw();
        virtual void Update(float dt);
        virtual void CleanUp();

        virtual void Pause();

    protected:

        Collider * Cactus_Collider;
        RigidBody * Cactus_RigidBody;
        Animation * Cactus_Animator;


};

#endif // CACTUS_H
