//
//  enemy.hpp
//  GameOfShapes
//
//  Created by mac on 4/5/24.
//

#ifndef enemy_hpp
#define enemy_hpp

#include "entity.hpp"
#include <vector>

class Enemy : public Entity {
public:
    Enemy(RenderWindow& window, const char* textureFile);
    void update() override;
    SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    //vector<Vector2D> vertices() const override;
    
private:
};

#endif /* enemy_hpp */
