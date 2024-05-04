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
    
    startCell = NULL;
    goalCell = NULL;
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
        
        //debug: done!
        //cerr << "Start position: " << start.x << ", " << start.y << endl;
        //cerr << "End position: " << goal.x << ", " << goal.y << endl;
    }
    
    if (initialisedStartGoal) {
        ContinuePath();
    }
}

void PathFinding::setStartAndGoal(SearchCell& start, SearchCell& goal) {
    startCell = new SearchCell (start.x, start.y, NULL);
    goalCell = new SearchCell (goal.x, goal.y, &goal);
    
    //debug: done
    //cerr << "Start id: " << startCell->id << endl;
    //cerr << "Goal id: " << goalCell->id << endl;
    
    startCell->g = 0;
    startCell->h = startCell->getDistance(goalCell);
    startCell->parent = NULL;
    
    openList.push_back(startCell);
    
    //debug: done
    //cerr << "Start Cell: " << start.x << ", " << start.y << endl;
    //cerr << "Goal Cell: " << goal.x << ", " << goal.y << endl;
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
    
    //debug: done
    //cerr << "Next Cell: " << nextCell->x << ", " << nextCell->y << endl;
    //cerr << "Next cell's id: " << nextCell->id << endl;
    
    return nextCell;
}

void PathFinding::pathOpened(int X, int Y, float newCost, SearchCell* parent) {
    
    
    //TODO: make it avoid the obstacles in map
    /*
    if (isCellBlocked) {
        return;
    }
     */
    
    int id = Y * WORLD_WIDTH + X;
    for (int i = 0; i < visitedList.size(); i++) {
        
        //debug: done
        //cerr << "Visited: " << visitedList[i]->x << ", " << visitedList[i]->y << endl;
        
        if (id == visitedList[i]->id) {
            //debug: done
            //cerr << "id: " << id << endl;
            return;
        }
    }
    
    SearchCell* newChild = new SearchCell(X, Y, parent);
    newChild->g = newCost;
    newChild->h = parent->getDistance(goalCell);
    
    for (int i = 0; i < openList.size(); i++) {
        if (id == openList[i]->id) {
            //debug: done
            //cerr << "id: " << id << endl;
            
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
    
    //debug: done
    //cerr << "cost: " << newCost << endl;
    //cerr << "heuristics: " << newChild ->h << endl;
    //cerr << endl;
}


void PathFinding::ContinuePath() {
    if (openList.empty()) {
        return;
    }
    
    SearchCell* currentCell = getNextCell();
    //debug: done
    //cerr << "Cell: " << currentCell->x << ", " << currentCell->y << endl;
    
    //debug: done
    //cerr << "Current cell id: " << currentCell->id << endl;
    //cerr << "Goal cell id: " << goalCell->id << endl;
    //cout << endl;
    //cerr << "Current cell coords: " << currentCell->x << ", " << currentCell->y << endl;
    //cerr << "Goal cell coords: " << goalCell->x << ", " << goalCell->y << endl;
    //cout << endl;
    
    if (currentCell->id == goalCell->id) {
        //debug
        //cerr << "id: " << currentCell->id << endl;
        
        goalCell->parent = currentCell->parent;
        SearchCell* getPath;
        
        for (getPath = goalCell; getPath != NULL; getPath = getPath->parent) {
            if (getPath == NULL) {
                cerr << "Error: getPath is NULL" << endl;
                break;
            }
            
            pathToGoal.push_back(new Vector2D(getPath->x, getPath->y));
            
            //debug
            //TODO: it works
            //cerr << "Next path: " << getPath->x << ", " << getPath->y << endl;
        }
        
        foundGoal = true;
        return;
    }
    
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

Vector2D PathFinding::nextPathPosition(const Entity& entity) {
    int index = 1;
    
    Vector2D nextPos;
    
    if (!pathToGoal.empty()) {
         if (index <= pathToGoal.size()) {
             nextPos.x = pathToGoal[pathToGoal.size() - index]->x;
             nextPos.y = pathToGoal[pathToGoal.size() - index]->y;
             index++;
             
             // Debug
             //cerr << "Path position: " << nextPos.x << ", " << nextPos.y << endl;
         }
         else {
             cerr << "Index out of range: " << index << endl;
         }
     }
    
     else {
         cerr << "No path available!" << endl;
     }
     
    Vector2D distance = nextPos - entity.transform.position;
    //cerr << "Distance: " << distance.x << ", " << distance.y << endl;
     
     if (index < pathToGoal.size()) {
         if (length(distance) < radius) {
             pathToGoal.erase(pathToGoal.end() - index);
         }
     }
    
    //cerr << "Path position: " << nextPos.x << ", " << nextPos.y << endl;
    return nextPos;
}
 
