//
//  enemy.hpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#ifndef enemy_hpp
#define enemy_hpp

#include "entity.hpp"
#include "renderWindow.hpp"

/*class Enemy : public Entity {
public:
    Enemy(RenderWindow& window, const char* textureFile);
    void update();
};
 */

class Enemy : public Entity {
public:
    Enemy(RenderWindow& window, const char* textureFile);

    void update() override;

    SDL_Rect setDstRect(int x, int y, int width, int height) const override;

private:
    // Additional member variables specific to the Enemy class
};

#endif /* enemy_hpp */
