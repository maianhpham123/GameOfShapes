//
//  menu.cpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#include "menu.hpp"

// menu.cpp
//TODO: fix

#include "menu.hpp"

Menu::Menu(RenderWindow& renderer, KeyboardController& keyboardController)
    : renderer(renderer), keyboardController(keyboardController) {}

void Menu::run() {
    bool running = true;
    
    // Load menu background texture
    SDL_Texture* background = renderer.loadTexture("path_to_background_texture.png");
    
    // Load start button texture
    SDL_Texture* startButton = renderer.loadTexture("path_to_start_button_texture.png");
    
    // Load exit button texture
    SDL_Texture* exitButton = renderer.loadTexture("path_to_exit_button_texture.png");
    
    // Create entities for buttons
    Entity startButtonEntity(startButton);
    Entity exitButtonEntity(exitButton);
    
    // Position the buttons on the screen
    // Adjust the coordinates according to your desired layout
    startButtonEntity.transform.position.x = 100;
    startButtonEntity.transform.position.y = 200;
    
    exitButtonEntity.transform.position.x = 100;
    exitButtonEntity.transform.position.y = 300;
    
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            
            // Pass the event to the keyboard controller
            keyboardController.handleEvents(event, startButtonEntity);
            keyboardController.handleEvents(event, exitButtonEntity);
        }
        
        // Render the menu
        renderer.clear();
        
        // Render the background
        renderer.render(background);
        
        // Render the buttons
        renderer.render(startButtonEntity);
        renderer.render(exitButtonEntity);
        
        renderer.display();
    }
    
    // Clean up resources
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(startButton);
    SDL_DestroyTexture(exitButton);
}
