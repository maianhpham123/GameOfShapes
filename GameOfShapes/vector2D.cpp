//
//  math.cpp
//  GameOfShapes
//
//  Created by mac on 4/2/24.
//

#include "defs.h"
#include "vector2D.hpp"

Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float X, float Y) : x(X), y(Y) {}

void Vector2D::print() {
    cout << x << ", " << y << endl;
}

Vector2D& Vector2D::add(const Vector2D& vec) {
    this->x += vec.x;
    this->y += vec.y;
    cout << this->x << ", " << this->y << endl;
    return *this;
}

Vector2D& Vector2D::substract(const Vector2D& vec) {
    this->x -= vec.x;
    this->y -= vec.y;
    cout << this->x << ", " << this->y << endl;
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec) {
    this->x *= vec.x;
    this->y *= vec.y;
    cout << this->x << ", " << this->y << endl;
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec) {
    this->x /= vec.x;
    this->y /= vec.y;
    cout << this->x << ", " << this->y << endl;
    return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2) {
    Vector2D& v = v1.add(v2);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2) {
    Vector2D& v = v1.substract(v2);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2) {
    Vector2D& v = v1.multiply(v2);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2) {
    Vector2D& v = v1.divide(v2);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
    Vector2D& v = this->add(vec);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec) {
    Vector2D& v = this->substract(vec);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& Vector2D::operator*=(const Vector2D& vec) {
    Vector2D& v = this->multiply(vec);
    cout << v.x << ", " << v.y << endl;
    return v;
}

Vector2D& Vector2D::operator/=(const Vector2D& vec) {
    Vector2D& v = this->divide(vec);
    cout << v.x << ", " << v.y << endl;
    return v;
}
