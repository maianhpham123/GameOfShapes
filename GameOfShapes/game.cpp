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
#include "map.cpp"
#include "bullet.cpp"
#include "enemyAI.cpp"
#include "menu.cpp"

//TODO: create a vector for bullet, each time of mouse down is a new bullet being released
//problem: the bullet has been initialised first
Game::Game() : window(), player(window, "yellow_circle.png"), enemy(window, "Simple Shapes/Square.png"), isRunning(true), mouse(window.getRenderer()), map(window.getRenderer()), menu(window, keyboardController)
{
    timer = Timer::Instance();
    map.update();
    
    //TODO: rewrite the constructor for this
    bullet = new Bullet(window, "yellow_circle.png", Vector2D(player.transform.position.x + 32, player.transform.position.y + 32));
    aienemy = new AIEnemy(window, "red_circle.png");
}


Game::~Game() {
    Timer::Release();
    timer = NULL;
    window.clean();
    
    delete bullet;
    delete aienemy;
    aienemy = NULL;
    SDL_Quit();
}

void Game::run() {
    
    bool isMenu = true; //TODO: add menu
    
    while (isRunning && !gameOver) {
        
        //TODO: fix Menu
        if (isMenu) {
            menu.run();
            if (menu.isStartSelected()) {
                isMenu = false;
            }
            
            else if (menu.isExitSelected()) {
                isRunning = false;
            }
        }
        
        else {
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
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                
                        int mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);
                        bullet->shoot(mouseX, mouseY);
            }
    }
}

void Game::update() {
    player.update();
    enemy.update();
    mouse.update();
    bullet->update();
    aienemy->enemyUpdate(player);
}

void Game::render() {
    window.clear();
    window.render(player);
    window.render(enemy);
    
    window.render(*aienemy);
    window.render(*bullet);
    
    enemy.transform.rotate(100 * timer->DeltaTime());
    mouse.render();
    map.render();
    
    if (mouse.checkRecCollision(enemy)) {
        SDL_Rect rect1 = mouse.setCollisionBox(0, 0, 0, 0);
        SDL_Rect rect2 = enemy.setCollisionBox(0, 0, 0,0);
        SDL_Rect rectIntersect;
        SDL_IntersectRect(&rect1, &rect2, &rectIntersect);
        SDL_SetRenderDrawColor(window.getRenderer(), 255, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(window.getRenderer(), &rectIntersect);
    }
    
    if (map.checkTile(mouse)) cerr << "Mouse has touched map" << endl;
    //else cerr << "Nothing has been touched!" << endl;
    
    window.display();
}

void Game::checkCollision() {
    if (player.checkRecCollision(enemy)) {
        cerr << "You have collided!" << endl;
    }
    
    if (map.checkTile(player)) cerr << "You have touched the map!" << endl;
    //else cerr << "You in safety zone!" << endl;
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
            //cerr << playerX << " " << playerY << endl;
            cerr << "is out of boundaries" <<endl;
            gameOver = true;
        }
}
