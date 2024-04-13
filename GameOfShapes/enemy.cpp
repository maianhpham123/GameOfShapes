//
//  enemy.cpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#include "enemy.hpp"

Enemy::Enemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(418.0f, 200.0f), window.loadTexture(textureFile)), rotationAngle(0.0f) {
    // Additional initialization for the Enemy class, if needed
}

SDL_Rect Enemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x;
    dstRect.y = transform.position.y;
    dstRect.w = 512;
    dstRect.h = 444;
    return dstRect;
}

void Enemy::update() {
    rotationAngle += 1.0f;
}

vector<Vector2D> Enemy::vertices() const {
    vector<Vector2D> enemyVertices;
    
    float vertex1X = (float) transform.position.x;
    float vertex1Y = (float) (transform.position.y + 444);
    float vertex2X = (float) (transform.position.x + 512 / 2);
    float vertex2Y = (float) transform.position.y;
    float vertex3X = (float) (transform.position.x + 512);
    float vertex3Y = (float) (transform.position.y + 444);
    
    enemyVertices.push_back(Vector2D(vertex1X, vertex1Y));
    enemyVertices.push_back(Vector2D(vertex2X, vertex2Y));
    enemyVertices.push_back(Vector2D(vertex3X, vertex3Y));
    
    return enemyVertices;
}


