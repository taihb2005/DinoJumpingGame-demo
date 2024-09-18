#include "Dinosaur.h"

const float JUMP_FORCE = 40.0f;

#include "Engine.h"

Dinosaur::Dinosaur(Properties * props) : Character(props)
{
    //isGrounded = true;
    JumpForce = -JUMP_FORCE;

    Dino_RigidBody = new RigidBody();
    Dino_RigidBody->setGravity(GRAVITY);

    Dino_Collider = new Collider();
    Dino_Collider->SetBuffer(24 , 4 , -40 , -9);

    Dino_Animator = new Animation;
    Dino_Animator->SetProperties(m_TextureID , 150 , 1 , 4 , SDL_FLIP_NONE);
}

void Dinosaur::Draw()
{
    if(isCrouching)
        Dino_Animator->Draw(m_Transform->X - 12 , m_Transform->Y + 10, 96 , 34);
    else
        Dino_Animator->Draw(m_Transform->X , m_Transform->Y , width , height);
}

void Dinosaur::HandleAnimationState()
{
    if(isCrouching)
    {
        Dino_Animator->SetProperties("dino_crouch" , 150 , 1 , 4 , SDL_FLIP_NONE);
    }

    if(isJumping)
    {
        Dino_Animator->SetProperties("dino_jump" , 100 , 1 , 1 , SDL_FLIP_NONE);
    }

    if(isFalling)
    {
        Dino_Animator->SetProperties("dino_fall" , 100 , 1 , 1 , SDL_FLIP_NONE);
    }


}
void Dinosaur::Update(float dt)
{
    //isGrounded = true;
    Dino_Animator->SetProperties(m_TextureID , 150 , 1 , 4 , SDL_FLIP_NONE);
    Dino_RigidBody->UnsetForce();
    //////////////////////////////////////////////////////////////////////////////


    //Jump
    if((InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_SPACE) || InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_UP)) && !InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_DOWN) && isGrounded)
    {
        isGrounded = false;
        isJumping = true;
        isFalling = false;
        Dino_RigidBody->SetForceY(JumpForce);
    }


    if(isJumping && JumpForce < 0 && !isGrounded)
    {
        JumpForce += 1;
        Dino_RigidBody->SetForceY(JumpForce);

    } else
    {
        JumpForce = -JUMP_FORCE;
        isJumping = false;
        //isFalling = true;
    }

    if((InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_DOWN) && !InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_UP)) && isGrounded)
    {
        isCrouching = true;
    } else
    {
        isCrouching = false;
    }

    if(InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_DOWN) && !isGrounded)
    {
        isJumping = false;
        Dino_RigidBody->UnsetForce();
        DinoGravity += 1;
        Dino_RigidBody->setGravity(DinoGravity);
    } else
    {
        Dino_RigidBody->setGravity(GRAVITY);
    }

    //fall
    if(Dino_RigidBody->getVelocity().Y > 0 && !isGrounded && !isJumping)
    {
        isFalling = true;
        DinoGravity += 0.7;
        Dino_RigidBody->setGravity(DinoGravity);
    } else
    {
        isGrounded = true;
        isFalling = false;
        Dino_RigidBody->setGravity(GRAVITY);
        DinoGravity = GRAVITY;
    }


        //std::cout << isGrounded << std::endl;


    //////////////////////////////////////////////////////////////////////////////
    /*Dino_RigidBody->Update(dt);
    m_LastSafePos.X = m_Transform->X;
    m_Transform->X += Dino_RigidBody->getPosition().X;
    Dino_Collider->SetHitbox(m_Transform->X , m_Transform->Y , width , height);
    if(CollisionHandler::getInstance()->MapCollision(Dino_Collider->GetHitbox()))
    {
        m_Transform->X = m_LastSafePos.X;
    }*/



    Dino_RigidBody->Update(dt);
    m_LastSafePos.Y = m_Transform->Y;
    m_Transform->Y += Dino_RigidBody->getPosition().Y;
    if(isCrouching){
        Dino_Collider->SetBuffer(24 , 4 , -47 , -9);
        Dino_Collider->SetHitbox(m_Transform->X - 10 , m_Transform->Y + 10 , 96 , 34);
    }
    else{
        Dino_Collider->SetBuffer(24 , 4 , -40 , -9);
        Dino_Collider->SetHitbox(m_Transform->X , m_Transform->Y , width , height);
    }
    if(m_Transform->Y > GROUND_H - height)
    {
           m_Transform->Y = m_LastSafePos.Y;
           isGrounded = true;
    } else
    {
        isGrounded = false;
    }

    //m_Transform->Y += Dino_RigidBody->getPosition().Y;
    HandleAnimationState();
    Dino_Animator->Update();
}

void Dinosaur::CleanUp()
{
    TextureManager::getTextureManager()->Drop(m_TextureID);
}

void Dinosaur::Pause()
{
    Dino_Animator->Draw(m_Transform->X , m_Transform->Y , width , height);
}

Dinosaur::~Dinosaur()
{
    free(Dino_RigidBody);
    free(Dino_Animator);
    free(Dino_Collider);
}

