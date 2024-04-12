//
//  game.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "game.hpp"
#include "utils.hpp"
#include "renderWindow.cpp"
#include "vector2D.cpp"
#include "entity.cpp"
#include "transform.hpp"
#include "player.cpp"
#include "enemy.cpp"


/* Game::Game() : window(), platform(window.loadTexture("yellow_circle.png")), enemy(window.loadTexture("Simple Shapes/Triangle.png")), keyboardController(), isRunning(true) {}
 */

Game::Game() : window(), player(window, "yellow_circle.png"), enemy(window, "Simple Shapes/Triangle.png"), isRunning(true) {}


Game::~Game() {
    window.clean();
    SDL_Quit();
}

void Game::run() {
    
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();
    
    while (isRunning && !gameOver) {
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        if (frameTime > 0.25f)
            frameTime = 0.25f;

        currentTime = newTime;
        accumulator += frameTime;

        handleEvents();
        while (accumulator >= timeStep) {
            update();
            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;
        
        // update();
        checkCollision();
        checkGameOver();
        render();
    }
    
    if (gameOver) {
        cout << "End game!" << endl;
        isRunning = false;
    }
    
    SDL_Quit();
}


// Game.cpp

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            isRunning = false;
        else
            // keyboardController.handleEvents(event, platform);
            player.handleEvents(event);
    }
}

void Game::update() {
    // platform.update();
    player.update();
}

void Game::render() {
    window.clear();
    // window.render(platform);
    window.render(player);
    window.render(enemy);
    
    //TODO: put this to a seperate file
    /*SDL_Rect dstRect {SCREEN_WIDTH/2 - 222, 200, 512, 444};
    SDL_RenderCopy(window.getRenderer(), enemy.getTexture(), NULL, &dstRect);*/
    
    window.display();
}

/*
 //check AABB collision
 void Game::checkCollision() {
    SDL_Rect playerBox = player.setCollisionBox(0, 0, 0, 0);
    SDL_Rect enemyBox = enemy.setCollisionBox(0, 0, 0, 0);
    if(player.checkCollision(enemy)) {
        cerr << "Player Collision Box: " << playerBox.x << " " << playerBox.y << " " << playerBox.w << " " << playerBox.h << endl;
        cerr << "Enemy Collision Box: " << enemyBox.x << " " << enemyBox.y << " " << enemyBox.w << " " << enemyBox.h << endl;
        cout << "you have collided!" << endl;
    }
}
 */

void Game::checkCollision() {
    if (player.checkSATCollision(enemy)) {
        cerr << "You have collided!" << endl;
    }
}

void Game::checkGameOver() {
    const float entityWidth = 64.0f;
        const float entityHeight = 64.0f;
    
        const float playerX = player.transform.position.x;
        const float playerY = player.transform.position.y;

        const float screenLeft = 0;
        const float screenRight = SCREEN_WIDTH;
        const float screenTop = 0;
        const float screenBottom = SCREEN_HEIGHT;

        if (playerX < screenLeft ||
            playerX + entityWidth > screenRight ||
            playerY < screenTop ||
            playerY + entityHeight > screenBottom) {
            cerr << playerX << " " << playerY << endl;
            cerr << "is out of boundaries" <<endl;
            gameOver = true;
        }
}
