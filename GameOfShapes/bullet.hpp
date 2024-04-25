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
#include <vector>

class Bullet : public Entity {
public:
    Bullet(RenderWindow& window, const char* textureFile, const Vector2D pos);
    ~Bullet();
    void update() override;
    void render() override;
    SDL_Rect setDstRect(int x, int y, int width, int height) const override;
    SDL_Rect setCollisionBox(int x, int y, int width, int height) const override;
    void shoot(int mouseX, int mouseY);
    vector<Bullet*> setBulletList () const;
    bool isOutOfScreen();
private:
    Vector2D velocity; // Bullet velocity
    vector<Bullet*> bullet_list; //the place to store bullet
};

#endif /* bullet_hpp */
