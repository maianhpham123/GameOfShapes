//
//  game.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef game_hpp
#define game_hpp

#include "defs.h"
#include "renderWindow.hpp"
#include "entity.hpp"
#include "keyboardController.hpp"
#include "player.hpp"

class Game {
public:
    Game();
    ~Game();

    void run();
    void clean();

private:
    void handleEvents();
    void update();
    void render();
    void checkGameOver();

    RenderWindow window;
    KeyboardController keyboardController;
    Entity platform;
    Entity enemy;

    bool isRunning;
    bool gameOver;
};

#endif /* game_hpp */