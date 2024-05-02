//
//  enemyAI.hpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/23/24.
//

#ifndef enemyAI_hpp
#define enemyAI_hpp

#include "defs.h"
#include "entity.hpp"
#include "map.hpp"
#include <math.h>
#include "vector2D.hpp"
#include "pathfinding.hpp"
#include "maths.hpp"

class AIEnemy : public Entity {
public:
    AIEnemy(RenderWindow& window, const char* textureFile);
    Vector2D getPosition();
    
    void enemyUpdate (const Entity& entity);
    
    virtual void update() override {}
    virtual void render() override {}
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;
    
private:
    PathFinding pathfinding;
};

#endif /* enemyAI_hpp */
