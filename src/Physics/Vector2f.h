#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <iostream>
#include <string>

class Vector2f
{
    public:
       float X , Y;

    public:
        void Log()
        {
            std::cout<< X << ',' << Y << std::endl;
        }

    public:
        Vector2f(float x = 0 , float y = 0):X(x) , Y(y){};

        inline Vector2f operator+(const Vector2f & v) const{
            return Vector2f(X + v.X , Y + v.Y);
        }

        inline Vector2f operator-(const Vector2f & v) const{
            return Vector2f(X - v.X , Y - v.Y);
        }

        inline Vector2f operator*(float k) const{
            return Vector2f(X * k  ,  Y * k);
        }

        inline float operator^(Vector2f & v) const{
            return X * v.X + Y * v.Y;
        }


};

#endif // VECTOR2F_H
