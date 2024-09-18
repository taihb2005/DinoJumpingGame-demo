#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include "InputFromPlayer.h"
#include "Timer.h"
#include "Globals.h"
#include "Cactus.h"
#include "CactusHandle.h"


Engine * Engine:: s_Engine = NULL;
Dinosaur * Dino1 = NULL;


Engine::Engine():isTheGameIsPausing(false) , isGameOver(false), isRunning(true) , window(NULL) , renderer(NULL)
{

}

Engine* Engine::getEngine()
{
    if(s_Engine == NULL) s_Engine = new Engine();
    return s_Engine;
}

bool Engine::getGameState()
{
    return isRunning;
}

void Engine::setGameState(bool running)
{
    isRunning = running;
}

bool Engine::getTheGameIsPausing()
{
    return isTheGameIsPausing;
}

void Engine::setTheGameIsPausing(bool running)
{
    isTheGameIsPausing = running;
}

bool Engine::getTheGameIsOver()
{
    return isGameOver;
}

void Engine::setTheGameIsOver(bool running)
{
    isGameOver = running;
}


bool Engine::Init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        success = false;
        printf("SDL could not initialized!\n");
    }

    if(!IMG_Init(IMG_INIT_PNG))
    {
        success = false;
        printf("IMG could not initialized! %s\n" , SDL_GetError());
    }

    if(success)
    {
        //SDL_WindowFlags m_window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
        window = SDL_CreateWindow("Game v1.0" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_W , SCREEN_H , SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            success = false;
            printf("Window has failed to create!\n! SDL Error : %s" , SDL_GetError());
        }

        renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(renderer == NULL)
        {
            success = false;
            printf("Renderer has failed to initialized!\n");;
        }
    }


    TextureManager::getTextureManager()->LoadFromFile("dino_run_an" , "asset/DinoCharacter/dino_run.png");
    TextureManager::getTextureManager()->LoadFromFile("dino_jump" , "asset/DinoCharacter/dino_jump.png");
    TextureManager::getTextureManager()->LoadFromFile("dino_fall" , "asset/DinoCharacter/dino_fall.png");
    TextureManager::getTextureManager()->LoadFromFile("dino_crouch" , "asset/DinoCharacter/dino_crouch.png");

    TextureManager::getTextureManager()->LoadFromFile("cactus1" , "asset/DinoCharacter/cactus1.png");
    TextureManager::getTextureManager()->LoadFromFile("cactus2" , "asset/DinoCharacter/cactus2.png");
    TextureManager::getTextureManager()->LoadFromFile("cactus3" , "asset/DinoCharacter/cactus3.png");
    TextureManager::getTextureManager()->LoadFromFile("bigcactus1.png" , "asset/DinoCharacter/bigcactus1.png");
    TextureManager::getTextureManager()->LoadFromFile("bigcactus2.png" , "asset/DinoCharacter/bigcactus2.png");
    TextureManager::getTextureManager()->LoadFromFile("bigcactus3.png" , "asset/DinoCharacter/bigcactus3.png");

    Dino1 = new Dinosaur(new Properties("dino_run_an" , 150 , GROUND_H - 44 , 61 , 44 , SDL_FLIP_NONE));


    return success;
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(renderer , 255 , 255 , 255 , 255);
    SDL_RenderClear(renderer);


    if(!isGameOver){
        Dino1->Draw();
        CactusHandle::getCactusInstance()->placeCactus();
    } else
    {
        Pause();
        if(InputFromPlayer::getInputInstance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            Restart();
            isGameOver = false;
        }
    }

    SDL_RenderPresent(renderer);
}

void Engine::Events()
{
    InputFromPlayer::getInputInstance()->EventHandler();
}


void Engine::Pause()
{
    Dino1->Pause();
    for(unsigned int i = 0 ; i < QueueOfCactus.size() ; i++)
    {
        QueueOfCactus[i]->Pause();
    }
}

void Engine::Restart()
{
    QueueOfCactus.clear();
    SDL_Delay(500);
}

void Engine::Update()
{
    float dt = Timer::getInstance()->getDeltatime();
    if(!isGameOver)
    {
        Dino1->Update(dt);
        CactusHandle::getCactusInstance()->updateCactus(dt);
    //CactusHandle::getCactusInstance()->updateTimer();
    }
}

void Engine::CleanUp()
{
    SDL_RenderClear(renderer);
}

void Engine::Quit()
{
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    TextureManager::getTextureManager()->CleanUp();
    CactusHandle::getCactusInstance()->clearCactus();

    IMG_Quit();
    SDL_Quit();

}
