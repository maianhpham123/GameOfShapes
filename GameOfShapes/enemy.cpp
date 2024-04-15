//
//  enemy.cpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#include "enemy.hpp"

Enemy::Enemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(384.0f, 144.0f), window.loadTexture(textureFile)) {}

SDL_Rect Enemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x;
    dstRect.y = transform.position.y;
    dstRect.w = 512;
    dstRect.h = 512;
    return dstRect;
}

void Enemy::update() {}

/*
vector<Vector2D> Enemy::vertices() const {
    vector<Vector2D> enemyVertices;
    
    float vertex1X = (float) transform.position.x;
    float vertex1Y = (float) transform.position.y;
    float vertex2X = (float) (transform.position.x + 512);
    float vertex2Y = (float) transform.position.y;
    float vertex3X = (float) (transform.position.x + 512);
    float vertex3Y = (float) (transform.position.y + 512);
    float vertex4X = (float) transform.position.x;
    float vertex4Y = (float) (transform.position.y + 512);
    
    enemyVertices.push_back(Vector2D(vertex1X, vertex1Y));
    enemyVertices.push_back(Vector2D(vertex2X, vertex2Y));
    enemyVertices.push_back(Vector2D(vertex3X, vertex3Y));
    enemyVertices.push_back(Vector2D(vertex4X, vertex4Y));
    
    return enemyVertices;
}
 */


