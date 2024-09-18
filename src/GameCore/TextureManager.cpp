#include "TextureManager.h"


TextureManager* TextureManager:: p_TextureManager = NULL;

TextureManager * TextureManager::getTextureManager()
{
    if(p_TextureManager == NULL)
    {
        p_TextureManager = new TextureManager();
    }
    return p_TextureManager;
}

bool TextureManager::LoadFromFile(std::string id , const char * p_title)
{
    SDL_Surface * loadedSurface = NULL;
    SDL_Texture * p_Texture;

    loadedSurface = IMG_Load(p_title);
    if(loadedSurface == NULL)
    {
        SDL_Log("Failed to load image \" %s \" ! SDL Error: %s\n" , p_title , SDL_GetError());
        return false;
    }

    p_Texture = SDL_CreateTextureFromSurface(Engine::getEngine()->getRenderer() , loadedSurface);
    if(p_Texture == NULL)
    {
        SDL_Log("Failed to create texture from image \" %s \"! SDL Error: %s\n" , p_title , SDL_GetError());
        return false;
    }
    SDL_FreeSurface(loadedSurface);
    m_TextureMap[id] = p_Texture;
    return true;
}

void TextureManager::Draw(std::string id , int x , int y , int width , int height , SDL_RendererFlip flip = SDL_FLIP_NONE)
{
    SDL_Rect source = {0 , 0 , width , height};
    SDL_Rect dest = {x  , y , width , height};
    SDL_RenderCopyEx(Engine::getEngine()->getRenderer() , m_TextureMap[id] , &source , &dest , 0 , NULL , flip);
}

void TextureManager::DrawFrame(std::string id , int x , int y , int width , int height , int frame , int row , SDL_RendererFlip flip)
{
    SDL_Rect source = {width * frame , height * (row - 1) , width , height};
    SDL_Rect dest = {x , y , width , height};
    SDL_RenderCopyEx(Engine::getEngine()->getRenderer() , m_TextureMap[id] , &source , &dest , 0 , NULL , flip);
}

void TextureManager::DrawTile(std::string id, int tilesize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = { frame * tilesize, row * tilesize, tilesize, tilesize };
    SDL_Rect destRect = { x , y , tilesize, tilesize };
    SDL_RenderCopyEx(Engine::getEngine()->getRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::CleanUp()
{
    std::map<std::string , SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin() ; it != m_TextureMap.end() ; ++it)
    {
        SDL_DestroyTexture(it->second);
    }
    m_TextureMap.clear();

    SDL_Log("All textures has been destroyed!\n");
}

