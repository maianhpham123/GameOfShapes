//
//  checkCollision.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef checkCollision_hpp
#define checkCollision_hpp

#include <vector>
#include "vector2D.hpp"
#include "maths.hpp"


void ProjectVertices(const vector<Vector2D>& vertices, const Vector2D& axis, float& min, float& max) {
    for (int i = 0; i < (int) vertices.size(); i++) {

        Vector2D v = vertices[i];
        float proj = dotProduct(v, axis);
        
        if (proj < min) min = proj;
        if (proj > max) max = proj;
    }
}


bool Intersect (const vector<Vector2D>& verticesA, const vector<Vector2D>& verticesB)
{
    
    // for object1
    //TODO: make 1 correct
    for (int i = 0; i < (int) verticesA.size(); i++) {
        Vector2D va = verticesA[i];
        Vector2D vb = verticesA[(i+1) % (int) verticesA.size()];
        
        Vector2D edge = vb - va;
        Vector2D axis = Vector2D(-edge.y, edge.x);
        
        float minA = std::numeric_limits<float>::max();
        float maxA = std::numeric_limits<float>::min();
        float minB = std::numeric_limits<float>::max();
        float maxB = std::numeric_limits<float>::min();
        
        ProjectVertices(verticesA, axis, minA, maxA);
        ProjectVertices(verticesB, axis, minB, maxB);
        
        if (minA >= maxB || minB >= maxA) return false;
        else {
            cout << "minA1: " << minA << " " << "maxA1: " << maxA << endl;
            cout << "minB1: " << minB << " " << "maxB1: " << maxB << endl;
        }
    }
    
    //for object2
    for (int i = 0; i < (int) verticesB.size(); i++) {
        Vector2D va = verticesB[i];
        Vector2D vb = verticesB[(i+1) % (int) verticesB.size()];
        
        Vector2D edge = vb - va;
        Vector2D axis = Vector2D(-edge.y, edge.x);
        
        float minA = std::numeric_limits<float>::max();
        float maxA = std::numeric_limits<float>::min();
        float minB = std::numeric_limits<float>::max();
        float maxB = std::numeric_limits<float>::min();
        
        ProjectVertices(verticesA, axis, minA, maxA);
        ProjectVertices(verticesB, axis, minB, maxB);
        
        if (minA >= maxB || minB >= maxA) return false;
        else {
            cout << "minA2: " << minA << " " << "maxA2: " << maxA << endl;
            cout << "minB2: " << minB << " " << "maxB2: " << maxB << endl;
        }
    }
    
    return true;
}

#endif /* checkCollision_hpp */
