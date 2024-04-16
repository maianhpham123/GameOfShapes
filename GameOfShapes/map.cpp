//
//  map.cpp
//  GameOfShapes
//
//  Created by mac on 4/14/24.
//

#include "map.hpp"

Map::Map() {
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

//TODO: make the map right, there is only one box being rendered
void Map::update() {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            tileMap[x][y] = rand() % 2;
        }
    }
    
    SDL_Rect tile[16][10];
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            tile[x][y].x = x * 80;
            tile[x][y].y = y * 80;
            tile[x][y].w = 80;
            tile[x][y].h = 80;
        }
    }
}

//TODO: correct this, there's nothing rendered on the screen
void Map::render() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            if (tileMap[x][y] == 1) {
                SDL_Rect rect = setCollisionBox(tile[x][y].x, tile[x][y].y, 80, 80);
                SDL_RenderDrawRect(renderer, &rect);
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
    return collisionBox;
}
