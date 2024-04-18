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
    Map();
    ~Map();
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    virtual SDL_Rect setCollisionBox (int x, int y, int width, int height) const override;
    
    void generateMap();
    void checkTile(const Entity& entity);
    
    virtual void update() override;
    virtual void render() override;
    
private:
    SDL_Renderer* renderer;
    SDL_Rect tile[16][10];
    int tileMap[16][10];
};

#endif /* map_hpp */
