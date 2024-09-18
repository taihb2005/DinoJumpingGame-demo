#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>


const int SCREEN_W = 848;
const int SCREEN_H = 320;
const int GROUND_H = 240;


class Engine
{
    public:
        static Engine * getEngine();

        bool getGameState();

        void setGameState(bool running);

        bool getTheGameIsPausing();

        void setTheGameIsPausing(bool running);

        bool getTheGameIsOver();

        void setTheGameIsOver(bool running);

        bool Init();

        void Render();

        void Events();

        void Pause();

        void Restart();

        void Update();

        void CleanUp();

        void Quit();

        SDL_Renderer * getRenderer(){return renderer;};




    private:
        Engine();
        static Engine * s_Engine;

        bool isTheGameIsPausing;
        bool isGameOver;
        bool isRunning;

        SDL_Window * window;
        SDL_Renderer * renderer;

};

#endif // ENGINE_H
