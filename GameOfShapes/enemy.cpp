//
//  enemy.cpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#include "enemy.hpp"

Enemy::Enemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(440.0f, 200.0f), window.loadTexture(textureFile)) {}

SDL_Rect Enemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x;
    dstRect.y = transform.position.y;
    dstRect.w = 400;
    dstRect.h = 400;
    return dstRect;
}

SDL_Rect Enemy::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x;
    collisionBox.y = transform.position.y;
    collisionBox.w = 450;
    collisionBox.h = 450;
    return collisionBox;
}

void Enemy::update() {}
void Enemy::render() {}


