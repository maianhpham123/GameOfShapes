//
//  enemy.cpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#include "enemy.hpp"

Enemy::Enemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(418.0f, 200.0f), window.loadTexture(textureFile)) {
    // Additional initialization for the Enemy class, if needed
}

void Enemy::update() {
    // Enemy-specific update logic
    // You can access the inherited member variables and functions from the Entity class
    // using the 'Entity::' scope resolution operator if necessary
    // ...
}
