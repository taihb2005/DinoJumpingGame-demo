#include "Engine.h"
#include "Timer.h"

int main(int argv , char * args[])
{
    Engine::getEngine()->Init();

    while(Engine::getEngine()->getGameState())
    {

        Engine::getEngine()->CleanUp();
        Engine::getEngine()->Events();
        Engine::getEngine()->Update();
        Engine::getEngine()->Render();
        Timer::getInstance()->Tick();
    }


    Engine::getEngine()->Quit();

	return 0;
}
