//
//  entity.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef entity_hpp
#define entity_hpp

#include "defs.h"

class Entity
{
public:
    Entity(float X, float Y, SDL_Texture* Texture);
    float getX();
    float getY();
    SDL_Texture* getTex();
    SDL_Rect getFrame();

private:
    float x, y;
    SDL_Rect frame;
    SDL_Texture* texture;
};

#endif /* entity_hpp */
