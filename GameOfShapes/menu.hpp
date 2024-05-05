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
#include "buttons.hpp"

enum class MenuResult {
    None, //TODO: what is it for?
    Start,
    Exit
};

class Menu {
public:
    Menu(RenderWindow& window, KeyboardController& keyboardController);
    ~Menu() {}
    void run();
    bool isStartSelected() const;
    bool isExitSelected() const;

private:
    RenderWindow& window;
    KeyboardController& keyboardController;
    Button* startButtonEntity;
    Button* exitButtonEntity;
    MenuResult result;
};

#endif /* menu_hpp */
