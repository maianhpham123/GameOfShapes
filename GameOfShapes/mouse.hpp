//
//  mouse.hpp
//  GameOfShapes
//
//  Created by mac on 4/14/24.
//

#ifndef mouse_hpp
#define mouse_hpp

#include "defs.h"
#include "entity.hpp"

class Mouse : public Entity {
public:
    Mouse(SDL_Renderer* Renderer);
    ~Mouse();
    
    void update() override;
    void render() override;
    
    void handleEvents(SDL_Event& event);
    
    bool isButtonPressed(int button) const;
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox (int x, int y, int width, int height) const override;
    
    int getMouseX() const;
    int getMouseY() const;
    
private:
    const Uint8* prevMouseState;
    const Uint8* currMouseState;
    int mouseX;
    int mouseY;
    SDL_Renderer* renderer;
    KeyboardController keyboardController;
};

#endif /* mouse_hpp */
