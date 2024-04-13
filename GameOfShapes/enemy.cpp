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

SDL_Rect Enemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x;  // Set the x-coordinate of the destination rectangle
    dstRect.y = transform.position.y;  // Set the y-coordinate of the destination rectangle
    dstRect.w = 512;  // Set the width of the destination rectangle
    dstRect.h = 444;  // Set the height of the destination rectangle
    // Additional calculations specific to the player's destination rectangle if needed
    return dstRect;
}

void Enemy::update() {
    // Enemy-specific update logic
    // You can access the inherited member variables and functions from the Entity class
    // using the 'Entity::' scope resolution operator if necessary
    // ...
}

/* used for checking AABB Collision
SDL_Rect Enemy::setCollisionBox(int x, int y, int width, int height) const {
    // Calculate the position and size of the triangle collision box
    SDL_Rect collisionBox;

    // Define the vertices of the triangle
    int vertex1X = transform.position.x;
    int vertex1Y = transform.position.y + 444;
    int vertex2X = transform.position.x + 512 / 2;
    int vertex2Y = transform.position.y;
    int vertex3X = transform.position.x + 512;
    int vertex3Y = transform.position.y + 444;

    // Calculate the bounding box that encloses the triangle
    collisionBox.x = std::min({vertex1X, vertex2X, vertex3X});
    collisionBox.y = std::min({vertex1Y, vertex2Y, vertex3Y});
    collisionBox.w = std::max({vertex1X, vertex2X, vertex3X}) - collisionBox.x;
    collisionBox.h = std::max({vertex1Y, vertex2Y, vertex3Y}) - collisionBox.y;

    return collisionBox;
}
 */

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
    
    //for debug
    //cout << enemyVertices[1].x << ", " << enemyVertices[1].y << endl;
    return enemyVertices;
}


