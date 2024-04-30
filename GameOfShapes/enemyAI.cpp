//
//  enemyAI.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/23/24.
//

#include "enemyAI.hpp"

AIEnemy::AIEnemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(1280.0f, 0.0f),window.loadTexture(textureFile)) {}

void AIEnemy::update() {}
void AIEnemy::render() {}

void AIEnemy::pathfinding(const Map& map) {
    
}

SDL_Rect AIEnemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x - 20;
    dstRect.y = transform.position.y - 20;
    dstRect.w = 40;
    dstRect.h = 40;
    return dstRect;
}

SDL_Rect AIEnemy::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x - 20;
    collisionBox.y = transform.position.y - 20;
    collisionBox.w = 40;
    collisionBox.h = 40;
    return collisionBox;
}
