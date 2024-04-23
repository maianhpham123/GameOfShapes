//
//  bullet.cpp
//  GameOfShapes
//
//  Created by mac on 4/18/24.
//

#include "bullet.hpp"

Bullet::Bullet(RenderWindow& window, const char* textureFile, Vector2D pos) : Entity(pos, window.loadTexture(textureFile)) {
    velocity = Vector2D(0.0f, 0.0f);
}

Bullet::~Bullet() {}

//TODO: finish this bullet class
void Bullet::update() {
    transform.position.x += velocity.x;
    transform.position.y += velocity.y;
}

void Bullet::render() {}

void Bullet::shoot(int mouseX, int mouseY) {
    int playerX = transform.position.x;
    int playerY = transform.position.y;
        
    Vector2D dir;
    dir.x = mouseX - playerX;
    dir.y = mouseY - playerY;
    
    Vector2D normalisedDir = normalise(dir);
            
    
        // Set the bullet's velocity based on the direction vector
    float bulletSpeed = 5.0f; // Adjust the bullet's speed as needed
    velocity.x = normalisedDir.x * bulletSpeed;
    velocity.y = normalisedDir.y * bulletSpeed;

        // Set the bullet's initial position
        transform.position.x = playerX;
        transform.position.y = playerY;
}

vector<Bullet*> Bullet::setBulletList () const {
    return bullet_list;
}

bool Bullet::isOutOfScreen() {
    const SDL_Rect ScreenSize = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
    return ((transform.position.x < 0) || (transform.position.y < 0) || (transform.position.x > ScreenSize.w) || (transform.position.y > ScreenSize.h));
    
}

SDL_Rect Bullet::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x - 15;
    dstRect.y = transform.position.y - 15;
    dstRect.w = 30;
    dstRect.h = 30;
    return dstRect;
}

SDL_Rect Bullet::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x - 15;
    collisionBox.y = transform.position.y - 15;
    collisionBox.w = 30;
    collisionBox.h = 30;
    return collisionBox;
}
