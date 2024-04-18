//
//  bullet.hpp
//  GameOfShapes
//
//  Created by mac on 4/18/24.
//

#ifndef bullet_hpp
#define bullet_hpp

#include "entity.hpp"
#include "timer.hpp"
#include "maths.hpp"

class Bullet : public Entity {
public:
    Bullet(RenderWindow& window, const char* textureFile);
    ~Bullet();
    
    void fire(Vector2D pos);
    void reLoad();
    
    void update() override;
    void render() override;
    
    SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    
    SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;
    
private:
    const int OFFSCREEN_BUFFER = 10;
    Timer* timer;
    float speed;
    bool isFired;
};

#endif /* bullet_hpp */
