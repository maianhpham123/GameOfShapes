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
#include "checkCollision.hpp"

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

void Entity::update() {}

SDL_Rect Entity::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    // Additional calculations specific to the entity's destination rectangle if needed
    return dstRect;
}

//AABB collision: i dont want to delete because it's the most primitive way to check collision
/*
 bool Entity::checkCollision(const Entity& other) const {
    SDL_Rect collisionBox1 = setCollisionBox(collisionBox.x, collisionBox.y, collisionBox.w, collisionBox.h);
    SDL_Rect collisionBox2 = setCollisionBox(other.collisionBox.x, other.collisionBox.y, other.collisionBox.w, other.collisionBox.h);
    return SDL_HasIntersection(&collisionBox1, &collisionBox2) == SDL_TRUE;
}
 */

vector<Vector2D> Entity::vertices() const {
    return collisionVertices;
}

bool Entity::checkSATCollision (const Entity& other) const {
    bool isIntersect = Intersect(vertices(), other.vertices());
    if (isIntersect) return true;
    return false;
}
