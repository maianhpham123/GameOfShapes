//
//  entity.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//
#ifndef entity_hpp
#define entity_hpp

#include "defs.h"
#include "transform.hpp"
#include "vector2D.hpp"

class Entity
{
public:
    TransformComponent transform;
    
    Entity ();
    Entity(SDL_Texture* Texture);
        
    Entity(const Vector2D& position, SDL_Texture* Texture);
        
    virtual void update();
    
    SDL_Texture* getTex(SDL_Texture* Texture);
    SDL_Texture* getTexture();
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const = 0;

private:
    SDL_Rect collisionBox;
    SDL_Rect dstRect;
    SDL_Texture* texture;
};

#endif /* entity_hpp */
