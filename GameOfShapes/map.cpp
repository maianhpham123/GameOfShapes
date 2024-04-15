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
    SDL_Rect dstRect = getDstRect();
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}

SDL_Rect getDstRect() {}
