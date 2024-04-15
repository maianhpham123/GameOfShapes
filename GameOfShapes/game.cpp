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


/* Game::Game() : window(), platform(window.loadTexture("yellow_circle.png")), enemy(window.loadTexture("Simple Shapes/Triangle.png")), keyboardController(), isRunning(true) {}
 */

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
    
    //TODO: draw the oriented bounding box to see the bug
    /*
    vector<Vector2D> enemyOrientedBoundingBox = enemy.vertices();
    vector<Vector2D> playerOrientedBoundingBox = player.vertices();
    
    for (int i = 0; i < (int) enemyOrientedBoundingBox.size(); i++) {
        Vector2D vec1 = enemyOrientedBoundingBox[i];
        Vector2D vec2 = enemyOrientedBoundingBox[(i+1) % (int) enemyOrientedBoundingBox.size()];
        SDL_SetRenderDrawColor(window.getRenderer(), 255, 0, 0, 255);
        SDL_RenderDrawLine(window.getRenderer(), vec1.x, vec1.y, vec2.x, vec2.y);
    }
    
    for (int i = 0; i < (int) playerOrientedBoundingBox.size(); i++) {
        Vector2D vec1 = playerOrientedBoundingBox[i];
        Vector2D vec2 = playerOrientedBoundingBox[(i+1) % (int) playerOrientedBoundingBox.size()];
        SDL_SetRenderDrawColor(window.getRenderer(), 255, 0, 0, 255);
        SDL_RenderDrawLine(window.getRenderer(), vec1.x, vec1.y, vec2.x, vec2.y);
    }
     */
    
    window.display();
}

void Game::checkCollision() {
    /*
    if (player.checkSATCollision(enemy)) {
        cout << "You have collided!" << endl;
        //for checking collision
        //gameOver = true; //it worked!
    }
    
    else cout << "nothing happens" << endl;
     */
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
