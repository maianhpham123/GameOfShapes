//
//  transform.hpp
//  GameOfShapes
//
//  Created by mac on 4/3/24.
//

#ifndef transform_hpp
#define transform_hpp

#include "defs.h"
#include <cmath>
#include "maths.hpp"

class TransformComponent
{
public:
    Vector2D position;
    Vector2D velocity;
    float rotation;
    float sinValue;
    float cosValue;
    
    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
        rotation = 0.0f;
    }
    
    TransformComponent(Vector2D vec, float Rotation) {
        position.x = vec.x;
        position.y = vec.y;
        rotation = Rotation;
        sinValue = sin(Rotation);
        cosValue = cos(Rotation);
    }
    
    void init() {
        velocity.x = 0;
        velocity.y = 0;
    }
    
    void translate() {
        position.x += velocity.x * SPEED;
        position.y += velocity.y * SPEED;
    }
    
    void rotate(float amount) {
        rotation += amount;
    }
};

#endif /* transform_hpp */
