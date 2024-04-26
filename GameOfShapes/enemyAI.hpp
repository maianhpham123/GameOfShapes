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
    void update(Map& map, Vector2D& playerPosition);
    
private:
    struct Node {
        int x;
        int y;
        int distance;
        
        Node(int _x, int _y, int _distance) : x(_x), y(_y), distance(_distance) {}
    };
    
    /*
    std::vector<Vector2D> shortestPath;
    
    void calculateShortestPath(Map& map, const Vector2D& playerPosition);
    Vector2D tileToWorld(const Vector2D& tilePosition, const Map& map) const;
    std::vector<Vector2D> getNeighbors(int x, int y, Map& map) const;
     */
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;
};

#endif /* enemyAI_hpp */
