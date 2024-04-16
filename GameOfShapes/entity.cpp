//
//  entity.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "entity.hpp"

Entity::Entity() {}
Entity::Entity(SDL_Texture* Texture) : texture(Texture) {}
Entity::Entity(const Vector2D& Position, SDL_Texture* Texture) {
        transform.position = Position;
        texture = Texture;
        transform.rotation = 0.0f;
}

SDL_Texture* Entity::getTexture() {
    return texture;
}

SDL_Rect Entity::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}

SDL_Rect Entity::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = x;
    collisionBox.y = y;
    collisionBox.w = width;
    collisionBox.h = height;
    return collisionBox;
}

float Entity::rotate(float Rotation) {
    transform.rotation = Rotation;
    if(transform.rotation > 360.0f)
        transform.rotation -= 360.0f;
    
    if(transform.rotation < 0.0f)
        transform.rotation += 360.0f;
    
    return transform.rotation;
}

void Entity::update() {}

void Entity::render() {}

bool Entity::checkRecCollision(const Entity& other) const {
    SDL_Rect const rect1 = setCollisionBox(0, 0, 0, 0);
    SDL_Rect const rect2 = other.setCollisionBox(0, 0, 0, 0);
    //SDL_Rect intersectRect;
    if (checkRectangleCollision(rect1, rect2)) {
        //TODO: put this into render function in game.cpp
        /*
        if (SDL_IntersectRect(&rect1, &rect2, &intersectRect)) {
            SDL_SetRenderDrawColor(getRenderer(), 255, 0, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(getRenderer(), &intersectRect);
        }
        */
        return true;
    }
    return false;
}
