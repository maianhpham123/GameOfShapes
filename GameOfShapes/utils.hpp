//
//  utils.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef utils_hpp
#define utils_hpp

#include <SDL2/SDL.h>

namespace utils
{
inline float hireTimeInSeconds() {
    float t = SDL_GetTicks();
    t *= 0.001f;
    return t;
}
}

#endif /* utils_hpp */
