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
#include "keyboardController.hpp"


Game::Game() : window(), platform(window.loadTexture("yellow_circle.png")), enemy(window.loadTexture("Simple Shapes/Triangle.png")), keyboardController(), isRunning(true) {}
Game::~Game() {
    window.clean();
    SDL_Quit();
}

// Game.cpp

void Game::run() {
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (isRunning) {
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
        
        update();
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
            keyboardController.handleEvents(event, platform);
    }
}

void Game::update() {
    platform.update();
}

void Game::render() {
    window.clear();
    window.render(platform);
    
    //TODO: put this to a seperate file
    SDL_Rect dstRect {SCREEN_WIDTH/2 - 222, 200, 512, 444};
    SDL_RenderCopy(window.getRenderer(), enemy.getTexture(), NULL, &dstRect);
    window.display();
}

void Game::checkGameOver() {
    const float entityWidth = 64.0f;
    const float entityHeight = 64.0f;

    const float entityX = platform.transform.position.x;
    const float entityY = platform.transform.position.y;

    if (entityX < -SCREEN_WIDTH/2 || entityX > SCREEN_WIDTH/2 ||
        entityY < -SCREEN_HEIGHT/2 || entityY > SCREEN_HEIGHT/2) {
        gameOver = true;
    }
}
