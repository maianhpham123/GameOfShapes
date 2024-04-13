//
//  player.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef player_hpp
#define player_hpp

#include <vector>
#include "entity.hpp"

class Player : public Entity {
public:
    Player(RenderWindow& window, const char* textureFile);
    void handleEvents(SDL_Event& event);
    void update() override;
    
    SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    
    vector<Vector2D> vertices() const override;
    
private:
    KeyboardController keyboardController;
};

#endif /* player_hpp */
