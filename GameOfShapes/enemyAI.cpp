//
//  enemyAI.cpp
//  GameOfShapes
//
//  Created by Mai Anh Pham on 4/23/24.
//

#include "enemyAI.hpp"

AIEnemy::AIEnemy(RenderWindow& window, const char* textureFile)
: Entity(Vector2D(1280.0f, 0.0f),window.loadTexture(textureFile)) {}

//TODO: convert this pseudocode to real code using A star pathfinding
//source: wikipedia

function reconstruct_path(cameFrom, current)
    total_path := {current}
    while current in cameFrom.Keys:
        current := cameFrom[current]
        total_path.prepend(current)
    return total_path

// A* finds a path from start to goal.
// h is the heuristic function. h(n) estimates the cost to reach goal from node n.
function A_Star(start, goal, h)
    // The set of discovered nodes that may need to be (re-)expanded.
    // Initially, only the start node is known.
    // This is usually implemented as a min-heap or priority queue rather than a hash-set.
    openSet := {start}

    // For node n, cameFrom[n] is the node immediately preceding it on the cheapest path from the start
    // to n currently known.
    cameFrom := an empty map

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
    gScore := map with default value of Infinity
    gScore[start] := 0

    // For node n, fScore[n] := gScore[n] + h(n). fScore[n] represents our current best guess as to
    // how cheap a path could be from start to finish if it goes through n.
    fScore := map with default value of Infinity
    fScore[start] := h(start)

    while openSet is not empty
        // This operation can occur in O(Log(N)) time if openSet is a min-heap or a priority queue
        current := the node in openSet having the lowest fScore[] value
        if current = goal
            return reconstruct_path(cameFrom, current)

        openSet.Remove(current)
        for each neighbor of current
            // d(current,neighbor) is the weight of the edge from current to neighbor
            // tentative_gScore is the distance from start to the neighbor through current
            tentative_gScore := gScore[current] + d(current, neighbor)
            if tentative_gScore < gScore[neighbor]
                // This path to neighbor is better than any previous one. Record it!
                cameFrom[neighbor] := current
                gScore[neighbor] := tentative_gScore
                fScore[neighbor] := tentative_gScore + h(neighbor)
                if neighbor not in openSet
                    openSet.add(neighbor)

    // Open set is empty but goal was never reached
    return failure




void AIEnemy::update() {}
void AIEnemy::render() {}

SDL_Rect AIEnemy::setDstRect(int x, int y, int width, int height) const {
    SDL_Rect dstRect;
    dstRect.x = transform.position.x - 20;
    dstRect.y = transform.position.y - 20;
    dstRect.w = 40;
    dstRect.h = 40;
    return dstRect;
}

SDL_Rect AIEnemy::setCollisionBox(int x, int y, int width, int height) const {
    SDL_Rect collisionBox;
    collisionBox.x = transform.position.x - 20;
    collisionBox.y = transform.position.y - 20;
    collisionBox.w = 40;
    collisionBox.h = 40;
    return collisionBox;
}
