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

class Enemy : public Entity {
public:
    Enemy(RenderWindow& window, const char* textureFile);
    void update();
};

#endif /* enemy_hpp */
