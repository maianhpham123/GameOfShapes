//
//  entity.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "entity.hpp"
#include "vector2D.hpp"
#include "defs.h"
#include "renderWindow.hpp"
#include "transform.hpp"

Entity::Entity() {}
Entity::Entity(SDL_Texture* Texture) : texture(Texture) {}
Entity::Entity(const Vector2D& Position, SDL_Texture* Texture) {
        transform.position = Position;
        texture = Texture;    
}

SDL_Texture* Entity::getTex(SDL_Texture* Texture) {
    if (Texture == NULL)
        cout << "getTex is not performed!" << endl;
    return Texture;
}

SDL_Texture* Entity::getTexture() {
    return texture;
}

/* SDL_Rect Entity::setDstRect(int x, int y, int width, int height) {
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}
 */

/*
void Entity::update()
{
    transform.update();
}
*/
