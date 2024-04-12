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
    dstRect.x = transform.position.x;  // Set the x-coordinate of the destination rectangle
    dstRect.y = transform.position.y;  // Set the y-coordinate of the destination rectangle
    dstRect.w = 64;  // Set the width of the destination rectangle
    dstRect.h = 64;  // Set the height of the destination rectangle
    // Additional calculations specific to the player's destination rectangle if needed
    return dstRect;
}

/*
 SDL_Rect Player::setCollisionBox(int x, int y, int width, int height) const {
    // Calculate the position and size of the circle collision box
    int radius = 32;
    int centerX = transform.position.x + radius;
    int centerY = transform.position.y + radius;
    int diameter = radius * 2;

    // Create a rectangle that encloses the circle collision box
    SDL_Rect collisionBox;
    collisionBox.x = centerX - radius;
    collisionBox.y = centerY - radius;
    collisionBox.w = diameter;
    collisionBox.h = diameter;

    return collisionBox;
}
 */

//get the vertices
vector<Vector2D> Player::vertices() const {
    vector<Vector2D> playerVertices;
    int radius = 32;
    int centerX = transform.position.x + radius;
    int centerY = transform.position.y + radius;
    // int diameter = radius * 2;
    
    /*
    collisionBox.x = centerX - radius;
    collisionBox.y = centerY - radius;
    collisionBox.w = diameter;
    collisionBox.h = diameter;
    */
    
    playerVertices.push_back(Vector2D(centerX - radius, centerY - radius));
    playerVertices.push_back(Vector2D(centerX + radius, centerY - radius));
    playerVertices.push_back(Vector2D(centerX + radius, centerY + radius));
    playerVertices.push_back(Vector2D(centerX - radius, centerY + radius));
    
    return playerVertices;
}
