#ifndef INPUTFROMPLAYER_H
#define INPUTFROMPLAYER_H

#include <SDL.h>
#include "Engine.h"

class InputFromPlayer
{
    public:
        InputFromPlayer();

        static InputFromPlayer * getInputInstance()
        {
            if(Input == NULL) Input = new InputFromPlayer();
            return Input;
        }

        void EventHandler();

        bool isKeyDown(SDL_Scancode Key);


    private:
        void KeyDown();
        void KeyUp();

        const Uint8 * m_KeyBoard;
        static InputFromPlayer * Input;
};

#endif // INPUTFROMPLAYER_H
