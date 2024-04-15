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
#include <vector>

class Map : public Entity {
public:
    Map();
    ~Map();
    
    virtual SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    
    virtual void update() override;
    virtual void render() override;
    
    SDL_Rect getDstRect() const;
    int* getTileMap();
    
    //TODO: get rid of this
    virtual vector<Vector2D> vertices() const override {
        vector<Vector2D> _mouse = {};
        return _mouse;
    }
    
private:
    
    int tileMap[16][10];
};

#endif /* map_hpp */
