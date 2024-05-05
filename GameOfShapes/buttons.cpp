//
//  buttons.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 5/5/24.
//

#include "buttons.hpp"

Button::Button(const Vector2D& position, RenderWindow& window, const char* textureFile, const char* text)
    : Entity(position, window.loadTexture(textureFile)), buttonText(text) {}

void Button::render() {
    // Render the button-specific elements
    cerr << "Rendering Button: " << buttonText << endl;
}

SDL_Rect Button::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}

SDL_Rect Button::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = x;
    collisionBox.y = y;
    collisionBox.w = width;
    collisionBox.h = height;
    return collisionBox;
}
