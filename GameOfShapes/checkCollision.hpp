//
//  checkCollision.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef checkCollision_hpp
#define checkCollision_hpp

#include <vector>
#include "vector2D.hpp"
#include "maths.hpp"

bool checkRectangleCollision (SDL_Rect rect1, SDL_Rect rect2) {
    return SDL_HasIntersection(&rect1, &rect2);
}

#endif /* checkCollision_hpp */
