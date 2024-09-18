#ifndef OBJECTS_H
#define OBJECTS_H


class Objects
{
    public:
        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual void CleanUp() = 0;
};

#endif // OBJECTS_H
