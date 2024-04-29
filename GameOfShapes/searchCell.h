//
//  searchCell.h
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/28/24.
//

#ifndef searchCell_h
#define searchCell_h

#include "defs.h"
#include <math.h>
#include "vector2D.hpp"

#define WORLD_SIZE 80

struct SearchCell {
public:
    Vector2D position;
    int id;
    SearchCell* parent;
    float g; //actual distance from start
    float h; //heuristic: estimation to the goal
    
    SearchCell() : parent(0) {}
    SearchCell(Vector2D _position, SearchCell* _parent = 0) : position(_position), parent(_parent), id(position.y * WORLD_SIZE + position.y), g(0), h(0) {}
    
    float getf() {
        return g+h;
    }
    
    float getDistance(SearchCell* nodeEnd) {
        float x = abs(this->position.x - nodeEnd->position.x);
        float y = abs(this->position.y - nodeEnd->position.y);
        return x + y;
    }
};

#endif /* searchCell_h */
