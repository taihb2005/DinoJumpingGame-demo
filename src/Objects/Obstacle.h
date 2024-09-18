#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObjects.h"

class Obstacle : public GameObjects
{
    public:
        //Obstacle();
        Obstacle(Properties * props):GameObjects(props){};

        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual void CleanUp() = 0;

    protected:

};

#endif // OBSTACLE_H
