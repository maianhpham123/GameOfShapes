//
//  math.hpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#ifndef math_hpp
#define math_hpp

#include "defs.h"

class Vector2D
{
public:
    float x, y;
    Vector2D();
    Vector2D(float X, float Y);
    
    void print();
    
    Vector2D& add(const Vector2D& vec);
    Vector2D& substract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);
    
    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
};

#endif /* math_hpp */
