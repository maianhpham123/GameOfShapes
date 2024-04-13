//
//  defs.h
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef defs_h
#define defs_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Game of Shapes!"

#define SPEED 5

using namespace std;

void logErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s : %s", msg, error);
    SDL_Quit();
}

#endif /* defs_h */
