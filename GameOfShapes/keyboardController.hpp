//
//  keyboardController.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef keyboardController_hpp
#define keyboardController_hpp

#include "defs.h"
#include "transform.hpp"
#include "entity.hpp"

class KeyboardController {
public:
    void handleEvents(SDL_Event& event, Entity& entity) {
        switch (event.type) {
            case SDL_KEYDOWN:
                handleKeyDown(event, entity);
                break;
            case SDL_KEYUP:
                handleKeyUp(event, entity);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleMouseButtonDown(event, entity);
                break;
            case SDL_MOUSEBUTTONUP:
                handleMouseButtonUp(event, entity);
                break;
            case SDL_MOUSEMOTION:
                handleMouseMotion(event, entity);
                break;
            default:
                break;
        }
    }

private:
    void handleKeyDown(SDL_Event& event, Entity& entity) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                // cout << "left is pressed" << endl;
                entity.transform.velocity.x = -1.0f;
                break;
            case SDLK_a:
                // cout << "left is pressed" << endl;
                entity.transform.velocity.x = -1.0f;
                break;
            case SDLK_RIGHT:
                // cout << "right is pressed" << endl;
                entity.transform.velocity.x = 1.0f;
                break;
            case SDLK_d:
                // cout << "right is pressed" << endl;
                entity.transform.velocity.x = 1.0f;
                break;
            case SDLK_UP:
                // cout << "up is pressed" << endl;
                entity.transform.velocity.y = -1.0f;
                break;
            case SDLK_w:
                // cout << "up is pressed" << endl;
                entity.transform.velocity.y = -1.0f;
                break;
            case SDLK_DOWN:
                // cout << "down is pressed" << endl;
                entity.transform.velocity.y = 1.0f;
                break;
            case SDLK_s:
                // cout << "down is pressed" << endl;
                entity.transform.velocity.y = 1.0f;
                break;
        }
    }

    void handleKeyUp(SDL_Event& event, Entity& entity) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                // cout << "left is not pressed" << endl;
                entity.transform.velocity.x = 0.0f;
                break;
            case SDLK_a:
                // cout << "left is not pressed" << endl;
                entity.transform.velocity.x = 0.0f;
                break;
            case SDLK_RIGHT:
                // cout << "right is not pressed" << endl;
                entity.transform.velocity.x = 0.0f;
                break;
            case SDLK_d:
                // cout << "right is not pressed" << endl;
                entity.transform.velocity.x = 0.0f;
                break;
            case SDLK_UP:
                // cout << "up is not pressed" << endl;
                entity.transform.velocity.y = 0.0f;
                break;
            case SDLK_w:
                // cout << "up is not pressed" << endl;
                entity.transform.velocity.y = 0.0f;
                break;
            case SDLK_DOWN:
                // cout << "down is not pressed" << endl;
                entity.transform.velocity.y = 0.0f;
                break;
            case SDLK_s:
                // cout << "down is not pressed" << endl;
                entity.transform.velocity.y = 0.0f;
                break;
        }
    }

    void handleMouseButtonDown(SDL_Event& event, Entity& entity) {
        // Handle mouse button down event
        // You can add your custom logic here
    }

    void handleMouseButtonUp(SDL_Event& event, Entity& entity) {
        // Handle mouse button up event
        // You can add your custom logic here
    }

    void handleMouseMotion(SDL_Event& event, Entity& entity) {
        // Handle mouse motion event
        // You can add your custom logic here
        int mouseX = event.motion.x;
        int mouseY = event.motion.y;
        SDL_Rect rect = entity.setDstRect(0, 0, 0, 0);
        rect.x = mouseX;
        rect.y = mouseY;
        
        //cout << mouseX << " " << mouseY << endl;
    }
};

#endif /* keyboardController_hpp */
