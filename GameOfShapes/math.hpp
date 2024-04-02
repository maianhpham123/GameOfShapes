//
//  math.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef math_hpp
#define math_hpp

#include "defs.h"

struct Vector2D {
    Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D(float X, float Y) : x(X), y(Y) {}
    
    void print () {
        cout << x << ", " << y << endl;
    }
    
    float x, y;
    };

#endif /* math_hpp */
