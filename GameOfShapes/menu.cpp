//
//  menu.cpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#include "menu.hpp"
#include "buttons.cpp"

// menu.cpp
//TODO: need modifications, first steps done (that the program does work)

Menu::Menu(RenderWindow& Window, KeyboardController& KeyboardController)
    : window(Window), keyboardController(KeyboardController) {
        startButtonEntity = NULL;
        exitButtonEntity = NULL;
        result = MenuResult::None;
    }

void Menu::run() {
    bool running = true;
    
    // Load start button texture
    SDL_Texture* startButton = window.loadTexture("Large Buttons/New Game Button.png");
    
    // Load exit button texture
    SDL_Texture* exitButton = window.loadTexture("Large Buttons/Quit Button.png");
    
    // Create entities for buttons
    startButtonEntity = new Button(Vector2D(100.0f, 200.0f), window, "Large Buttons/New Game Button.png", "Start");
    exitButtonEntity = new Button(Vector2D(100.0f, 300.0f), window, "Large Buttons/Quit Button.png", "Exit");
    
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            
            // Pass the event to the keyboard controller
            keyboardController.handleEvents(event, *startButtonEntity);
            keyboardController.handleEvents(event, *exitButtonEntity);
        }
        
        // Render the menu
        window.clear();
        
        // Render the buttons
        window.render(*startButtonEntity);
        window.render(*exitButtonEntity);
        
        window.display();
    }
    
    // Clean up resources
    SDL_DestroyTexture(startButton);
    SDL_DestroyTexture(exitButton);
    
    delete startButtonEntity;
    delete exitButtonEntity;
}

bool Menu::isStartSelected() const
{
    return (result == MenuResult::Start);
}

bool Menu::isExitSelected() const
{
    return (result == MenuResult::Exit);
}
