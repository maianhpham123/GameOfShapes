//
//  enemyAI.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/23/24.
//

#include "enemyAI.hpp"
#include "pathfinding.cpp"

AIEnemy::AIEnemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(1280.0f, 0.0f),window.loadTexture(textureFile)), pathfinding() {}

Vector2D AIEnemy::getPosition() {
    return transform.position;
}

void AIEnemy::enemyUpdate(const Entity& entity) {
    Vector2D currentPos = getPosition();
    Vector2D targetPos = entity.transform.position;
    
    //debug: done
    //cout << "PLayer Position: " << entity.transform.position.x << ", " << entity.transform.position.y << endl;
    
    pathfinding.findPath(currentPos, targetPos);
    
    Vector2D nextPos = pathfinding.nextPathPosition();
    
    //update the AI's movement towards next Position
    Vector2D direction = normalise(nextPos - currentPos);
    
    float speed = 10.0f; //TODO: modify with the suitable speed
    Vector2D velocity;
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;
    Vector2D newPosition = currentPos + velocity;
}

SDL_Rect AIEnemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x - 20;
    dstRect.y = transform.position.y - 20;
    dstRect.w = 40;
    dstRect.h = 40;
    return dstRect;
}

SDL_Rect AIEnemy::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x - 20;
    collisionBox.y = transform.position.y - 20;
    collisionBox.w = 40;
    collisionBox.h = 40;
    return collisionBox;
}
