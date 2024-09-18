#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2f.h"

class Transform
{
    public:
        float X , Y;

    public:
        Transform(float x = 0 ,float y = 0): X(x) , Y(y) {};
        void Log(){
            std::cout << X << ',' << Y << std::endl;
        }

    private:
        inline void TranslateX(float x){X += x;};
        inline void TranslateY(float y){Y += y;};
        inline Vector2f Translate(Vector2f &v){return Vector2f(X + v.X , Y + v.Y);};

};

#endif // TRANSFORM_H
