//
//  pathfinding.hpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/28/24.
//

#ifndef pathfinding_hpp
#define pathfinding_hpp

#include "defs.h"
#include "vector2D.hpp"
#include <vector>
#include "searchCell.h"

class PathFinding {
public:
    PathFinding();
    ~PathFinding();
    
    void findPath(Vector2D& currentPos, Vector2D& targetPos);
    Vector2D nextPathPosition();
    
    void ClearOpenList() {
        openList.clear();
    }
    void clearVisitedList() {
        visitedList.clear();
    }
    void clearPathToGoal() {
        pathToGoal.clear();
    }
    
    bool initialisedStartGoal;
    bool foundGoal;
    
private:
    void setStartAndGoal (SearchCell& start, SearchCell& goal);
    void pathOpened (Vector2D& position, float newCost, SearchCell* parent);
    SearchCell* getNextCell();
    void ContinuePath();
    
    SearchCell* startCell;
    SearchCell* goalCell;
    vector<SearchCell*> openList;
    vector<SearchCell*> visitedList;
    vector<Vector2D*> pathToGoal;
};

#endif /* pathfinding_hpp */
