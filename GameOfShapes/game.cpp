//
//  game.cpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#include "game.hpp"
#include "timer.cpp"
#include "renderWindow.cpp"
#include "vector2D.cpp"
#include "mouse.cpp"
#include "entity.cpp"
#include "transform.hpp"
#include "player.cpp"
#include "enemy.cpp"
#include "defs.h"

Game::Game() : window(), player(window, "yellow_circle.png"), enemy(window, "Simple Shapes/Square.png"), isRunning(true), mouse(window.getRenderer()) {
    timer = Timer::Instance();
}


Game::~Game() {
    Timer::Release();
    timer = NULL;
    window.clean();
    SDL_Quit();
}

void Game::run() {
    
    while (isRunning && !gameOver) {
        timer->update();
        if (timer->DeltaTime() >= (1.0f / FRAME_RATE)) {
            handleEvents();
            update();
            checkCollision();
            checkGameOver();
            render();
            timer->Reset();
        }
    }
    
    if (gameOver) {
        cerr << "End game!" << endl;
        isRunning = false;
    }
    
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            isRunning = false;
        else
            player.handleEvents(event);
            mouse.handleEvents(event);
    }
}

void Game::update() {
    player.update();
    enemy.update();
    mouse.update();
}

void Game::render() {
    window.clear();
    window.render(player);
    window.render(enemy);
    enemy.transform.rotate(100 * timer->DeltaTime());
    mouse.render();
    window.display();
}

void Game::checkCollision() {
    if (player.checkRecCollision(enemy)) {
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
