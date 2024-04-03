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

class Entity
{
public:
    TransformComponent transform;
    
    Entity ();
    Entity(SDL_Texture* Texture);
        
    Entity(const Vector2D& position, SDL_Texture* Texture);
        
    void update();
    
    SDL_Texture* getTex(SDL_Texture* Texture);
    SDL_Texture* getTexture();

private:
    SDL_Rect collisionBox;
    SDL_Texture* texture;
};

#endif /* entity_hpp */
