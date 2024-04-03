//
//  renderWindow.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef renderWindow_hpp
#define renderWindow_hpp

#include "defs.h"
#include "entity.hpp"

class RenderWindow
{
public:
    RenderWindow();
    SDL_Texture* loadTexture(const char* file);
    
    int getRefreshRate();
    
    SDL_Renderer* getRenderer();
    
    void render(Entity& entity);
    void clear();
    void display();
    void clean();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif /* renderWindow_hpp */
