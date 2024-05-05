//
//  buttons.hpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 5/5/24.
//

#ifndef buttons_hpp
#define buttons_hpp

#include "defs.h"
#include "entity.hpp"

class Button : public Entity {
public:
    Button(const Vector2D& position, RenderWindow& window, const char* textureFile, const char* text);
    ~Button() {}
    
    void render() override;
    void update() override {}
    
    SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;

private:
    const char* buttonText;
};

#endif /* buttons_hpp */
