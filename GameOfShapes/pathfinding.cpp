//
//  pathfinding.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/28/24.
//

#include "pathfinding.hpp"

PathFinding::PathFinding() {
    initialisedStartGoal = false;
    foundGoal = false;
}

PathFinding::~PathFinding() {}

void PathFinding::findPath(Vector2D& currentPos, Vector2D& targetPos) {
    if (!initialisedStartGoal) {
        for (int i = 0; i < openList.size(); i++) {
            delete openList[i];
        }
        openList.clear();
        
        for (int i = 0 ; i < visitedList.size(); i++) {
            delete visitedList[i];
        }
        visitedList.clear();
        
        for (int i = 0; i < pathToGoal.size(); i++) {
            delete pathToGoal[i];
        }
        pathToGoal.clear();
        
        //initialise start
        SearchCell start;
        start.position.x = currentPos.x;
        start.position.y = currentPos.y;
        
        //initialise goal
        SearchCell goal;
        goal.position.x = targetPos.x;
        goal.position.y = targetPos.y;
        
        setStartAndGoal(start, goal);
        initialisedStartGoal = true;
    }
    
    if (initialisedStartGoal) {
        ContinuePath();
    }
}

void PathFinding::setStartAndGoal(SearchCell& start, SearchCell& goal) {
    startCell = new SearchCell (start.position, NULL);
    goalCell = new SearchCell (goal.position, &goal);
    
    startCell->g = 0;
    startCell->h = startCell->getDistance(goalCell);
    startCell->parent = 0;
    
    openList.push_back(startCell);
}

SearchCell* PathFinding::getNextCell() {
    float bestF = numeric_limits<float>::max();
    int cellIndex = -1;
    SearchCell* nextCell = NULL;
    
    for (int i = 0; i < openList.size(); i++) {
        if (openList[i]->getf() < bestF) {
            bestF = openList[i]->getf();
            cellIndex = i;
        }
    }
    
    if (cellIndex >= 0) {
        nextCell = openList[cellIndex];
        visitedList.push_back(nextCell);
        openList.erase(openList.begin() + cellIndex);
    }
    
    return nextCell;
}

void PathFinding::pathOpened(Vector2D& position, float newCost, SearchCell* parent) {
    int id = position.y * WORLD_SIZE + position.x;
    for (int i = 0; i < visitedList.size(); i++) {
        if (id == visitedList[i]->id) {
            return;
        }
    }
    
    SearchCell* newChild = new SearchCell(position, parent);
    newChild->g = newCost;
    newChild->h = parent->getDistance(goalCell);
    
    for (int i = 0; i < openList.size(); i++) {
        if (id == openList[i]->id) {
            float newF = newChild->g + newCost + openList[i]->h;
            
            if (openList[i]->getf() > newF) {
                openList[i]->g = newChild->g + newCost;
                openList[i]->parent = newChild;
            }
            
            else //if the F is not better {
                delete newChild;
                return;
        }
    }
    
    openList.push_back(newChild);
}


void PathFinding::ContinuePath() {
    if (openList.empty()) {
        return;
    }
    
    SearchCell* currentCell = getNextCell();
    if (currentCell->id == goalCell->id) {
        goalCell->parent = currentCell->parent;
        SearchCell* getPath;
        
        for (getPath = goalCell; getPath != NULL; getPath = getPath->parent) {
            pathToGoal.push_back(new Vector2D(getPath->position));
        }
        
        foundGoal = true;
        return;
    }
    
    //TODO: finish the function
    else {
        //rightSide
        pathOpened(<#Vector2D &position#>, <#float newCost#>, <#SearchCell *parent#>);
        //leftSide
        //up
        //down
        //left-up diagonal
        //right-up diagonal
        //left-down diagonal
        //right-down diagonal
    }
}
