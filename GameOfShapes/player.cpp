//
//  player.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "player.hpp"
#include "entity.cpp"

Player::Player () {}

Player::Player(RenderWindow& renderer) : entity(renderer.loadTexture("yellow_circle.png")), renderer(renderer) {
    entity.transform.position = {0.0f, 0.0f};
}

void Player::handleInput() {
    // Handle player input here, e.g., update the entity's position based on keyboard input
}

void Player::update() {
    // Update player logic here, e.g., perform movement calculations or game-specific logic
}

void Player::render() {
    SDL_Rect dstRect = {
        static_cast<int>(entity.transform.position.x),
        static_cast<int>(entity.transform.position.y),
        64,
        64
    };

    SDL_RenderCopy(renderer.getRenderer(), entity.getTexture(), NULL, &dstRect);    
}

Entity Entity::getEntity() {
    return entity;
}
