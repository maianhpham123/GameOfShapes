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
#include "renderWindow.hpp"
#include "checkCollision.hpp"
#include <vector>

class Entity
{
public:
    TransformComponent transform;
    
    Entity ();
    Entity(SDL_Texture* Texture);
    Entity(const Vector2D& position, SDL_Texture* Texture);
    
    virtual ~Entity() {}
    
    SDL_Texture* getTexture();
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const = 0;
    
    virtual SDL_Rect setCollisionBox(int x, int y, int width, int height) const = 0;
    
    float rotate (float Rotation);
    
    virtual void update();
    virtual void render();

    bool checkRecCollision(const Entity& other) const;
    
private:
    SDL_Texture* texture;
};

#endif /* entity_hpp */
