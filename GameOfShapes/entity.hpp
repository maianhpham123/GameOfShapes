//
//  entity.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//
#ifndef entity_hpp
#define entity_hpp

#include "defs.h"
#include "math.hpp"

class Entity
{
public:
    Entity(Vector2D Pos, SDL_Texture* Texture);
    Vector2D& getPos() {
        return pos;
    }
    SDL_Texture* getTex();
    SDL_Rect getFrame();

private:
    Vector2D pos;
    SDL_Rect frame;
    SDL_Texture* texture;
};

#endif /* entity_hpp */
