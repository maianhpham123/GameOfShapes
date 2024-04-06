//
//  enemy.cpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#include "enemy.hpp"

Enemy::Enemy(RenderWindow& window, const char* textureFile)
: Entity(window.loadTexture(textureFile)) {
    // Additional initialization for the Enemy class, if needed
}

void Enemy::update() {
    // Enemy-specific update logic
    // You can access the inherited member variables and functions from the Entity class
    // using the 'Entity::' scope resolution operator if necessary
    // ...
}
