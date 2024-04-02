//
//  renderWindow.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "defs.h"
#include "renderWindow.hpp"
#include "entity.hpp"

RenderWindow::RenderWindow() : window(NULL), renderer(NULL) {
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
        logErrorAndExit("CreateWindow", SDL_GetError());
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
        logErrorAndExit("CreateRenderer", SDL_GetError());
}

SDL_Texture* RenderWindow::loadTexture(const char* file) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, file);
    if (texture == NULL)
        logErrorAndExit("LoadTexture", IMG_GetError());
    return texture;
}

void RenderWindow::render(Entity& entity) {
    SDL_Rect srcRect, dstRect;
    
    srcRect.x = entity.getFrame().x;
    srcRect.y = entity.getFrame().y;
    srcRect.w = entity.getFrame().w;
    srcRect.h = entity.getFrame().h;
    
    dstRect.x = entity.getPos().x;
    dstRect.y = entity.getPos().y;
    dstRect.w = 64;
    dstRect.h = 64;
    
    SDL_RenderCopy(renderer, entity.getTex(), NULL, &dstRect);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::clean() {
    SDL_DestroyWindow(window);
}
