//
//  maths.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef maths_hpp
#define maths_hpp

#include <cmath>
#include "vector2D.hpp"

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

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

Vector2D rotateVector(Vector2D& vec, float angle) {
    float radAngle = (float) (angle * DEG_TO_RAD);
    return Vector2D((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}

#endif /* maths_hpp */
