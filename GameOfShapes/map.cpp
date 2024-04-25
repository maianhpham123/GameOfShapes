//
//  map.cpp
//  GameOfShapes
//
//  Created by mac on 4/14/24.
//

#include "map.hpp"

Map::Map(SDL_Renderer* Renderer) {
    renderer = Renderer;
    srand(static_cast <unsigned int>(time(NULL)));
    update();
}

Map::~Map() {}

SDL_Rect Map::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}

void Map::update() {
    int countObstacles = 0;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 16; y++) {
            tileMap[x][y] = rand() % 2;
        }
    }
    
    //TODO: Modify the map (after finishing the bullet and AI_Enemy class
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 16; y++) {
            if (tileMap[x][y] == 0 && countObstacles < maxObstacles)
                countObstacles++;
            else if (tileMap[x][y] == 0 && countObstacles >= maxObstacles) tileMap[x][y] = 1;
        }
    }
    
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 16; y++) {
            tile[x][y].x = x * 80;
            tile[x][y].y = y * 80;
            tile[x][y].w = 80;
            tile[x][y].h = 80;
        }
    }
}

//TODO: has been modified
void Map::render() {
    /* for debugging and seeing the hidden map */
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 8; y++) {
            if (tileMap[x][y] == 0) {
                SDL_Rect rect = setCollisionBox(tile[x][y].x, tile[x][y].y, 80, 80);
                SDL_RenderDrawRect(renderer, &rect);
                //cerr << "position of box: " << rect.x << "  " << rect.y << endl;
            }
        }
    }
    
}

SDL_Rect Map::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = x;
    collisionBox.y = y;
    collisionBox.w = 80;
    collisionBox.h = 80;
    //cerr << "position of collisionBox: " << collisionBox.x << " " << collisionBox.y << endl;
     
    return collisionBox;
}

//TODO: modify the checkTile
bool Map::checkTile(const Entity& entity) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 16; y++) {
            if (tileMap[x][y] == 0) {
                SDL_Rect tileCollisionBox = setCollisionBox(tile[x][y].x,tile[x][y].y,80,80);
                SDL_Rect entityCollisionBox = entity.setCollisionBox(0,0,0,0);
                if (SDL_HasIntersection(&tileCollisionBox, &entityCollisionBox)) {
                    SDL_Rect intersectRect;
                    SDL_IntersectRect(&tileCollisionBox, &entityCollisionBox, &intersectRect);
                    SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &intersectRect);
                    //cerr << "You have touched the map!" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int Map::getRows() {
    return 10;
}

int Map::getCols() {
    return 16;
}

Vector2D Map::worldToTile(const Vector2D& worldPosition) const {
    // Calculate tile position based on world position and tile size
    const float tileSize = 80.0f; // Replace with your actual tile size
    int tileX = static_cast<int>(worldPosition.x / tileSize);
    int tileY = static_cast<int>(worldPosition.y / tileSize);
    return Vector2D(tileX, tileY);
}

int Map::getTileValue(int row, int col) const {
    if (row >= 0 && row < 10 && col >= 0 && col < 16) {
        return tileMap[row][col];
    }

    // Handle invalid indices or out-of-bounds access
    // You can throw an exception, return a default value, or handle it based on your requirements.
    // Here, we return -1 to indicate an invalid or out-of-bounds access.
    return -1;
}

void Map::setTileValue(int row, int col, int value) {
    if (row >= 0 && row < 10 && col >= 0 && col < 16) {
        tileMap[row][col] = value;
    }
    // Handle invalid indices or out-of-bounds access if needed
}


