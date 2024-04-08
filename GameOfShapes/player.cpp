//
//  player.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "player.hpp"

Player::Player(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(100.0f, 100.0f), window.loadTexture(textureFile)) {}

void Player::handleEvents(SDL_Event& event) {
    keyboardController.handleEvents(event, *this);
}

void Player::update() {
    transform.update();
}

SDL_Rect Player::setDstRect(int x, int y, int width, int height) const
{
    SDL_Rect dstRect;
    dstRect.x = x;  // Set the x-coordinate of the destination rectangle
    dstRect.y = y;  // Set the y-coordinate of the destination rectangle
    dstRect.w = width;  // Set the width of the destination rectangle
    dstRect.h = height;  // Set the height of the destination rectangle
    // Additional calculations specific to the player's destination rectangle if needed
    return dstRect;
}
