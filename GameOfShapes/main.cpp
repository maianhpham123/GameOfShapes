// main.cpp

#include "game.cpp"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        logErrorAndExit("InitialiseSDL", SDL_GetError());

    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
        logErrorAndExit("InitialiseImage", IMG_GetError());

    Game game;
    game.run();

    return 0;
}
