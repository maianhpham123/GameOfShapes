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

/*
vector<Vector2D> Entity::vertices() const {
    return collisionVertices;
}
 */

/*
bool Entity::checkSATCollision (const Entity& other) const {
    bool isIntersect = Intersect(vertices(), other.vertices());
    if (isIntersect) return true;
    return false;
}
 */

bool Entity::checkRecCollision(const Entity& other) const {
    if (checkRectangleCollision(collisionBox, other.collisionBox)) return true;
    return false;
}
