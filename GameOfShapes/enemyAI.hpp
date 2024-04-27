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
#include <vector>
#include <queue>
#include <unordered_map>

class AIEnemy : public Entity {
public:
    AIEnemy(RenderWindow& window, const char* textureFile);
    
private:
    virtual void update() override;
    virtual void render() override;
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;
};

#endif /* enemyAI_hpp */
