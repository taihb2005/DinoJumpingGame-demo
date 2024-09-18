#include "CollisionHandler.h"

CollisionHandler * CollisionHandler:: m_Instance = NULL;

CollisionHandler::CollisionHandler()
{

}

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    bool x_IsOverlap = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_IsOverlap = (a.y < b.y + b.h) && (a.y + a.h > b.y);
    return x_IsOverlap && y_IsOverlap;
}


