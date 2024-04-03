//
//  player.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef player_hpp
#define player_hpp

#include "entity.hpp"
#include "renderWindow.hpp"

class Player {
public:
    Player();
    Player(RenderWindow& renderer);
    void handleInput();
    void update();
    void render();

private:
    Entity entity; // Player entity
    RenderWindow& renderer;
};

#endif /* player_hpp */
