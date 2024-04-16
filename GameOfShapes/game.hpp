//
//  game.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef game_hpp
#define game_hpp

#include "defs.h"
#include "timer.hpp"
#include "renderWindow.hpp"
#include "entity.hpp"
#include "keyboardController.hpp"
#include "mouse.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "map.hpp"

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
    void checkCollision(); 
    void checkGameOver();

    RenderWindow window;
    KeyboardController keyboardController;
    Player player;
    Enemy enemy;
    Mouse mouse;
    Map map;
    Timer* timer;
    const int FRAME_RATE = 60;
    
    bool isRunning;
    bool gameOver;
};

#endif /* game_hpp */
