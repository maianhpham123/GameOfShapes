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
#define WORLD_WIDTH 16
#define WORLD_HEIGHT 10
#define WORLD_SIZE (WORLD_WIDTH * WORLD_HEIGHT)

struct SearchCell {
public:
    int x, y;
    int id;
    SearchCell* parent;
    float g; //actual distance from start
    float h; //heuristic: estimation to the goal
    
    SearchCell() : parent(NULL) {}
    SearchCell(int X, int Y, SearchCell* Parent = NULL) : x(X), y(Y), parent(Parent), id(Y * WORLD_WIDTH + X), g(0), h(0) {}
    
    float getf() {
        return g+h;
    }
    
    //Manhattan Distance - approximation heuristics to calculate h
    float getDistance(SearchCell* nodeEnd) {
        float x = (float) abs((float) (this->x - nodeEnd->x));
        float y = (float) abs((float) (this->y - nodeEnd->y));
        return x + y;
    }
};

#endif /* searchCell_h */
