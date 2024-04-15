//
//  mouse.cpp
//  GameOfShapes
//
//  Created by mac on 4/14/24.
//

#include "mouse.hpp"

Mouse::Mouse(SDL_Renderer* Renderer) {
    renderer = Renderer;
    prevMouseState = NULL;
    currMouseState = NULL;
    mouseX = 0;
    mouseY = 0;
}

Mouse::~Mouse() {}

void Mouse::update() {
    prevMouseState = currMouseState;
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    currMouseState = reinterpret_cast<const Uint8*>(&mouseState);
}

void Mouse::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = setDstRect(mouseX - 25, mouseY - 25, 50, 50);
    SDL_RenderDrawRect(renderer, &rect);
}

SDL_Rect Mouse::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;
    return dstRect;
}

void Mouse::handleEvents(SDL_Event& event) {
    keyboardController.handleEvents(event, *this);
}


int Mouse::getMouseX() const {
    return mouseX;
}

int Mouse::getMouseY() const {
    return mouseY;
}
