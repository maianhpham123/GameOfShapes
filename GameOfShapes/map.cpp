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
    /*
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            if (tileMap[x][y] == 0) {
                SDL_Rect rect = setCollisionBox(tile[x][y].x, tile[x][y].y, 80, 80);
                SDL_RenderDrawRect(renderer, &rect);
                //cerr << "position of box: " << rect.x << "  " << rect.y << endl;
            }
        }
    }
    */
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

void Map::generateMap() {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            if (tileMap[x][y] == 0) {
                SDL_Rect collisionBox = setCollisionBox(tile[x][y].x, tile[x][y].y, 80, 80);
                //cerr << "position of collisionBox: " << collisionBox.x << " " << collisionBox.y << endl;
                //cerr << "position of box: " << rect.x << "  " << rect.y << endl;
            }
        }
    }
}

bool Map::checkTile(const Entity& entity) {
    bool isCollided = false;
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            if (tileMap[x][y] == 0) {
                SDL_Rect tileCollisionBox = setCollisionBox(tile[x][y].x, tile[x][y].y, 80, 80);
                SDL_Rect playerCollisionBox = entity.setCollisionBox(0, 0, 0, 0);
                if (SDL_HasIntersection(&playerCollisionBox, &tileCollisionBox)) {
                    //cerr << "You have touched the map!" << endl;
                    isCollided = true;
                }
                else {
                    //cerr << "You in safety zone!" << endl;
                    isCollided = false;
                }
            }
        }
    }
    return isCollided;
}
