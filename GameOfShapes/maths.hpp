//
//  maths.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef maths_hpp
#define maths_hpp

#include "vector2D.hpp"

float length(Vector2D a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

float distance(Vector2D a, Vector2D b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Vector2D normalise(Vector2D a){
    float length_a = length(a);
    float x = a.x / length_a;
    float y = a.y / length_a;
    return Vector2D(x, y);
}

float dotProduct (Vector2D a, Vector2D b) {
    return a.x * b.x + a.y * b.y;
}

float crossProduct (Vector2D a, Vector2D b) {
    return a.x * b.y - a.y * b.x;
}

#endif /* maths_hpp */
