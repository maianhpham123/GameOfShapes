//
//  menu.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef menu_hpp
#define menu_hpp

#include "defs.h"
#include "renderWindow.hpp"
#include "keyboardController.hpp"

class Menu {
public:
    Menu(RenderWindow& renderer, KeyboardController& keyboardController);
    void run();

private:
    RenderWindow& renderer;
    KeyboardController& keyboardController;
};

#endif /* menu_hpp */
