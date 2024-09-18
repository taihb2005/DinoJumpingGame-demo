#include "InputFromPlayer.h"


InputFromPlayer * InputFromPlayer:: Input = NULL;

InputFromPlayer::InputFromPlayer()
{
    m_KeyBoard = SDL_GetKeyboardState(NULL);
}

void InputFromPlayer::EventHandler()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT: Engine::getEngine()->setGameState(false); break;
            case SDL_KEYDOWN: KeyDown(); break;
            case SDL_KEYUP: KeyUp();break;
        }
    }
}

bool InputFromPlayer::isKeyDown(SDL_Scancode key)
{
    return m_KeyBoard[key];
}

void InputFromPlayer::KeyDown()
{
    m_KeyBoard = SDL_GetKeyboardState(NULL);
}

void InputFromPlayer::KeyUp()
{
    m_KeyBoard = SDL_GetKeyboardState(NULL);
}


