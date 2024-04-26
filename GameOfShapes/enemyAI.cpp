//
//  enemyAI.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/23/24.
//

#include "enemyAI.hpp"

//TODO: fix the enemyAI class
AIEnemy::AIEnemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(1280.0f, 0.0f),window.loadTexture(textureFile)) {}

//TODO: rewrite this using Djikstra algorithm
/*
void AIEnemy::update(Map& map, Vector2D& playerPosition) {
    calculateShortestPath(map, playerPosition);
    
    if (!shortestPath.empty()) {
        Vector2D nextTile = shortestPath.back();
        transform.position = tileToWorld(nextTile, map);
        shortestPath.pop_back();
    }
}

void AIEnemy::calculateShortestPath(Map& map, const Vector2D& playerPosition) {
    const int rows = map.getRows(); //10
    const int cols = map.getCols(); //16
    
    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    std::unordered_map<int, Vector2D> previous;
    
    std::queue<Node> queue;
    Vector2D startPos = map.worldToTile(transform.position);
    Node startNode(startPos.x, startPos.y, 0);
    queue.push(startNode);
    distance[startPos.y][startPos.x] = 0;
    
    while (!queue.empty()) {
        Node current = queue.front();
        queue.pop();
        
        // Check if reached the player position
        if (current.x == playerPosition.x && current.y == playerPosition.y) {
            shortestPath.clear();
            Vector2D currentTile(current.x, current.y);
            shortestPath.push_back(currentTile);
            
            while (previous.find(current.y * cols + current.x) != previous.end()) {
                Vector2D prevTile = previous[current.y * cols + current.x];
                shortestPath.push_back(prevTile);
                current.x = prevTile.x;
                current.y = prevTile.y;
            }
            
            break;
        }
        
        // Get the neighbors of the current node
        vector<Vector2D> neighbors = getNeighbors(current.x, current.y, map);
        
        for (const Vector2D& neighbor : neighbors) {
            int neighborX = static_cast<int>(neighbor.x);
            int neighborY = static_cast<int>(neighbor.y);
            
            // Check if the neighbor is blocked
            if (map.getTileValue(neighborY, neighborX) != 0) {
                continue; // Skip blocked tiles
            }
            
            int newDistance = current.distance + 1;
            
            if (newDistance < distance[neighborY][neighborX]) {
                distance[neighborY][neighborX] = newDistance;
                Node newNode(neighborX, neighborY, newDistance);
                queue.push(newNode);
                previous[neighborY * cols + neighborX] = Vector2D(current.x, current.y);
            }
        }
    }
}

std::vector<Vector2D> AIEnemy::getNeighbors(int x, int y, Map& map) const {
    std::vector<Vector2D> neighbors;
    
    // Add the neighboring tiles (up, down, left, right)
    if (x > 0) {
        neighbors.push_back(Vector2D(x - 1, y));
    }
    if (x < map.getCols() - 1) {
        neighbors.push_back(Vector2D(x + 1, y));
    }
    if (y > 0) {
        neighbors.push_back(Vector2D(x, y - 1));
    }
    if (y < map.getRows() - 1) {
        neighbors.push_back(Vector2D(x, y + 1));
    }
    
    return neighbors;
}

Vector2D AIEnemy::tileToWorld(const Vector2D& tilePosition, const Map& map) const {
    // Calculate world position based on tile position and tile size
    const float tileSize = 80.0; // Replace with the actual tile size getter
    float worldX = tilePosition.x * tileSize;
    float worldY = tilePosition.y * tileSize;
    return Vector2D(worldX, worldY);
}
 */

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
