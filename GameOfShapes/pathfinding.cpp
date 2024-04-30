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
        start.x = currentPos.x;
        start.y = currentPos.y;
        
        //initialise goal
        SearchCell goal;
        goal.x = targetPos.x;
        goal.y = targetPos.y;
        
        setStartAndGoal(start, goal);
        initialisedStartGoal = true;
    }
    
    if (initialisedStartGoal) {
        ContinuePath();
    }
}

void PathFinding::setStartAndGoal(SearchCell& start, SearchCell& goal) {
    startCell = new SearchCell (start.x, start.y, NULL);
    goalCell = new SearchCell (goal.x, goal.y, &goal);
    
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

void PathFinding::pathOpened(int X, int Y, float newCost, SearchCell* parent) {
    
    /*
    if (isCellBlocked) {
        return;
    }
     */
    
    int id = Y * WORLD_SIZE + X;
    for (int i = 0; i < visitedList.size(); i++) {
        if (id == visitedList[i]->id) {
            return;
        }
    }
    
    SearchCell* newChild = new SearchCell(X, Y, parent);
    newChild->g = newCost;
    newChild->h = parent->getDistance(goalCell);
    
    for (int i = 0; i < openList.size(); i++) {
        if (id == openList[i]->id) {
            float newF = newChild->g + newCost + openList[i]->h;
            
            if (openList[i]->getf() > newF) {
                openList[i]->g = newChild->g + newCost;
                openList[i]->parent = newChild;
            }
            
            //if the F is not better
            else {
                delete newChild;
                return;
            }
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
            pathToGoal.push_back(new Vector2D(getPath->x, getPath->y));
        }
        
        foundGoal = true;
        return;
    }
    
    //TODO: finish the function
    else {
        //rightSide
        pathOpened(currentCell->x + 1, currentCell->y, currentCell->g + 1, currentCell);
        //leftSide
        pathOpened(currentCell->x - 1, currentCell->y, currentCell->g + 1, currentCell);
        //up
        pathOpened(currentCell->x, currentCell->y - 1, currentCell->g + 1, currentCell);
        //down
        pathOpened(currentCell->x, currentCell->y + 1, currentCell->g + 1, currentCell);
        //left-up diagonal
        pathOpened(currentCell->x - 1, currentCell->y - 1, currentCell->g + 1.414f, currentCell);
        //right-up diagonal
        pathOpened(currentCell->x + 1, currentCell->y - 1, currentCell->g + 1.414f, currentCell);
        //left-down diagonal
        pathOpened(currentCell->x - 1, currentCell->y + 1, currentCell->g + 1.414f, currentCell);
        //right-down diagonal
        pathOpened(currentCell->x + 1, currentCell->y + 1, currentCell->g + 1.414f, currentCell);
        
        for (int i = 0; i < openList.size(); i++) {
            if (currentCell->id == openList[i]->id) {
                openList.erase(openList.begin() + i);
            }
        }
    }
}

Vector2D PathFinding::nextPathPosition() {
    int index = 1;
    Vector2D nextPos;
    nextPos.x = pathToGoal[pathToGoal.size() - index]->x;
    nextPos.y = pathToGoal[pathToGoal.size() - index]->y;

    Vector2D distance = nextPos - pos;

    if (index < pathToGoal.size()) {
        if (length(distance) < radius) {
            pathToGoal.erase(pathToGoal.end() - index);
        }
    }

    return nextPos;
}
