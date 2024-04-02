//
//  entity.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "entity.hpp"
#include "math.hpp"

Entity::Entity(Vector2D Pos, SDL_Texture* Texture) : pos(Pos), texture(Texture) {
    frame.x = 0;
    frame.y = 0;
}


SDL_Texture* Entity::getTex() {
    if (texture == NULL)
        cout << "getTex is not performed!" << endl;
    return texture;
}

SDL_Rect Entity::getFrame() {
    return frame;
}
