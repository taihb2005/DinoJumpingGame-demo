#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "Objects.h"
#include <SDL.h>
#include "Transform.h"
#include <string>
#include "Point.h"

struct Properties{
    public:
        Properties(std::string id , float x , float y , int w , int h , SDL_RendererFlip t_flip){
            X = x;
            Y = y;
            width = w;
            height = h;
            flip = t_flip;
            TextureID = id;
        }
    public:
        float X , Y;
        int width;
        int height;
        std::string TextureID;
        SDL_RendererFlip flip;
};

class GameObjects : public Objects
{
    public:
        GameObjects(){};
        GameObjects(Properties * property)
        {
            m_Transform = new Transform();

            m_Transform->X = property->X;
            m_Transform->Y = property->Y;
            width = property->width;
            height = property->height;
            m_TextureID = property->TextureID;
            flip = property->flip;

            {
            float tmp_x = property->X + property->width / 2;
            float tmp_y = property->Y + property->height / 2;
            m_PointToSetCamera = new Point(tmp_x , tmp_y); //set at center of the object;
            }
        };

        inline Point * getCameraPoint(){return m_PointToSetCamera;};

        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual void CleanUp() = 0;

        virtual void Pause() = 0;

    protected:
        Transform * m_Transform;
        std::string m_TextureID;

        int width;
        int height;
        SDL_RendererFlip flip;

        Point * m_PointToSetCamera;
};

#endif // GAMEOBJECTS_H
