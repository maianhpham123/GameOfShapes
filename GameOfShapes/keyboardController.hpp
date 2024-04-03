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
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    cout << "left is pressed" << endl;
                    entity.transform.velocity.x = -1.0f;
                    break;
                case SDLK_RIGHT:
                    cout << "right is pressed" << endl;
                    entity.transform.velocity.x = 1.0f;
                    break;
                case SDLK_UP:
                    cout << "up is pressed" << endl;
                    entity.transform.velocity.y = -1.0f;
                    break;
                case SDLK_DOWN:
                    cout << "down is pressed" << endl;
                    entity.transform.velocity.y = 1.0f;
                    break;
            }
        }
        
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    cout << "left is not pressed" << endl;
                    entity.transform.velocity.x = 0.0f;
                    break;
                case SDLK_RIGHT:
                    cout << "right is not pressed" << endl;
                    entity.transform.velocity.x = 0.0f;
                    break;
                case SDLK_UP:
                    cout << "up is not pressed" << endl;
                    entity.transform.velocity.y = 0.0f;
                    break;
                case SDLK_DOWN:
                    cout << "down is not pressed" << endl;
                    entity.transform.velocity.y = 0.0f;
                    break;
            }
        }
    }
};

#endif /* keyboardController_hpp */
