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
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

SDL_Texture* RenderWindow::loadTexture(const char* file) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, file);
    if (texture == NULL)
        logErrorAndExit("LoadTexture", IMG_GetError());
    return texture;
}

SDL_Renderer* RenderWindow::getRenderer() {
    return renderer;
}

void RenderWindow::render(Entity& entity) {
    SDL_Rect dstRect = entity.setDstRect(0, 0, 0, 0); 
    
    //SDL_RenderCopy(renderer, entity.getTexture(), NULL, &dstRect);
    SDL_RenderCopyEx(renderer, entity.getTexture(), NULL, &dstRect, entity.transform.rotation, NULL, SDL_FLIP_NONE);
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}
