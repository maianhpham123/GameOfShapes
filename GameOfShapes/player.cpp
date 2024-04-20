//
//  player.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "player.hpp"

Player::Player(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(608.0f, 700.0f), window.loadTexture(textureFile)) {}

void Player::handleEvents(SDL_Event& event) {
    keyboardController.handleEvents(event, *this);
}

void Player::update() {
    transform.translate();
}

SDL_Rect Player::setDstRect(int x, int y, int width, int height) const
{
    SDL_Rect dstRect;
    dstRect.x = transform.position.x;
    dstRect.y = transform.position.y;
    dstRect.w = 64;
    dstRect.h = 64;
    return dstRect;
}

SDL_Rect Player::setCollisionBox(int x, int y, int width, int height) const
{
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x;
    collisionBox.y = transform.position.y;
    collisionBox.w = 64;
    collisionBox.h = 64;
    
    return collisionBox;
}
