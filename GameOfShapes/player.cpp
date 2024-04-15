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

/*
vector<Vector2D> Player::vertices() const {
    vector<Vector2D> playerVertices;
    float radius = 30.0f;
    float centerX = (float) (transform.position.x + radius);
    float centerY = (float) (transform.position.y + radius);
    
    playerVertices.push_back(Vector2D(centerX - radius + 4.0f, centerY - radius + 4.0f));
    playerVertices.push_back(Vector2D(centerX + radius, centerY - radius + 4.0f));
    playerVertices.push_back(Vector2D(centerX + radius, centerY + radius));
    playerVertices.push_back(Vector2D(centerX - radius + 4.0f, centerY + radius));
    
    return playerVertices;
}
 */
