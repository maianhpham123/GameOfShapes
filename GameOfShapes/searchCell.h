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

//TODO: figure out the real world_size
#define WORLD_SIZE 80

struct SearchCell {
public:
    int x, y;
    int id;
    SearchCell* parent;
    float g; //actual distance from start
    float h; //heuristic: estimation to the goal
    
    SearchCell() : parent(0) {}
    SearchCell(int X, int Y, SearchCell* Parent = 0) : x(X), y(Y), parent(Parent), id(y * WORLD_SIZE + x), g(0), h(0) {}
    
    float getf() {
        return g+h;
    }
    
    //Manhattan Distance - approximation heuristics to calculate h
    float getDistance(SearchCell* nodeEnd) {
        float x = abs(this->x - nodeEnd->x);
        float y = abs(this->y - nodeEnd->y);
        return x + y;
    }
};

#endif /* searchCell_h */
