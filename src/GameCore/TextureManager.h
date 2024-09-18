#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Engine.h"
#include "Vector2f.h"
#include <string>
#include <map>

class TextureManager
{
    public:
        static TextureManager * getTextureManager();

        bool LoadFromFile(std::string id , const char * p_title);

        void Draw(std::string id , int x , int y , int width , int height , SDL_RendererFlip flip);

        void DrawFrame(std::string id , int x , int y , int width , int height , int frame , int row , SDL_RendererFlip flip = SDL_FLIP_NONE);

        void DrawTile(std::string id , int tilesize , int x , int y , int col , int row , SDL_RendererFlip flip = SDL_FLIP_NONE);

        void Drop(std::string id);

        void CleanUp();

    private:
        TextureManager(){};
        static TextureManager * p_TextureManager;
        std::map<std::string , SDL_Texture*> m_TextureMap;
};

#endif // TEXTUREMANAGER_H
