//
//  bullet.cpp
//  GameOfShapes
//
//  Created by mac on 4/18/24.
//

#include "bullet.hpp"

Bullet::Bullet(RenderWindow& window, const char* textureFile) : Entity(window.loadTexture(textureFile)) {
    timer = Timer::Instance();
    speed = 500.0f;
    isFired = false;
}

Bullet::~Bullet() {
    timer = NULL;
}

void Bullet::fire(Vector2D pos) {
    isFired = true;
    position = pos;
}

void Bullet::reLoad() {
    isFired = false;
}

//TODO: finish this bullet class
void Bullet::update() {
    if (isFired) {
        Vector2D direction = position - transform.position;
        Vector2D dir = normalise(direction);
        
        Vector2D velocity;
        velocity.x = dir.x * speed * timer->DeltaTime();
        velocity.y = dir.y * speed * timer->DeltaTime();
        
        transform.position += velocity;
    }
}

void Bullet::render() {}

SDL_Rect Bullet::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x - 25;
    dstRect.y = transform.position.y - 25;
    dstRect.w = 50;
    dstRect.h = 50;
    return dstRect;
}

SDL_Rect Bullet::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x - 25;
    collisionBox.y = transform.position.y - 25;
    collisionBox.w = 50;
    collisionBox.h = 50;
    return collisionBox;
}
