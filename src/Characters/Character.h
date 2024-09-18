#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObjects.h"


class Character : public GameObjects
{
    public:
        //Character(){};
        Character(Properties * props):GameObjects(props){};

        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual void CleanUp() = 0;
    protected:

};

#endif // CHARACTER_H
