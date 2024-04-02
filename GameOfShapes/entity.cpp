//
//  entity.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "entity.hpp"

Entity::Entity(float X, float Y, SDL_Texture* Texture) : x(X), y(Y), texture(Texture) {
    frame.x = 0;
    frame.y = 0;
    frame.w = 64;
    frame.h = 64;
}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

SDL_Texture* Entity::getTex() {
    return texture;
}

SDL_Rect Entity::getFrame() {
    return frame;
}
