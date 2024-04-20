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
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            tileMap[x][y] = rand() % 2;
        }
    }
    
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 10; y++) {
            if (tileMap[x][y] == 0 && countObstacles < maxObstacles)
                countObstacles++;
            else if (tileMap[x][y] == 0 && countObstacles >= maxObstacles) tileMap[x][y] = 1;
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

//TODO: has been modified
void Map::render() {
    /* for debugging and seeing the hidden map
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

//TODO: modify the checkTile
bool Map::checkTile(const Entity& entity) {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 8; y++) {
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
