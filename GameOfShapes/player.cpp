//
//  player.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "player.hpp"

Player::Player(RenderWindow& window, const char* textureFile)
    : Entity(window.loadTexture(textureFile)) {}



void Player::handleEvents(SDL_Event& event) {
    keyboardController.handleEvents(event, *this);
}


