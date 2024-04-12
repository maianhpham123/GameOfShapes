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

SDL_Renderer* RenderWindow::getRenderer() {
    return renderer;
}

int RenderWindow::getRefreshRate() {
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);
    return mode.refresh_rate;
}

/*void RenderWindow::render(Entity& entity) {
    SDL_Rect dstRect {(int)entity.transform.position.x, (int)entity.transform.position.y, 64, 64};
    SDL_RenderCopy(renderer, entity.getTexture(), NULL, &dstRect);
}
 */

void RenderWindow::render(Entity& entity) {
    SDL_Rect dstRect = entity.setDstRect(0,0,0,0); // Get the destination rectangle of the entity

    SDL_RenderCopy(renderer, entity.getTexture(), NULL, &dstRect); // Render the entity's texture
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
