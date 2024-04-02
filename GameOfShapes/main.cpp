//
//  main.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "renderWindow.cpp"
#include "entity.cpp"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        logErrorAndExit("InitialiseSDL", SDL_GetError());
    
    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
        logErrorAndExit("InitialiseImage", IMG_GetError());
    
    RenderWindow window;
    
    SDL_Texture* player = window.loadTexture("yellow_circle.png");
    Entity platform(Vector2D(100, 100), player);
    
    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }
        
        window.clear();
        window.render(platform);
        window.display();
    }

    window.clean();
    SDL_Quit();
}
