//
//  transform.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef transform_hpp
#define transform_hpp

#include "vector2D.hpp"
#include "defs.h"

class TransformComponent
{
public:
    Vector2D position;
    Vector2D velocity;
    
    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(float X, float Y) {
        position.x = X;
        position.y = Y;
    }
    
    void init() {
        velocity.x = 0;
        velocity.y = 0;
    }
    
    void update() {
        position.x += velocity.x * SPEED;
        position.y += velocity.y * SPEED;
        cout << "(" << position.x << ", " << position.y << ")" << endl;
    }
};

#endif /* transform_hpp */