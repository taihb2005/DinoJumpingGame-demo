#ifndef DINOSAUR_H
#define DINOSAUR_H

#include "Character.h"
#include "TextureManager.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"
#include "CollisionHandler.h"


class Dinosaur : public Character
{
    public:
        Dinosaur();
        virtual ~Dinosaur();
        Dinosaur(Properties * props);

        SDL_Rect getHitbox()
        {
            return Dino_Collider->getHitbox();
        }

        Vector2f getDinoPosition()
        {
            return Dino_RigidBody->getPosition();
        }

        virtual void Draw();
        virtual void Update(float dt);
        virtual void CleanUp();

        virtual void Pause();

    protected:
        void HandleAnimationState();

        bool isCrouching;
        bool isGrounded;
        bool isJumping;
        bool isFalling;

        float JumpForce;
        float DinoGravity;

        RigidBody * Dino_RigidBody;
        Animation * Dino_Animator;
        Collider * Dino_Collider;

        Vector2f m_LastSafePos;

};

#endif // DINOSAUR_H
