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

Entity::Entity() {}
Entity::Entity(SDL_Texture* Texture) : texture(Texture) {}
Entity::Entity(const Vector2D& position, SDL_Texture* Texture) {
        transform.position = position;
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

void Entity::update()
{
    transform.update();
}
