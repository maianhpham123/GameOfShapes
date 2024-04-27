//
//  map.hpp
//  GameOfShapes
//
//  Created by mac on 4/14/24.
//

#ifndef map_hpp
#define map_hpp

#include <iostream>
#include "entity.hpp"
#include <ctime>
#include <cstdlib>

class Map : public Entity {
public:
    Map(SDL_Renderer* Renderer);
    ~Map();
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox (int x, int y, int width, int height) const override;
    
    bool checkTile(const Entity& entity);
    
    virtual void update() override;
    virtual void render() override;
    
private:
    SDL_Renderer* renderer;
    SDL_Rect tile[10][16];
    int tileMap[10][16];
    const int maxObstacles = 10;
};

#endif /* map_hpp */
